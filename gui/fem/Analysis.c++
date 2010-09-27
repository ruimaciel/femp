#include "Analysis.h++"

#include <Eigen/Sparse>
#include <Eigen/LU>


namespace fem
{

Analysis::Analysis()
{
	// build all lists of integration points/weights pairs
	build_integration_points();
	setDefaultIntegrationDegrees();
}


Analysis::Analysis(const Analysis &copied)
{
	// copy the FEM equation
	this->k = copied.k;
	this->f = copied.f;
	this->d = copied.d;
}


Analysis::~Analysis()
{
}


enum Analysis::Error Analysis::build_fem_equation(Model &model, const LoadPattern &lp, bool verbose)
{
	using namespace std;
	using namespace Eigen;

	// perform sanity checks on the model
	if(model.element_list.empty() )
		return ERR_NO_ELEMENTS;

		// generate the location matrix
	make_location_matrix(model);

		// initialize the FEM equation objects
	k.setZero();
	f.setZero();
	d.setZero();
				
		// declare variables
	size_t pi = 0;	// progress indicator
	double detJ = 0;

	Matrix3d J, invJ;
	std::vector< Eigen::Matrix<double,6,6> > D_list;

		// set up the temporary variables for the elementary matrix and vector
	//symmetric_matrix<double, upper> k_elem;
	Matrix<double,Dynamic, Dynamic> k_elem;
	Matrix<double,Dynamic,1> f_elem;
	Matrix<double,Dynamic,Dynamic> B;
	Matrix<double,Dynamic,Dynamic> Bt;

		//TODO get a separate function to return the shape function
	std::vector<double>	sf;	// shape function
	std::vector<double>	dNdcsi;
	std::vector<double>	dNdeta;
	std::vector<double>	dNdzeta;

	int nnodes;	// number of nodes
	std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator dof;	// for the force vector scatter operation


		//build a list of constitutive matrices
	for(std::vector<Material>::iterator material = model.material_list.begin(); material != model.material_list.end(); material++)
	{
		D_list.push_back(material->generateD());
	}

		// generate stiffness matrix by cycling through all elements in the model
		//TODO fix progress indicator
#define UPDATE_PROGRESS(component) if(verbose) \
		{ \
			if(pi % (component.size()/10+1) == 0) \
			{ \
				cout << "," << pi / (component.size()/10+1)+1; \
				cout.flush(); \
			} \
			pi++; \
		} 

	if(verbose)
	{
		pi = 0;
		cout << "\t\"stiffness matrix progress\": [0";	
		cout.flush();
	}
	for(std::vector<Element>::iterator element = model.element_list.begin(); element != model.element_list.end(); element++)
	{
			// output
		UPDATE_PROGRESS(model.element_list);

			// get the number of expected nodes used by the current element type
		nnodes = element->node_number();

			// resize the elementary matrices to fit the new node size
		k_elem.resize(nnodes*3,nnodes*3);
		f_elem.resize(nnodes*3);
		B.resize(6,3*nnodes);
		Bt.resize(3*nnodes,6);

			// initialize variables
		k_elem.setZero();
		f_elem.setZero();
		B.setZero();

		std::cout << "Beginning element stiffness" << std::endl;

			// build the element stiffness matrix: cycle through the number of integration points
		for (std::vector<boost::tuple<fem::point,double> >::iterator i = ipwpl[element->family()][degree[element->type]].begin(); i != ipwpl[element->family()][degree[element->type]].end(); i++)
		{
#define X(N) model.node_list[element->nodes[N]].x()
#define Y(N) model.node_list[element->nodes[N]].y()
#define Z(N) model.node_list[element->nodes[N]].z()

				// get the shape function and it's partial derivatives for this integration point
			dNdcsi = getdNdcsi(element->type, i->get<0>() );
			dNdeta = getdNdeta(element->type, i->get<0>() );
			dNdzeta = getdNdzeta(element->type, i->get<0>() );

				// generate the jacobian
			J.setZero();
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += dNdcsi[n]*X(n);	J(0,1) += dNdcsi[n]*Y(n);	J(0,2) += dNdcsi[n]*Z(n);
				J(1,0) += dNdeta[n]*X(n);	J(1,1) += dNdeta[n]*Y(n);	J(1,2) += dNdeta[n]*Z(n);
				J(2,0) += dNdzeta[n]*X(n);	J(2,1) += dNdzeta[n]*Y(n);	J(2,2) += dNdzeta[n]*Z(n);
			}

			std::cout << "J:\n" << J << "\n" << endl;

			detJ = J.determinant();

				// return error if we stumble on a negative determinant
			if(detJ <= 0)
			{
				cout << "],\n";	// close the stiffness array in order to open an error message and still preserve a valid JSON document
				cout << "\t\"error\": \"stumbled on a negative determinant on element " << distance(model.element_list.begin(), element) << "\"\n";
				cout << "}\n";
				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			J.computeInverse(&invJ);

				// Set up the B matrix
			for(int n = 0; n < nnodes; n++)
			{
				// set the variables
				// set the partial derivatives
#undef X
#undef Y
#undef Z
#define dNdx invJ(0,0)*dNdcsi[n] + invJ(0,1)*dNdeta[n] + invJ(0,2)*dNdzeta[n]
#define dNdy invJ(1,0)*dNdcsi[n] + invJ(1,1)*dNdeta[n] + invJ(1,2)*dNdzeta[n]
#define dNdz invJ(2,0)*dNdcsi[n] + invJ(2,1)*dNdeta[n] + invJ(2,2)*dNdzeta[n]

				// set the current node portion of the B matrix
				B(0,3*n)	= dNdx;
				B(1,3*n+1)	= dNdy;
				B(2,3*n+2)	= dNdz;
				B(3,3*n)	= dNdy;	B(3,3*n+1) = dNdx;
				B(4,3*n)	= dNdz;	B(4,3*n+2) = dNdx;
				B(5,3*n+1)	= dNdz;	B(5,3*n+2) = dNdy;

				//TODO consider also setting Bt, avoid trans(b)
#undef dNdx
#undef dNdy
#undef dNdz
			}

			// having done the legwork, let's build up the elementary stiffness matrix and equivalent nodal force vector

			Bt = B.transpose();
	
			Eigen::Matrix<double,6,6> D = D_list[element->material];

			// add this integration point's contribution
			k_elem += Bt*D*B*detJ*i->get<1>();
		}
		cout << "k elem: " << k_elem << endl;

			// add elementary stiffness matrix to the global stiffness matrix 
		add_elementary_stiffness_to_global(k_elem, lm, *element);
	}
	if(verbose)
		cout << "]," << endl;


		// now set up the equivalent forces vector
	// set nodal force contribution made by the domain loads
	if(verbose)
	{
		pi = 0;
		cout << "\t\"domain loads progress\": [0";	
		cout.flush();
	}
	for(std::map<size_t,fem::DomainLoad>::const_iterator domain_load = lp.domain_loads.begin(); domain_load != lp.domain_loads.end(); domain_load++)
	{
		// output progress message
		UPDATE_PROGRESS(lp.domain_loads);

		fem::Element *element;
		element = &model.element_list[domain_load->first];
		nnodes = element->node_number();

		f_elem.resize(nnodes*3);
		f_elem.setZero();

		// as the distribution is linear across the domain then degree 1 is enough
		for (std::vector<boost::tuple<fem::point,double> >::iterator i = ipwpl[element->family()][ddegree[element->type]].begin(); i != ipwpl[element->family()][ddegree[element->type]].end(); i++)
		{
				// build the Jacobian
			//TODO rewrite this
			sf = getN(element->type, i->get<0>());
			dNdcsi = getdNdcsi(element->type, i->get<0>() );
			dNdeta = getdNdeta(element->type, i->get<0>() );
			dNdzeta = getdNdzeta(element->type, i->get<0>() );

				// generate the jacobian
			J.setZero();
#define X(N)	model.node_list[element->nodes[N]].x()
#define Y(N)	model.node_list[element->nodes[N]].y()
#define Z(N)	model.node_list[element->nodes[N]].z()
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += dNdcsi[n]*X(n);	J(0,1) += dNdcsi[n]*Y(n);	J(0,2) += dNdcsi[n]*Z(n);
				J(1,0) += dNdeta[n]*X(n);	J(1,1) += dNdeta[n]*Y(n);	J(1,2) += dNdeta[n]*Z(n);
				J(2,0) += dNdzeta[n]*X(n);	J(2,1) += dNdzeta[n]*Y(n);	J(2,2) += dNdzeta[n]*Z(n);
			}

			detJ = J.determinant();
			if(detJ <= 0)
			{
				cout << "],\n";	// close the stiffness array in order to open an error message and still preserve a valid JSON document
				cout << "\t\"error\": \"stumbled on a negative determinant on element " << domain_load->first << "\"\n";
				cout << "}\n";
				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			// and now the f_elem
			for(int n = 0; n < nnodes; n++)
			{
#define N(n) sf[n]
#define b(COORD) domain_load->second.force.COORD()
#define W    i->get<1>()
				f_elem(3*n) += N(n)*b(x)*detJ*W;
				f_elem(3*n+1) += N(n)*b(y)*detJ*W;
				f_elem(3*n+2) += N(n)*b(z)*detJ*W;
#undef N
#undef b
#undef W
			}
		}
#undef X
#undef Y
#undef Z

			//add the domain load's f_elem contribution to f
		for(size_t i = 0; i < model.element_list[domain_load->first].nodes.size(); i++)
		{
			dof = lm.find(model.element_list[domain_load->first].nodes[i]);
			if(dof == lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					f(n-1) += f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					f(n-1) += f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					f(n-1) += f_elem(3*i+2);
			}
		}
	}
	if(verbose)
		cout << "]," << endl;

		// integrate the surface loads
	//TODO finish this
	if(verbose)
	{
		pi = 0;
		cout << "\t\"surface loads progress\": [0";
		cout.flush();
	}
	cout << "\nSurface loads: " << lp.surface_loads.size() << endl;
	for(std::vector<fem::SurfaceLoad>::const_iterator surface_load = lp.surface_loads.begin(); surface_load != lp.surface_loads.end(); surface_load++)
	{
			// output progress message
		UPDATE_PROGRESS(lp.surface_loads);

		//TODO
		nnodes = surface_load->node_number();

		f_elem.resize(nnodes*3);
		f_elem.setZero();
		cout << "\nf_elem original:\n" << f_elem << endl;

		for (std::vector<boost::tuple<fem::point,double> >::iterator i = ipwpl[surface_load->family()][degree[surface_load->type]].begin(); i != ipwpl[surface_load->family()][degree[surface_load->type]].end(); i++)
		{
				// get shape function and shape function derivatives in this integration point's coordinate
			sf = getN(surface_load->type, i->get<0>() );
			dNdcsi = getdNdcsi(surface_load->type, i->get<0>() );
			dNdeta = getdNdeta(surface_load->type, i->get<0>() );

				// calculate the Jacobian
			J.setZero();
#define X(N)	model.node_list[surface_load->nodes[N]].x()
#define Y(N)	model.node_list[surface_load->nodes[N]].y()
#define Z(N)	model.node_list[surface_load->nodes[N]].z()
			J(0,0) = 1;	J(1,0) = 1;	J(2,0) = 1;
			for(int n = 0; n < nnodes; n++)
			{
				J(0,1) += dNdcsi[n]*X(n);	J(1,1) += dNdcsi[n]*Y(n);	J(2,1) += dNdcsi[n]*Z(n);
				J(0,2) += dNdeta[n]*X(n);	J(1,2) += dNdeta[n]*Y(n);	J(2,2) += dNdeta[n]*Z(n);
			}
			cout << "\nJ matrix:\n" << J << endl;

			detJ = J.determinant();
			if(detJ <= 0)
			{
				cout << "],\n";	// close the stiffness array in order to open an error message and still preserve a valid JSON document
				cout << "\t\"error\": \"stumbled on a negative determinant on surface " << "\"\n";
				cout << "}\n";
				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}


#define N(n) sf[n]
#define b(COORD) domain_load->second.force.COORD()
#define W    i->get<1>()
				// calculate q(csi, eta, zeta)
			fem::point q;
			for(int j = 0; j < nnodes; j++)
			{
				q += N(j)*surface_load->surface_forces[j];
			}
			cout << "\nq: " << q << endl;

			for(int n = 0; n < nnodes; n++)
			{

				f_elem(3*n  ) += N(n)*q.x()*detJ*W;
				f_elem(3*n+1) += N(n)*q.y()*detJ*W;
				f_elem(3*n+2) += N(n)*q.z()*detJ*W;
			}
		}
		cout << "\nf_elem:\n" << f_elem << endl;

			//add the surface load's f_elem contribution to f
		//for(size_t i = 0; i < model.element_list[domain_load->first].nodes.size(); i++)
		for(int i = 0; i < nnodes; i++)
		{
			dof = lm.find(surface_load->nodes[i]);
			if(dof == lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					f(n-1) += f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					f(n-1) += f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					f(n-1) += f_elem(3*i+2);
			}
		}
	}
	if(verbose)
		cout << "]," << endl;

	// set nodal forces
	if(verbose)
	{
		pi = 0;
		cout << "\t\"nodal loads progress\": [0";
		cout.flush();
	}
	for(std::map<size_t,fem::NodalLoad>::const_iterator nodal_load = lp.nodal_loads.begin(); nodal_load != lp.nodal_loads.end(); nodal_load++)
	{
			// output progress message
		UPDATE_PROGRESS(lp.nodal_loads);

		size_t n;
		n = nodal_load->first;

		// set the nodal loads
		if(lm[n].get<0>() != 0)
			f[lm[n].get<0>()-1] += nodal_load->second.x();
		if(lm[n].get<1>() != 0)
			f[lm[n].get<1>()-1] += nodal_load->second.y();
		if(lm[n].get<2>() != 0)
			f[lm[n].get<2>()-1] += nodal_load->second.z();
	}
	if(verbose)
		cout << "]," << endl;

	//DEBUG
	//cout << "K[" << k.rows() << ", " << k.cols() << "]" << endl;
	
	// fem equation is set.
	return ERR_OK;
}


void Analysis::output_fem_equation(std::ostream &out)
{
	out << "\t\"fem equation\" : {\n";

	// output stiffness matrix
	out << "\t\t\"stiffness matrix\" : [\n";
	for(int i = 0; i < k.rows(); i++)
	{
		out << "\t\t\t[";
		for(int j = 0; j < k.cols(); j++)
		{
			if(j != 0)
				out << ",";
			out << "\t" << k.coeff(i,j);
		}
		out << "]";
		if(i + 1 < k.rows())
			out << ",";
		out << "\n";
	}
	out << "\t\t],\n";

	// output force vector
	out << "\t\t\"force vector\" : [\n";
	for(int i = 0; i < f.rows(); i++)
	{
		out << "\t\t\t";
		out << f.coeff(i);
		if(i +1 < f.rows() )
			out << ",";
		out << "\n";
	}
	out << "\t\t]\n";

	out << "\t},\n";
}


void Analysis::output_displacements(std::ostream &out)
{
	using namespace std;

	// output displacements field
	out << "\t\"displacement\": [";
	size_t n = 0;
	bool first = true;
	for(map<size_t, boost::tuple<size_t,size_t,size_t> >::const_iterator i = lm.begin(); i != lm.end(); i++)
	{
		if( (i->second.get<0>() == 0)&& (i->second.get<1>() == 0) &&  (i->second.get<1>() == 0) )
			continue;

		if(!first)
			out << ",";
		else
			first = false;

		out << "\n\t\t{ \"node\": " << i->first;
		if(i->second.get<0>() != 0)
			out << ", \"dx\": " << d(n++);
		if(i->second.get<1>() != 0)
			out << ", \"dy\": " << d(n++);
		if(i->second.get<2>() != 0)
			out << ", \"dz\": " << d(n++);
		out << "}";
	}

	out << "\n\t]\n";
}


std::map<size_t, Node> Analysis::displacements_map()
{
	using namespace std;

	map<size_t, Node> df;	// displacements field
	size_t n = 0;
	Node node;

	for(map<size_t, boost::tuple<size_t,size_t,size_t> >::const_iterator i = lm.begin(); i != lm.end(); i++)
	{
		node.zero();

		// don't add a map if no DoF exists
		if(  (i->second.get<0>() == 0) && (i->second.get<1>() == 0) && (i->second.get<2>() == 0))
			continue;

		// assign the displacements
		if(i->second.get<0>() != 0)
			node.data[0] = d(n++);
		if(i->second.get<1>() != 0)
			node.data[1] = d(n++);
		if(i->second.get<2>() != 0)
			node.data[2] = d(n++);

		// add the displacement field to the map
		df[i->first] = node;
	}

	return df;
}


/*******************************************************************************
Gauss-Legendre integration function, gauleg, from "Numerical Recipes in C"
(Cambridge Univ. Press) by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and
B.P. Flannery
*******************************************************************************/
/*******************************************************************************
Given n, this
routine returns arrays x[1..n] and w[1..n] of length n, containing the abscissas
and weights of the Gauss-Legendre n-point quadrature formula.
*******************************************************************************/
void Analysis::gauleg(double x[], double w[], int n)
{
	int m,j,i;
	double z1,z,pp,p3,p2,p1;
	m=(n+1)/2; /* The roots are symmetric, so we only find half of them. */

	for (i=1;i<=m;i++) 
	{ /* Loop over the desired roots. */
		z=cos(3.141592654*(i-0.25)/(n+0.5));
		/* Starting with the above approximation to the ith root, we enter */
		/* the main loop of refinement by Newton's method.                 */
		do {
			p1=1.0;
			p2=0.0;
			for (j=1;j<=n;j++) { /* Recurrence to get Legendre polynomial. */
				p3=p2;
				p2=p1;
				p1=((2.0*j-1.0)*z*p2-(j-1.0)*p3)/j;
			}
			/* p1 is now the desired Legendre polynomial. We next compute */
			/* pp, its derivative, by a standard relation involving also  */
			/* p2, the polynomial of one lower order.                     */
			pp=n*(z*p1-p2)/(z*z-1.0);
			z1=z;
			z=z1-p1/pp; /* Newton's method. */
		} while (fabs(z-z1) > 3e-11);	// ARBITRATED
		x[i-1]=-z;      /* Scale the root to the desired interval, */
		x[n-i]=z;  /* and put in its symmetric counterpart.   */
		w[i-1]=2.0/((1.0-z*z)*pp*pp); /* Compute the weight             */
		w[n-i]=w[i-1];                 /* and its symmetric counterpart. */
	}
}


void Analysis::setDegree(Element::Type &type, int &d)
{
	degree[type] = d;
}


void Analysis::setDDegree(Element::Type &type, int &d)
{
	ddegree[type] = d;
}


void Analysis::setDefaultIntegrationDegrees()
{
	//TODO tweak integration points	
	// the degree for the stiffness matrix	// and the degree for the domain loads
	degree[Element::FE_TRIANGLE3 ] = 1;	ddegree[Element::FE_TRIANGLE3 ] = 1;
	degree[Element::FE_TRIANGLE6 ] = 1;	ddegree[Element::FE_TRIANGLE6 ] = 1;
	degree[Element::FE_TRIANGLE10] = 1;	ddegree[Element::FE_TRIANGLE10] = 1;
	degree[Element::FE_TRIANGLE15] = 1;	ddegree[Element::FE_TRIANGLE15] = 1;

	degree[Element::FE_QUADRANGLE4] = 1;	ddegree[Element::FE_QUADRANGLE4] = 1;
	degree[Element::FE_QUADRANGLE8] = 1;	ddegree[Element::FE_QUADRANGLE8] = 1;
	degree[Element::FE_QUADRANGLE9] = 1;	ddegree[Element::FE_QUADRANGLE9] = 1;

	degree[Element::FE_TETRAHEDRON4 ] = 4;	ddegree[Element::FE_TETRAHEDRON4 ] = 1;
	degree[Element::FE_TETRAHEDRON10] = 4;	ddegree[Element::FE_TETRAHEDRON10] = 1;
	degree[Element::FE_TETRAHEDRON20] = 4;	ddegree[Element::FE_TETRAHEDRON20] = 1;
	degree[Element::FE_TETRAHEDRON35] = 4;	ddegree[Element::FE_TETRAHEDRON35] = 1;
	degree[Element::FE_TETRAHEDRON56] = 4;	ddegree[Element::FE_TETRAHEDRON56] = 1;

	degree[Element::FE_HEXAHEDRON8 ] = 4;	ddegree[Element::FE_HEXAHEDRON8 ] = 1;
	degree[Element::FE_HEXAHEDRON20] = 4;	ddegree[Element::FE_HEXAHEDRON20] = 1;
	degree[Element::FE_HEXAHEDRON27] = 4;	ddegree[Element::FE_HEXAHEDRON27] = 1;

	degree[Element::FE_PRISM6 ] = 4;	ddegree[Element::FE_PRISM6 ] = 1;
	degree[Element::FE_PRISM15] = 4;	ddegree[Element::FE_PRISM15] = 1;
	degree[Element::FE_PRISM18] = 4;	ddegree[Element::FE_PRISM18] = 1;

	degree[Element::FE_PYRAMID5 ] = 4;	ddegree[Element::FE_PYRAMID5 ] = 1;
	degree[Element::FE_PYRAMID14] = 4;	ddegree[Element::FE_PYRAMID14] = 1;
	degree[Element::FE_PYRAMID13] = 4;	ddegree[Element::FE_PYRAMID13] = 1;

	degree[Element::FE_ITRIANGLE9 ] = 1;	ddegree[Element::FE_ITRIANGLE9 ] = 1;
	degree[Element::FE_ITRIANGLE12] = 1;	ddegree[Element::FE_ITRIANGLE12] = 1;
	degree[Element::FE_ITRIANGLE15] = 1;	ddegree[Element::FE_ITRIANGLE15] = 1;
	degree[Element::FE_TRIANGLE21 ] = 1;	ddegree[Element::FE_TRIANGLE21 ] = 1;
}


void Analysis::build_integration_points()
{
	using namespace boost;
	std::vector<tuple<fem::point, double> > ips;

	// triangle family, level 1
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3,1.0/3,1.0/3), 1.0));
		ipwpl[Element::EF_TRIANGLE][1] = ips;
	}

	// triangle family, level 2: 3 points, degree 2
	{
		//TODO needs testing
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(	2.0/3,	1.0/6,	1.0/6), 1.0/3));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	2.0/3,	1.0/6), 1.0/3));
		ips.push_back(tuple<fem::point,double>(fem::point(	1.0/6,	1.0/6,	2.0/3), 1.0/3));
		ipwpl[Element::EF_TRIANGLE][2] = ips;
	}

	// triangle family, level 3: 6 points, degree 4
	{
		//TODO needs testing
		ips.clear();
		double g1=(8-sqrt(10.0)+sqrt(38.0-44.0*sqrt(2.0/5)))/18;
		double g2=(8-sqrt(10.0)-sqrt(38.0-44.0*sqrt(2.0/5)))/18;

		ips.push_back(tuple<fem::point,double>(fem::point(1-2*g1, g1, g1), (620+sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g1, 1-2*g1, g1), (620+sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g1, g1, 1-2*g1), (620+sqrt(213125-53320*sqrt(10)))/3720) );

		ips.push_back(tuple<fem::point,double>(fem::point(1-2*g2, g2, g2), (620-sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g2, 1-2*g2, g2), (620-sqrt(213125-53320*sqrt(10)))/3720) );
		ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 1-2*g2), (620-sqrt(213125-53320*sqrt(10)))/3720) );

		ipwpl[Element::EF_TRIANGLE][3] = ips;
	}

	// triangle family, level 4: 7  points, degree 5
	{
		//TODO needs testing
		ips.clear();
	
		double g1=(6.0-sqrt(15))/21; 
		double g2=(6.0+sqrt(15))/21;

		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g1, g1, g1), (155.0-sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, 1.0-2*g1, g1), (155.0-sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g1, g1, 1.0-2*g1), (155.0-sqrt(15))/1200));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0-2*g2, g2, g2), (155.0+sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, 1.0-2*g2, g2), (155.0+sqrt(15))/1200));
		ips.push_back(tuple<fem::point,double>(fem::point(g2, g2, 1.0-2*g2), (155.0+sqrt(15))/1200));

		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3), 9.0/40));

		ipwpl[Element::EF_TRIANGLE][4] = ips;
	}


	// Quadrilateral family
	{
		for(int d = 1; d < 6; d++)
		{
			ips.clear();
			double x[d], w[d];	// for the Gauss-Legendre integration points and weights
			// get the Gauss-Legendre integration points and weights
			gauleg(x,w,d);

			// and now generate a list with those points
			for(int i = 0; i < d; i++)
			{
				for(int j = 0; j < d; j++)
				{
					ips.push_back(tuple<fem::point,double>(fem::point(x[i],x[j],0), w[i]*w[j]));
				}
			}
			ipwpl[Element::EF_QUADRILATERAL][d] = ips;
		}
	}


	// Tetrahedron family, degree 1
	{
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(0.25,0.25,0.25), 1.0/6.0));
		ipwpl[Element::EF_TETRAHEDRON][1] = ips;
	}

	// Tetrahedron family, degree 2
	{
		ips.clear();

		ips.push_back(tuple<fem::point,double>(fem::point(0.58541019662496845446,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.58541019662496845446,0.13819660112501051518),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.58541019662496845446),1.0/(6*4)));
		ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));

		ipwpl[Element::EF_TETRAHEDRON][2] = ips;
	}

	// Tetrahedron family, degree 3
	{
		ips.clear();
		/*
		ips.push_back(tuple<fem::point,double>(fem::point(0, 0, 0), 1.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
		*/

		/*
		   If [j<=0,info={{g1,g1,g1,g1},w1}; info[[1,i]]=1-3*g1];
		   If [j> 0,info={{g2,g2,g2,g2},w2}; info[[1,j]]=1-3*g2]];
		 */

		double g[2];
		double w[2];

		g[0]=(55-3*sqrt(17)+sqrt(1022-134*sqrt(17)))/196;
		g[1]=(55-3*sqrt(17)-sqrt(1022-134*sqrt(17)))/196;

		w[0]= (1.0/8 + sqrt((1715161837-406006699*sqrt(17))/23101)/3120)/6.0;
		w[1]= (1.0/8 - sqrt((1715161837-406006699*sqrt(17))/23101)/3120) /6.0;

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0] ));

		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1]), w[1] ));

		ipwpl[Element::EF_TETRAHEDRON][3] = ips;
	}

	// Tetrahedron family, degree 4
	{
		ips.clear();
		double g[3];
		double w[2];
		g[0]=0.09273525031089122640232391373703060;
		g[1]=0.31088591926330060979734573376345783;
		g[2]=0.45449629587435035050811947372066056;

		w[0] = (-1+6*g[1]*(2+g[1]*(-7+8*g[1]))+14*g[2]-60*g[1]*(3+4*g[1]* (-3+4*g[1]))*g[2]+4*(-7+30*g[1]*(3+4*g[1]*(-3+4*g[1])))*g[2]*g[2])/ (120*(g[0]-g[1])*(g[1]*(-3+8*g[1])+6*g[2]+8*g[1]*(-3+4*g[1])*g[2]-4* (3+4*g[1]*(-3+4*g[1]))*g[2]*g[2]+8*g[0]*g[0]*(1+12*g[1]* (-1+2*g[1])+4*g[2]-8*g[2]*g[2])+g[0]*(-3-96*g[1]*g[1]+24*g[2]*(-1+2*g[2])+ g[1]*(44+32*(1-2*g[2])*g[2]))));
		w[1] = (-1-20*(1+12*g[0]*(2*g[0]-1))*w[0]+20*g[2]*(2*g[2]-1)*(4*w[0]-1))/ (20*(1+12*g[1]*(2*g[1]-1)+4*g[2]-8*g[2]*g[2]));

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0] ));
		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1]), w[1] ));
		// 9 to 14
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], 1.0/2-g[2], g[3]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], g[3], 1.0/2-g[2]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/2-g[2], g[3], g[3]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[3], 1.0/2-g[2], 1.0/2-g[2]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[3], 1.0/2-g[2], g[3]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[3], g[3], 1.0/2-g[2]), 1.0/6 - 2*(w[0]+w[1])/3  ));
		ipwpl[Element::EF_TETRAHEDRON][4] = ips;
	}

	// Tetrahedron family, degree 5
	{
		ips.clear();
		double g[3];
		double w[2];

		g[0]=(7-sqrt(15))/34; 	g[1]=7/17-g[0]; 	g[2]=(10-2*sqrt(15))/40;
		w[0]=(2665+14*sqrt(15))/37800;	w[1]=(2665-14*sqrt(15))/37800;

		// 1 to 4
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[0], g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], 1-3*g[0], g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], 1-3*g[0]), w[0] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[0], g[0], g[0]), w[0] ));

		// 5 to 8
		ips.push_back(tuple<fem::point,double>(fem::point(1-3*g[1], g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], 1-3*g[1], g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], 1-3*g[1]), w[1] ));
		ips.push_back(tuple<fem::point,double>(fem::point(g[1], g[1], g[1] ), w[1] ));

		// 9 to 14
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], 0.5 - g[2], g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], g[2], 0.5-g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(0.5-g[2], g[2], g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 0.5-g[2], 0.5-g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], 0.5-g[2], g[2] ), 10.0/189));
		ips.push_back(tuple<fem::point,double>(fem::point(g[2], g[2], 0.5-g[2] ), 10.0/189));

		// 15
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/4, 1.0/4, 1.0/4 ), 16.0/135));

		ipwpl[Element::EF_TETRAHEDRON][5] = ips;
	}


	// Hexahedron family, integration points 1 to 7
	for(int d = 1; d < 8; d++)
	{
		ips.clear();
		double x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		gauleg(x,w,d);

		// and now generate a list with those points
		for(int i = 0; i < d; i++)
		{
			for(int j = 0; j < d; j++)
			{
				for(int k = 0; k < d; k++)
				{
					ips.push_back(tuple<fem::point,double>(fem::point(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
				}
			}
		}
		ipwpl[Element::EF_HEXAHEDRON][d] = ips;
	}


	//Prism, level 1
	{
		//TODO test this
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/3,1.0/3,0), 1.0*2/2));
		ipwpl[Element::EF_PRISM][1] = ips;
	}

	//Prism, level 2
	{
		//TODO test this
		ips.clear();
		ips.push_back(tuple<fem::point,double>(fem::point(2.0/3,1.0/6,-1.0/sqrt(3)), (1.0/3)*1/2));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,2.0/3,-1.0/sqrt(3)), (1.0/3)*1/2));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,1.0/6,-1.0/sqrt(3)), (1.0/3)*1/2));
		ips.push_back(tuple<fem::point,double>(fem::point(2.0/3,1.0/6, 1.0/sqrt(3)), (1.0/3)*1/2));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,2.0/3, 1.0/sqrt(3)), (1.0/3)*1/2));
		ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,1.0/6, 1.0/sqrt(3)), (1.0/3)*1/2));
		ipwpl[Element::EF_PRISM][2] = ips;
	}

	//Prism, level 3
	for(int d = 3; d < 5; d++)
	{
		//TODO test this
		ips.clear();
		double x[d], w[d];	// for the Gauss-Legendre integration points and weights
		// get the Gauss-Legendre integration points and weights
		gauleg(x,w,d);

		for(std::vector<tuple<fem::point, double> >::iterator i = ipwpl[Element::EF_TRIANGLE][3].begin(); i != ipwpl[Element::EF_TRIANGLE][3].end(); i++)
		{
			for(int j = 0; j < d; j++)
			{
				ips.push_back(tuple<fem::point,double>(fem::point(i->get<0>().x(),i->get<0>().y(), x[j]), i->get<1>()*w[j]));
			}
		}
		ipwpl[Element::EF_PRISM][d] = ips;
	}

	//TODO finish the rest
}


void
Analysis::make_location_matrix(Model &model)
{
	size_t dof = 1;	// degree of freedom count, the 0 value is interpreted as a prescribed movement

	// iterate through the node list
	for(std::map<size_t, fem::Node>::iterator i = model.node_list.begin(); i != model.node_list.end(); i++)
	{
		if(model.node_restrictions_list.find(i->first) == model.node_restrictions_list.end())
		{
			// there are no node restrictions set for this node
			lm[i->first].get<0>() = dof++;
			lm[i->first].get<1>() = dof++;
			lm[i->first].get<2>() = dof++;
		}
		else
		{
				// there are some node restrictions set for this node
			if(model.node_restrictions_list[i->first].dx() == false)
				lm[i->first].get<0>() = dof++;
			else
				lm[i->first].get<0>() = 0;

			if(model.node_restrictions_list[i->first].dy() == false)
				lm[i->first].get<1>() = dof++;
			else
				lm[i->first].get<1>() = 0;

			if(model.node_restrictions_list[i->first].dz() == false)
				lm[i->first].get<2>() = dof++;
			else
				lm[i->first].get<2>() = 0;
		}
	}

	dof--;	// avoid the off by one error in resizing K_g and f_g

		// resize the FEM equation
	/*
	k.resize(dof,dof, false);
	f.resize(dof, false);
	d.resize(dof, false);
	*/
	k.resize(dof,dof);
	f.resize(dof);
	d.resize(dof);
}


inline void Analysis::add_elementary_stiffness_to_global(const Eigen::Matrix<double,Eigen::Dynamic, Eigen::Dynamic> &k_elem, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element)
{
	using namespace std;	//TODO remove cleanup code

	assert((size_t)k_elem.rows() == element.nodes.size()*3);
	assert((size_t)k_elem.cols() == element.nodes.size()*3);

	std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator idof, jdof;	// degrees of freedom for the line and column 
	size_t id[3], jd[3]; // boost::tuple, being a template, doesn't accept non-const parameters.  This is a way to sidestep it

	boost::tuple<size_t,size_t,size_t> dof;
	for(size_t i = 0; i < element.nodes.size(); i++)
	{
		// if all three DoF of this node are prescribed then they aren't added to K_g
		idof = lm.find(element.nodes[i]);
		if(idof  == lm.end()) // no entry in lm means all 3 DoF are prescribed
			continue;

		// get the global DoF
		id[0] = idof->second.get<0>();
		id[1] = idof->second.get<1>();
		id[2] = idof->second.get<2>();

		// the node has non-prescribed DoF
		for(size_t j = 0; j < element.nodes.size(); j++)
		{
			// if all three DoF of this node are prescribed then they aren't added to K_g
			jdof = lm.find(element.nodes[j]);
			if(jdof == lm.end()) // no entry in lm means all 3 DoF are prescribed
				continue;

			// get the global DoF
			jd[0] = jdof->second.get<0>();
			jd[1] = jdof->second.get<1>();
			jd[2] = jdof->second.get<2>();

				//now let's cycle this node's stiffness sub-matrix
				// get the degrees of freedom for this node
			for(int u = 0; u < 3; u++)
			{
				// add the remaining elements
				for(int v = 0; v < 3; v++)
				{
					if( (id[u] != 0) && (jd[v] != 0) )
					{
						k.coeffRef(id[u]-1,jd[v]-1) += k_elem(3*i+u, 3*j+v);
					}
				}
			}
		}
	}
}


const std::vector<double> & Analysis::getN( const Element::Type &type, const point & p)
{
	switch(type)
	{
		case Element::FE_TRIANGLE3:
			return this->tri3.setN(p);
			break;

		case Element::FE_TRIANGLE6:
			return this->tri6.setN(p);
			break;

		case Element::FE_TRIANGLE10:
			return this->tri10.setN(p);
			break;

		case Element::FE_QUADRANGLE4:
			return this->quad4.setN(p);
			break;

		case Element::FE_QUADRANGLE8:
			return this->quad8.setN(p);
			break;

		case Element::FE_QUADRANGLE9:
			return this->quad9.setN(p);
			break;

		case Element::FE_TETRAHEDRON4:
			return this->tetra4.setN(p);
			break;

		case Element::FE_TETRAHEDRON10:
			return this->tetra10.setN(p);
			break;

		case Element::FE_HEXAHEDRON8:
			return this->hexa8.setN(p);
			break;

		case Element::FE_HEXAHEDRON20:
			return this->hexa20.setN(p);
			break;

		case Element::FE_HEXAHEDRON27:
			return this->hexa27.setN(p);
			break;

		//TODO add remaining elements
	}
}



const std::vector<double> & Analysis::getdNdcsi( const Element::Type &type, const point & p)
{
	switch(type)
	{
		case Element::FE_TRIANGLE3:
			return this->tri3.setdNdcsi(p);
			break;

		case Element::FE_TRIANGLE6:
			return this->tri6.setdNdcsi(p);
			break;

		case Element::FE_TRIANGLE10:
			return this->tri10.setdNdcsi(p);
			break;

		case Element::FE_QUADRANGLE4:
			return this->quad4.setdNdcsi(p);
			break;

		case Element::FE_QUADRANGLE8:
			return this->quad8.setdNdcsi(p);
			break;

		case Element::FE_QUADRANGLE9:
			return this->quad9.setdNdcsi(p);
			break;

		case Element::FE_TETRAHEDRON4:
			return this->tetra4.setdNdcsi(p);
			break;

		case Element::FE_TETRAHEDRON10:
			return this->tetra10.setdNdcsi(p);
			break;

		case Element::FE_HEXAHEDRON8:
			return this->hexa8.setdNdcsi(p);
			break;

		case Element::FE_HEXAHEDRON20:
			return this->hexa20.setdNdcsi(p);
			break;

		case Element::FE_HEXAHEDRON27:
			return this->hexa27.setdNdcsi(p);
			break;

		//TODO add remaining elements
	}
}



const std::vector<double> & Analysis::getdNdeta( const Element::Type &type, const point & p)
{
	switch(type)
	{
		case Element::FE_TRIANGLE3:
			return this->tri3.setdNdeta(p);
			break;

		case Element::FE_TRIANGLE6:
			return this->tri6.setdNdeta(p);
			break;

		case Element::FE_TRIANGLE10:
			return this->tri10.setdNdeta(p);
			break;

		case Element::FE_QUADRANGLE4:
			return this->quad4.setdNdeta(p);
			break;

		case Element::FE_QUADRANGLE8:
			return this->quad8.setdNdeta(p);
			break;

		case Element::FE_QUADRANGLE9:
			return this->quad9.setdNdeta(p);
			break;

		case Element::FE_TETRAHEDRON4:
			return this->tetra4.setdNdeta(p);
			break;

		case Element::FE_TETRAHEDRON10:
			return this->tetra10.setdNdeta(p);
			break;

		case Element::FE_HEXAHEDRON8:
			return this->hexa8.setdNdeta(p);
			break;

		case Element::FE_HEXAHEDRON20:
			return this->hexa20.setdNdeta(p);
			break;

		case Element::FE_HEXAHEDRON27:
			return this->hexa27.setdNdeta(p);
			break;

		//TODO add remaining elements
	}
}


const std::vector<double> & Analysis::getdNdzeta( const Element::Type &type, const point & p)
{
	switch(type)
	{
		case Element::FE_TRIANGLE3:
			return this->tri3.setdNdzeta(p);
			break;

		case Element::FE_TRIANGLE6:
			return this->tri6.setdNdzeta(p);
			break;

		case Element::FE_TRIANGLE10:
			return this->tri10.setdNdzeta(p);
			break;

		case Element::FE_QUADRANGLE4:
			return this->quad4.setdNdzeta(p);
			break;

		case Element::FE_QUADRANGLE8:
			return this->quad8.setdNdzeta(p);
			break;

		case Element::FE_QUADRANGLE9:
			return this->quad9.setdNdzeta(p);
			break;

		case Element::FE_TETRAHEDRON4:
			return this->tetra4.setdNdzeta(p);
			break;

		case Element::FE_TETRAHEDRON10:
			return this->tetra10.setdNdzeta(p);
			break;

		case Element::FE_HEXAHEDRON8:
			return this->hexa8.setdNdzeta(p);
			break;

		case Element::FE_HEXAHEDRON20:
			return this->hexa20.setdNdzeta(p);
			break;

		case Element::FE_HEXAHEDRON27:
			return this->hexa27.setdNdzeta(p);
			break;

		//TODO add remaining elements
	}
}


}

