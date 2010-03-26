#include "Analysis.h++"



namespace fem
{

Analysis::Analysis()
{
	// build all lists of integration points/weights pairs
	integration_points();
	setDefaultIntegrationDegrees();
}


Analysis::Analysis(const Analysis &copied)
{
}


Analysis::~Analysis()
{
}


enum Analysis::Error Analysis::build_fem_equation(Model &model, struct FemEquation &f, const LoadPattern &lp)
{
	using namespace std;
	using namespace boost::numeric::ublas;

	// perform sanity checks on the model
	if(model.element_list.empty() )
		return ERR_NO_ELEMENTS;

		// initialize the FemEquation object
	f.k.clear();
	f.f.clear();
				
		// declare variables
	double detJ = 0;
	matrix<double>	J(3,3), invJ(3,3);
	std::vector< symmetric_matrix<double, upper> > D_list;

		// set up the temporary variables for the elementary matrix and vector
	symmetric_matrix<double, upper> k_elem;
	//TODO replace mapped_vector with vector
	mapped_vector<double> f_elem;
	matrix<double> B;
	matrix<double> Bt;

		//TODO get a separate function to return the shape function
	std::vector<double>	sf;	// shape function
	boost::tuple< std::vector<double>, std::vector<double>,std::vector<double> > sfd;	// tuple: dNdcsi, dNdeta, dNdzeta
	int nnodes;	// number of nodes


		//build a list of constitutive matrices
	for(std::vector<Material>::iterator material = model.material_list.begin(); material != model.material_list.end(); material++)
	{
		D_list.push_back(material->generateD());
	}

		// generate stiffness matrix by cycling through all elements in the model
	for(std::vector<Element>::iterator element = model.element_list.begin(); element != model.element_list.end(); element++)
	{
			// get the number of expected nodes used by the current element type
		nnodes = element->node_number();

			// resize the elementary matrices to fit the new node size
		k_elem.resize(nnodes*3,nnodes*3,false);
		f_elem.resize(nnodes*3,false);
		B.resize(6,3*nnodes,false);
		Bt.resize(3*nnodes,6,false);

			// initialize variables
		k_elem.clear();
		f_elem.clear();
		B.clear();

			// build the element stiffness matrix: cycle through the number of integration points
		for (std::vector<boost::tuple<fem::point,double> >::iterator i = ipwpl[element->family()][degree[element->type]].begin(); i != ipwpl[element->family()][degree[element->type]].end(); i++)
		{
#define X(N) model.node_list[element->nodes[N]].x()
#define Y(N) model.node_list[element->nodes[N]].y()
#define Z(N) model.node_list[element->nodes[N]].z()
#define dNdcsi(N) sfd.get<0>()[n]
#define dNdeta(N) sfd.get<1>()[n]
#define dNdzeta(N) sfd.get<2>()[n]

				// get the shape function and it's partial derivatives for this integration point
			// sf = this->shape_function(element->type, i->get<0>());
			sfd = this->shape_function_derivatives(element->type, i->get<0>() );

				// generate the jacobian
			J.clear();
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += dNdcsi(n)*X(n);	J(0,1) += dNdcsi(n)*Y(n);	J(0,2) += dNdcsi(n)*Z(n);
				J(1,0) += dNdeta(n)*X(n);	J(1,1) += dNdeta(n)*Y(n);	J(1,2) += dNdeta(n)*Z(n);
				J(2,0) += dNdzeta(n)*X(n);	J(2,1) += dNdzeta(n)*Y(n);	J(2,2) += dNdzeta(n)*Z(n);
			}

			detJ = det3by3(J);
			invJ = invert3by3(J,detJ);

				// Set up the B matrix
			for(int n = 0; n < nnodes; n++)
			{
				// set the variables

				// set the partial derivatives
#undef X
#undef Y
#undef Z
#define dNdx invJ(0,0)*dNdcsi(n) + invJ(0,1)*dNdeta(n) + invJ(0,2)*dNdzeta(n)
#define dNdy invJ(1,0)*dNdcsi(n) + invJ(1,1)*dNdeta(n) + invJ(1,2)*dNdzeta(n)
#define dNdz invJ(2,0)*dNdcsi(n) + invJ(2,1)*dNdeta(n) + invJ(2,2)*dNdzeta(n)

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

#undef dNdcsi
#undef dNdeta
#undef dNdzeta
			}

			// having done the legwork, let's build up the elementary stiffness matrix and equivalent nodal force vector

			Bt = trans(B);
			symmetric_matrix<double> D = D_list[element->material];

			matrix<double> temp;
			// and now, k_elem = sum(Bt*D*B*detJ*i->second);
			temp = prod(Bt,D);
			temp = prod(temp,B);
			temp *= detJ*i->get<1>();
			k_elem += temp;	// adding up the full result


			/*
			// check if there is a domain load associated with this element

			// integrate the domain loads, if it is defined
			// get the current element's index
			size_t element_index = distance(model.element_list.begin(), element);
			
			std::map<size_t,DomainLoad>::const_iterator dli;	// domain load iterator

			dli = lp.domain_loads.find(element_index);
			if(dli != lp.domain_loads.end())
			{
				for(int n = 0; n < nnodes; n++)
				{
#define N(n) sf[n]
#define W    i->get<1>()
					//TODO implement domain nodes
					f_elem(3*n) += N(n)*dli->second.force.x()*detJ*W;
					f_elem(3*n+1) += N(n)*dli->second.force.y()*detJ*W;
					f_elem(3*n+2) += N(n)*dli->second.force.z()*detJ*W;
#undef W
#undef N
				}
			}
			*/
		}

			// add elementary stiffness matrix to the global stiffness matrix 
		add_elementary_stiffness_to_global(k_elem, f, lm, *element);
	}


		// now set up the equivalent forces vector
	// set nodal force contribution made by the domain loads
	for(std::map<size_t,fem::DomainLoad>::const_iterator domain_load = lp.domain_loads.begin(); domain_load != lp.domain_loads.end(); domain_load++)
	{
		//TODO finish this
		fem::Element *element;
		element = &model.element_list[domain_load->first];
		nnodes = element->node_number();

		f_elem.resize(nnodes*3, false);

		// as the distribution is linear across the domain then degree 1 is enough
		for (std::vector<boost::tuple<fem::point,double> >::iterator i = ipwpl[element->family()][1].begin(); i != ipwpl[element->family()][1].end(); i++)
		{
				// build the Jacobian
			sf = shape_function(element->type, i->get<0>() );
			sfd = shape_function_derivatives(element->type, i->get<0>() );

				// generate the jacobian
			J.clear();
#define X(N)	model.node_list[element->nodes[N]].x()
#define Y(N)	model.node_list[element->nodes[N]].y()
#define Z(N)	model.node_list[element->nodes[N]].z()
#define dNdcsi(N) sfd.get<0>()[n]
#define dNdeta(N) sfd.get<1>()[n]
#define dNdzeta(N) sfd.get<2>()[n]
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += dNdcsi(n)*X(n);	J(0,1) += dNdcsi(n)*Y(n);	J(0,2) += dNdcsi(n)*Z(n);
				J(1,0) += dNdeta(n)*X(n);	J(1,1) += dNdeta(n)*Y(n);	J(1,2) += dNdeta(n)*Z(n);
				J(2,0) += dNdzeta(n)*X(n);	J(2,1) += dNdzeta(n)*Y(n);	J(2,2) += dNdzeta(n)*Z(n);
			}
#undef dNdcsi
#undef dNdeta
#undef dNdzeta

			detJ = det3by3(J);

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
	}

		// integrate the surface loads
	//TODO finish this


	// set nodal forces
	for(std::map<size_t,fem::NodalLoad>::const_iterator nodal_load = lp.nodal_loads.begin(); nodal_load != lp.nodal_loads.end(); nodal_load++)
	{
		size_t n;
		n = nodal_load->first;

		// set the nodal loads
		if(lm[n].get<0>() != 0)
			f.f[lm[n].get<0>()-1] += nodal_load->second.x();
		if(lm[n].get<1>() != 0)
			f.f[lm[n].get<1>()-1] += nodal_load->second.y();
		if(lm[n].get<2>() != 0)
			f.f[lm[n].get<2>()-1] += nodal_load->second.z();
	}


	// fem equation is set.
	return ERR_OK;
}


boost::numeric::ublas::matrix<double> Analysis::invert3by3(const boost::numeric::ublas::matrix<double> &M, double det)
{
	assert(M.size1() == 3);
	assert(M.size2() == 3);
	assert(det > 0);
	/*
	   (%i1) M: matrix([a,b,c],[d,e,f],[g,h,i]);
	   [ a  b  c ]
	   [         ]
	   (%o1)      [ d  e  f ]
	   [         ]
	   [ g  h  i ]

	   (%i2) N: invert(M), detout;
	   [ e i - f h  c h - b i  b f - c e ]
	   [                                 ]
	   [ f g - d i  a i - c g  c d - a f ]
	   [                                 ]
	   [ d h - e g  b g - a h  a e - b d ]
	   (%o2) ---------------------------------------------
	   a (e i - f h) + b (f g - d i) + c (d h - e g)
	 */

	boost::numeric::ublas::matrix<double> invJ(3,3);
	invJ(0,0) = (M(1,1)*M(2,2) - M(1,2)*M(2,1))/det;
	invJ(0,1) = (M(0,2)*M(2,1) - M(0,1)*M(2,2))/det;
	invJ(0,2) = (M(0,1)*M(1,2) - M(0,2)*M(1,1))/det;
	invJ(1,0) = (M(1,2)*M(2,0) - M(1,0)*M(2,2))/det;
	invJ(1,1) = (M(0,0)*M(2,2) - M(0,2)*M(2,0))/det;
	invJ(1,2) = (M(0,2)*M(1,0) - M(0,0)*M(1,2))/det;
	invJ(2,0) = (M(1,0)*M(2,1) - M(1,1)*M(2,0))/det;
	invJ(2,1) = (M(0,1)*M(2,0) - M(0,0)*M(2,1))/det;
	invJ(2,2) = (M(0,0)*M(1,1) - M(0,1)*M(1,0))/det;

	return invJ;
}


double Analysis::det3by3(const boost::numeric::ublas::matrix<double> &M)
{
	assert(M.size1() == 3);
	assert(M.size2() == 3);
	return	M(0,0)*( M(1,1)*M(2,2) - M(1,2)*M(2,1)) + \
		M(0,1)*( M(1,2)*M(2,0) - M(1,0)*M(2,2)) + \
		M(0,2)*( M(1,0)*M(2,1) - M(1,1)*M(2,0));
}


enum Analysis::Error Analysis::run(Model &model, const LoadPattern &lp)
{
	using namespace std;

		// build the location matrix, for the degrees of freedom
	make_location_matrix(model);
	
		// output location matrix
	cout << "{\n";
	cout << "\t\"degrees of freedom\": [";
	for(map<size_t, boost::tuple<size_t,size_t,size_t> >::const_iterator i = lm.begin(); i != lm.end(); i++)
	{
		if(i != lm.begin())
			cout << ",";
		cout << "\n\t\t{ \"node\": " << i->first;
		if(i->second.get<0>() != 0)
			cout << ", \"dx\": " << i->second.get<0>();
		if(i->second.get<1>() != 0)
			cout << ", \"dy\": " << i->second.get<1>();
		if(i->second.get<2>() != 0)
			cout << ", \"dz\": " << i->second.get<2>();
		cout << "}";
	}
	cout << "\n\t],\n" << endl;

		//this is a nasty hack to test the code. To be removed.
	//TODO return a good return code
	build_fem_equation(model, f, lp);

		// solve the equation system
	f.solve();
	// f.CGsolve(10e-5);

		// output displacements field
	cout << "\t\"displacement\": [\n";
	for(size_t i = 0; i < f.d.size(); i++)
	{
		if(i != 0)
			cout << ",\n";
		cout << "\t\t" << f.d[i];
	}
	cout << "\n\t]\n";
	cout << "}\n";

	return ERR_OK;
}


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


std::vector<double> 
Analysis::shape_function(const Element::Type type, const fem::point &point)
{
	using namespace boost;
	using namespace std;

	vector<double> sf;	// shape function derivatives weights 

	// declare a set of macros to make the code more readable
#define csi point.data[0]
#define eta point.data[1]
#define zeta point.data[2]

	// let's fill in the vectors
	switch(type)
	{
		case Element::FE_TETRAHEDRON4:
			sf.resize(4);
			sf[0] = 1-csi-eta-zeta;
			sf[1] = csi;
			sf[2] = eta;
			sf[3] = zeta;
			break;

		
		case Element::FE_TETRAHEDRON10:
			{
				double L[4];
				L[0] = 1-csi-eta-zeta;
				L[1] = csi;
				L[2] = eta;
				L[3] = zeta;
			
				sf.resize(10);
				sf[0] = (2*L[0]-1)*L[0];
				sf[1] = (2*L[1]-1)*L[1];
				sf[2] = (2*L[2]-1)*L[2];
				sf[3] = (2*L[3]-1)*L[3];
				sf[4] = 4*L[0]*L[1];
				sf[5] = 4*L[1]*L[2];
				sf[6] = 4*L[0]*L[2];
				sf[7] = 4*L[0]*L[3];
				sf[8] = 4*L[2]*L[3];
				sf[9] = 4*L[1]*L[3];
			}
			break;

		case Element::FE_TETRAHEDRON20:
			{
				double L[4];
				L[0] = 1-csi-eta-zeta;
				L[1] = csi;
				L[2] = eta;
				L[3] = zeta;
			
				sf.resize(10);
				sf[0] = (2*L[0]-1)*L[0];
				sf[1] = (2*L[1]-1)*L[1];
				sf[2] = (2*L[2]-1)*L[2];
				sf[3] = (2*L[3]-1)*L[3];
				sf[4] = 4*L[0]*L[1];
				sf[5] = 4*L[1]*L[2];
				sf[6] = 4*L[0]*L[2];
				sf[7] = 4*L[0]*L[3];
				sf[8] = 4*L[2]*L[3];
				sf[9] = 4*L[1]*L[3];
				sf[10] = (2*L[0]-1)*L[0];
				sf[11] = (2*L[1]-1)*L[1];
				sf[12] = (2*L[2]-1)*L[2];
				sf[13] = (2*L[3]-1)*L[3];
				sf[14] = 4*L[0]*L[1];
				sf[15] = 4*L[1]*L[2];
				sf[16] = 4*L[0]*L[2];
				sf[17] = 4*L[0]*L[3];
				sf[18] = 4*L[2]*L[3];
				sf[19] = 4*L[1]*L[3];
			}
			break;

		case Element::FE_HEXAHEDRON8:
			sf.resize(8);
			sf[0] = (1-csi)*(1-eta)*(1-zeta)/8;
			sf[1] = (csi+1)*(1-eta)*(1-zeta)/8;
			sf[2] = (csi+1)*(eta+1)*(1-zeta)/8;
			sf[3] = (1-csi)*(eta+1)*(1-zeta)/8;
			sf[4] = (1-csi)*(1-eta)*(zeta+1)/8;
			sf[5] = (csi+1)*(1-eta)*(zeta+1)/8;
			sf[6] = (csi+1)*(eta+1)*(zeta+1)/8;
			sf[7] = (1-csi)*(eta+1)*(zeta+1)/8;
			break;

		case Element::FE_HEXAHEDRON27:
			// sf
			sf.resize(27);
			sf[ 0] = (csi-1)*csi*(eta-1)*eta*(zeta-1)*zeta/8;
			sf[ 1] = csi*(csi+1)*(eta-1)*eta*(zeta-1)*zeta/8;
			sf[ 2] = csi*(csi+1)*eta*(eta+1)*(zeta-1)*zeta/8;
			sf[ 3] = (csi-1)*csi*eta*(eta+1)*(zeta-1)*zeta/8;
			sf[ 4] = (csi-1)*csi*(eta-1)*eta*zeta*(zeta+1)/8;
			sf[ 5] = csi*(csi+1)*(eta-1)*eta*zeta*(zeta+1)/8;
			sf[ 6] = csi*(csi+1)*eta*(eta+1)*zeta*(zeta+1)/8;
			sf[ 7] = (csi-1)*csi*eta*(eta+1)*zeta*(zeta+1)/8;
			sf[ 8] = -(csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)*zeta/4;
			sf[ 9] = -(csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
			sf[10] = -(csi-1)*csi*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
			sf[11] = -csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
			sf[12] = -csi*(csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
			sf[13] = -(csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)*zeta/4;
			sf[14] = -csi*(csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
			sf[15] = -(csi-1)*csi*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
			sf[16] = -(csi-1)*(csi+1)*(eta-1)*eta*zeta*(zeta+1)/4;
			sf[17] = -(csi-1)*csi*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
			sf[18] = -csi*(csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
			sf[19] = -(csi-1)*(csi+1)*eta*(eta+1)*zeta*(zeta+1)/4;
			sf[20] = (csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/2;
			sf[21] = (csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/2;
			sf[22] = (csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
			sf[23] = csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
			sf[24] = (csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/2;
			sf[25] = (csi-1)*(csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/2;
			sf[26] = -(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1);
			break;

		case Element::FE_PRISM6:
			double L[3];
			L[0] = 1-csi-eta;
			L[1] = csi;
			L[2] = eta;

			sf.resize(6);
			sf[ 0] = L[0]*(1-zeta)/2.0;
			sf[ 1] = L[1]*(1-zeta)/2.0;
			sf[ 2] = L[2]*(1-zeta)/2.0;
			sf[ 3] = L[0]*(1+zeta)/2.0;
			sf[ 4] = L[1]*(1+zeta)/2.0;
			sf[ 5] = L[2]*(1+zeta)/2.0;
			break;

		default:
			//TODO this part should never be reached
			assert(false);
			break;
	}
#undef csi
#undef eta
#undef zeta

	return sf;
}


boost::tuple<std::vector<double>, std::vector<double>, std::vector<double> > Analysis::shape_function_derivatives(const Element::Type type, const fem::point &point)
{
	using namespace boost;
	using namespace std;
	tuple<vector<double>, vector<double>, vector<double> > sfd;	// shape function derivatives tuple
	vector<double> dNdcsi, dNdeta, dNdzeta;	// shape function derivatives weights 

	// declare a set of macros to make the code more readable
#define csi point.data[0]
#define eta point.data[1]
#define zeta point.data[2]

	// let's fill in the vectors
	switch(type)
	{
		case Element::FE_TETRAHEDRON4:
			dNdcsi.resize(4);
			dNdcsi[0] = -1;
			dNdcsi[1] = 1;
			dNdcsi[2] = 0;
			dNdcsi[3] = 0;

			dNdeta.resize(4);
			dNdeta[0] = -1;
			dNdeta[1] = 0;
			dNdeta[2] = 1;
			dNdeta[3] = 0;

			dNdzeta.resize(4);
			dNdzeta[0] = -1;
			dNdzeta[1] = 0;
			dNdzeta[2] = 0;
			dNdzeta[3] = 1;
			break;

		
		case Element::FE_TETRAHEDRON10:
			{
				double L[4];
				L[0] = 1-csi-eta-zeta;
				L[1] = csi;
				L[2] = eta;
				L[3] = zeta;
			
				dNdcsi.resize(10);
				dNdcsi[0] = -4*L[0]+1;
				dNdcsi[1] = 4*L[1]-1;
				dNdcsi[2] = 0;
				dNdcsi[3] = 0;
				dNdcsi[4] = 4*(-L[1]+L[0]);
				dNdcsi[5] = 4*L[2];
				dNdcsi[6] = -4*L[2];
				dNdcsi[7] = -4*L[3];
				dNdcsi[8] = 0;
				dNdcsi[9] = 4*L[3];

				dNdeta.resize(10);
				dNdeta[0] = -4*L[0]+1;
				dNdeta[1] = 0;
				dNdeta[2] = 4*L[2]-1;
				dNdeta[3] = 0;
				dNdeta[4] = -4*L[1];
				dNdeta[5] = 4*L[1];
				dNdeta[6] = 4*(-L[2]+L[0]);
				dNdeta[7] = -4*L[3];
				dNdeta[8] = 4*L[3];
				dNdeta[9] = 0;

				dNdzeta.resize(10);
				dNdzeta[0] = -4*L[0]+1;
				dNdzeta[1] = 0;
				dNdzeta[2] = 0;
				dNdzeta[3] = 4*L[3]-1;
				dNdzeta[4] = -4*L[1];
				dNdzeta[5] = 0;
				dNdzeta[6] = -4*L[2];
				dNdzeta[7] = 4*(-L[3]+L[0]);
				dNdzeta[8] = 4*L[2];
				dNdzeta[9] = 4*L[1];
			}
			break;

		/*
		case Element::FE_TETRAHEDRON20:
			{
				//TODO finish this
				double L[4];
				L[0] = 1-csi-eta-zeta;
				L[1] = csi;
				L[2] = eta;
				L[3] = zeta;
			
				sf.resize(10);
				sf[0] = (2*L[0]-1)*L[0];
				sf[1] = (2*L[1]-1)*L[1];
				sf[2] = (2*L[2]-1)*L[2];
				sf[3] = (2*L[3]-1)*L[3];
				sf[4] = 4*L[0]*L[1];
				sf[5] = 4*L[1]*L[2];
				sf[6] = 4*L[0]*L[2];
				sf[7] = 4*L[0]*L[3];
				sf[8] = 4*L[2]*L[3];
				sf[9] = 4*L[1]*L[3];
				sf[10] = (2*L[0]-1)*L[0];
				sf[11] = (2*L[1]-1)*L[1];
				sf[12] = (2*L[2]-1)*L[2];
				sf[13] = (2*L[3]-1)*L[3];
				sf[14] = 4*L[0]*L[1];
				sf[15] = 4*L[1]*L[2];
				sf[16] = 4*L[0]*L[2];
				sf[17] = 4*L[0]*L[3];
				sf[18] = 4*L[2]*L[3];
				sf[19] = 4*L[1]*L[3];

				dNdcsi.resize(10);
				dNdcsi[0] = -4*L[0]+1;
				dNdcsi[1] = 4*L[1]-1;
				dNdcsi[2] = 0;
				dNdcsi[3] = 0;
				dNdcsi[4] = 4*(-L[1]+L[0]);
				dNdcsi[5] = 4*L[2];
				dNdcsi[6] = -4*L[2];
				dNdcsi[7] = -4*L[3];
				dNdcsi[8] = 0;
				dNdcsi[9] = 4*L[3];


			}
			break;
			*/

		case Element::FE_HEXAHEDRON8:
			// dNdcsi
			dNdcsi.resize(8);
			dNdcsi[ 0] = -(1-eta)*(1-zeta)/8;
			dNdcsi[ 1] = (1-eta)*(1-zeta)/8;
			dNdcsi[ 2] = (eta+1)*(1-zeta)/8;
			dNdcsi[ 3] = -(eta+1)*(1-zeta)/8;
			dNdcsi[ 4] = -(1-eta)*(zeta+1)/8;
			dNdcsi[ 5] = (1-eta)*(zeta+1)/8;
			dNdcsi[ 6] = (eta+1)*(zeta+1)/8;
			dNdcsi[ 7] = -(eta+1)*(zeta+1)/8;

			// dNdeta
			dNdeta.resize(8);
			dNdeta[ 0] = -(1-csi)*(1-zeta)/8;
			dNdeta[ 1] = -(csi+1)*(1-zeta)/8;
			dNdeta[ 2] = (csi+1)*(1-zeta)/8;
			dNdeta[ 3] = (1-csi)*(1-zeta)/8;
			dNdeta[ 4] = -(1-csi)*(zeta+1)/8;
			dNdeta[ 5] = -(csi+1)*(zeta+1)/8;
			dNdeta[ 6] = (csi+1)*(zeta+1)/8;
			dNdeta[ 7] = (1-csi)*(zeta+1)/8;

			// dNdzeta
			dNdzeta.resize(8);
			dNdzeta[ 0] = -(1-csi)*(1-eta)/8;
			dNdzeta[ 1] = -(csi+1)*(1-eta)/8;
			dNdzeta[ 2] = -(csi+1)*(eta+1)/8;
			dNdzeta[ 3] = -(1-csi)*(eta+1)/8;
			dNdzeta[ 4] = (1-csi)*(1-eta)/8;
			dNdzeta[ 5] = (csi+1)*(1-eta)/8;
			dNdzeta[ 6] = (csi+1)*(eta+1)/8;
			dNdzeta[ 7] = (1-csi)*(eta+1)/8;
			break;

		case Element::FE_HEXAHEDRON27:
			// dNdcsi
			dNdcsi.resize(27);
			dNdcsi[ 0] = csi*(eta-1)*eta*(zeta-1)*zeta/8+(csi-1)*(eta-1)*eta*(zeta-1)*zeta/8;
			dNdcsi[ 1] = (csi+1)*(eta-1)*eta*(zeta-1)*zeta/8+csi*(eta-1)*eta*(zeta-1)*zeta/8;
			dNdcsi[ 2] = (csi+1)*eta*(eta+1)*(zeta-1)*zeta/8+csi*eta*(eta+1)*(zeta-1)*zeta/8;
			dNdcsi[ 3] = csi*eta*(eta+1)*(zeta-1)*zeta/8+(csi-1)*eta*(eta+1)*(zeta-1)*zeta/8;
			dNdcsi[ 4] = csi*(eta-1)*eta*zeta*(zeta+1)/8+(csi-1)*(eta-1)*eta*zeta*(zeta+1)/8;
			dNdcsi[ 5] = (csi+1)*(eta-1)*eta*zeta*(zeta+1)/8+csi*(eta-1)*eta*zeta*(zeta+1)/8;
			dNdcsi[ 6] = (csi+1)*eta*(eta+1)*zeta*(zeta+1)/8+csi*eta*(eta+1)*zeta*(zeta+1)/8;
			dNdcsi[ 7] = csi*eta*(eta+1)*zeta*(zeta+1)/8+(csi-1)*eta*(eta+1)*zeta*(zeta+1)/8;
			dNdcsi[ 8] = -(csi+1)*(eta-1)*eta*(zeta-1)*zeta/4-(csi-1)*(eta-1)*eta*(zeta-1)*zeta/4;
			dNdcsi[ 9] = -csi*(eta-1)*(eta+1)*(zeta-1)*zeta/4-(csi-1)*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
			dNdcsi[10] = -csi*(eta-1)*eta*(zeta-1)*(zeta+1)/4-(csi-1)*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
			dNdcsi[11] = -(csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/4-csi*(eta-1)*(eta+1)*(zeta-1)*zeta/4;
			dNdcsi[12] = -(csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/4-csi*(eta-1)*eta*(zeta-1)*(zeta+1)/4;
			dNdcsi[13] = -(csi+1)*eta*(eta+1)*(zeta-1)*zeta/4-(csi-1)*eta*(eta+1)*(zeta-1)*zeta/4;
			dNdcsi[14] = -(csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/4-csi*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
			dNdcsi[15] = -csi*eta*(eta+1)*(zeta-1)*(zeta+1)/4-(csi-1)*eta*(eta+1)*(zeta-1)*(zeta+1)/4;
			dNdcsi[16] = -(csi+1)*(eta-1)*eta*zeta*(zeta+1)/4-(csi-1)*(eta-1)*eta*zeta*(zeta+1)/4;
			dNdcsi[17] = -csi*(eta-1)*(eta+1)*zeta*(zeta+1)/4-(csi-1)*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
			dNdcsi[18] = -(csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/4-csi*(eta-1)*(eta+1)*zeta*(zeta+1)/4;
			dNdcsi[19] = -(csi+1)*eta*(eta+1)*zeta*(zeta+1)/4-(csi-1)*eta*(eta+1)*zeta*(zeta+1)/4;
			dNdcsi[20] = (csi+1)*(eta-1)*(eta+1)*(zeta-1)*zeta/2+(csi-1)*(eta-1)*(eta+1)*(zeta-1)*zeta/2;
			dNdcsi[21] = (csi+1)*(eta-1)*eta*(zeta-1)*(zeta+1)/2+(csi-1)*(eta-1)*eta*(zeta-1)*(zeta+1)/2;
			dNdcsi[22] = csi*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
			dNdcsi[23] = (csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2+csi*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)/2;
			dNdcsi[24] = (csi+1)*eta*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*eta*(eta+1)*(zeta-1)*(zeta+1)/2;
			dNdcsi[25] = (csi+1)*(eta-1)*(eta+1)*zeta*(zeta+1)/2+(csi-1)*(eta-1)*(eta+1)*zeta*(zeta+1)/2;
			dNdcsi[26] = -(csi+1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1)-(csi-1)*(eta-1)*(eta+1)*(zeta-1)*(zeta+1);

			// dNdeta
			dNdeta.resize(27);
			dNdeta[ 0] = (csi-1)*csi*eta*(zeta-1)*zeta/8+(csi-1)*csi*(eta-1)*(zeta-1)*zeta/8;
			dNdeta[ 1] = csi*(csi+1)*eta*(zeta-1)*zeta/8+csi*(csi+1)*(eta-1)*(zeta-1)*zeta/8;
			dNdeta[ 2] =  csi*(csi+1)*(eta+1)*(zeta-1)*zeta/8+csi*(csi+1)*eta*(zeta-1)*zeta/8;
			dNdeta[ 3] = (csi-1)*csi*(eta+1)*(zeta-1)*zeta/8+(csi-1)*csi*eta*(zeta-1)*zeta/8;
			dNdeta[ 4] =  (csi-1)*csi*eta*zeta*(zeta+1)/8+(csi-1)*csi*(eta-1)*zeta*(zeta+1)/8;
			dNdeta[ 5] = csi*(csi+1)*eta*zeta*(zeta+1)/8+csi*(csi+1)*(eta-1)*zeta*(zeta+1)/8;
			dNdeta[ 6] =  csi*(csi+1)*(eta+1)*zeta*(zeta+1)/8+csi*(csi+1)*eta*zeta*(zeta+1)/8;
			dNdeta[ 7] = (csi-1)*csi*(eta+1)*zeta*(zeta+1)/8+(csi-1)*csi*eta*zeta*(zeta+1)/8;
			dNdeta[ 8] =  -(csi-1)*(csi+1)*eta*(zeta-1)*zeta/4-(csi-1)*(csi+1)*(eta-1)*(zeta-1)*zeta/4;
			dNdeta[ 9] = -(csi-1)*csi*(eta+1)*(zeta-1)*zeta/4-(csi-1)*csi*(eta-1)*(zeta-1)*zeta/4;
			dNdeta[10] =  -(csi-1)*csi*eta*(zeta-1)*(zeta+1)/4-(csi-1)*csi*(eta-1)*(zeta-1)*(zeta+1)/4;
			dNdeta[11] = -csi*(csi+1)*(eta+1)*(zeta-1)*zeta/4-csi*(csi+1)*(eta-1)*(zeta-1)*zeta/4;
			dNdeta[12] =  -csi*(csi+1)*eta*(zeta-1)*(zeta+1)/4-csi*(csi+1)*(eta-1)*(zeta-1)*(zeta+1)/4;
			dNdeta[13] = -(csi-1)*(csi+1)*(eta+1)*(zeta-1)*zeta/4-(csi-1)*(csi+1)*eta*(zeta-1)*zeta/4;
			dNdeta[14] =  -csi*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)/4-csi*(csi+1)*eta*(zeta-1)*(zeta+1)/4;
			dNdeta[15] = -(csi-1)*csi*(eta+1)*(zeta-1)*(zeta+1)/4-(csi-1)*csi*eta*(zeta-1)*(zeta+1)/4;
			dNdeta[16] =  -(csi-1)*(csi+1)*eta*zeta*(zeta+1)/4-(csi-1)*(csi+1)*(eta-1)*zeta*(zeta+1)/4;
			dNdeta[17] = -(csi-1)*csi*(eta+1)*zeta*(zeta+1)/4-(csi-1)*csi*(eta-1)*zeta*(zeta+1)/4;
			dNdeta[18] =  -csi*(csi+1)*(eta+1)*zeta*(zeta+1)/4-csi*(csi+1)*(eta-1)*zeta*(zeta+1)/4;
			dNdeta[19] = -(csi-1)*(csi+1)*(eta+1)*zeta*(zeta+1)/4-(csi-1)*(csi+1)*eta*zeta*(zeta+1)/4;
			dNdeta[20] =  (csi-1)*(csi+1)*(eta+1)*(zeta-1)*zeta/2+(csi-1)*(csi+1)*(eta-1)*(zeta-1)*zeta/2;
			dNdeta[21] =  (csi-1)*(csi+1)*eta*(zeta-1)*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*(zeta-1)*(zeta+1)/2;
			dNdeta[22] =  (csi-1)*csi*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*csi*(eta-1)*(zeta-1)*(zeta+1)/2;
			dNdeta[23] =  csi*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)/2+csi*(csi+1)*(eta-1)*(zeta-1)*(zeta+1)/2;
			dNdeta[24] =  (csi-1)*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)/2+(csi-1)*(csi+1)*eta*(zeta-1)*(zeta+1)/2;
			dNdeta[25] =  (csi-1)*(csi+1)*(eta+1)*zeta*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*zeta*(zeta+1)/2;
			dNdeta[26] =  -(csi-1)*(csi+1)*(eta+1)*(zeta-1)*(zeta+1)-(csi-1)*(csi+1)*(eta-1)*(zeta-1)*(zeta+1);

			// dNdzeta
			dNdzeta.resize(27);
			dNdzeta[ 0] = (csi-1)*csi*(eta-1)*eta*zeta/8+(csi-1)*csi*(eta-1)*eta*(zeta-1)/8;
			dNdzeta[ 1] = csi*(csi+1)*(eta-1)*eta*zeta/8+csi*(csi+1)*(eta-1)*eta*(zeta-1)/8;
			dNdzeta[ 2] =  csi*(csi+1)*eta*(eta+1)*zeta/8+csi*(csi+1)*eta*(eta+1)*(zeta-1)/8;
			dNdzeta[ 3] = (csi-1)*csi*eta*(eta+1)*zeta/8+(csi-1)*csi*eta*(eta+1)*(zeta-1)/8;
			dNdzeta[ 4] =  (csi-1)*csi*(eta-1)*eta*(zeta+1)/8+(csi-1)*csi*(eta-1)*eta*zeta/8;
			dNdzeta[ 5] = csi*(csi+1)*(eta-1)*eta*(zeta+1)/8+csi*(csi+1)*(eta-1)*eta*zeta/8;
			dNdzeta[ 6] =  csi*(csi+1)*eta*(eta+1)*(zeta+1)/8+csi*(csi+1)*eta*(eta+1)*zeta/8;
			dNdzeta[ 7] = (csi-1)*csi*eta*(eta+1)*(zeta+1)/8+(csi-1)*csi*eta*(eta+1)*zeta/8;
			dNdzeta[ 8] =  -(csi-1)*(csi+1)*(eta-1)*eta*zeta/4-(csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)/4;
			dNdzeta[ 9] = -(csi-1)*csi*(eta-1)*(eta+1)*zeta/4-(csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)/4;
			dNdzeta[10] =  -(csi-1)*csi*(eta-1)*eta*(zeta+1)/4-(csi-1)*csi*(eta-1)*eta*(zeta-1)/4;
			dNdzeta[11] = -csi*(csi+1)*(eta-1)*(eta+1)*zeta/4-csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)/4;
			dNdzeta[12] =  -csi*(csi+1)*(eta-1)*eta*(zeta+1)/4-csi*(csi+1)*(eta-1)*eta*(zeta-1)/4;
			dNdzeta[13] = -(csi-1)*(csi+1)*eta*(eta+1)*zeta/4-(csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)/4;
			dNdzeta[14] =  -csi*(csi+1)*eta*(eta+1)*(zeta+1)/4-csi*(csi+1)*eta*(eta+1)*(zeta-1)/4;
			dNdzeta[15] = -(csi-1)*csi*eta*(eta+1)*(zeta+1)/4-(csi-1)*csi*eta*(eta+1)*(zeta-1)/4;
			dNdzeta[16] =  -(csi-1)*(csi+1)*(eta-1)*eta*(zeta+1)/4-(csi-1)*(csi+1)*(eta-1)*eta*zeta/4;
			dNdzeta[17] = -(csi-1)*csi*(eta-1)*(eta+1)*(zeta+1)/4-(csi-1)*csi*(eta-1)*(eta+1)*zeta/4;
			dNdzeta[18] =  -csi*(csi+1)*(eta-1)*(eta+1)*(zeta+1)/4-csi*(csi+1)*(eta-1)*(eta+1)*zeta/4;
			dNdzeta[19] = -(csi-1)*(csi+1)*eta*(eta+1)*(zeta+1)/4-(csi-1)*(csi+1)*eta*(eta+1)*zeta/4;
			dNdzeta[20] =  (csi-1)*(csi+1)*(eta-1)*(eta+1)*zeta/2+(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1)/2;
			dNdzeta[21] =  (csi-1)*(csi+1)*(eta-1)*eta*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*eta*(zeta-1)/2;
			dNdzeta[22] = (csi-1)*csi*(eta-1)*(eta+1)*(zeta+1)/2+(csi-1)*csi*(eta-1)*(eta+1)*(zeta-1)/2;
			dNdzeta[23] =  csi*(csi+1)*(eta-1)*(eta+1)*(zeta+1)/2+csi*(csi+1)*(eta-1)*(eta+1)*(zeta-1)/2;
			dNdzeta[24] = (csi-1)*(csi+1)*eta*(eta+1)*(zeta+1)/2+(csi-1)*(csi+1)*eta*(eta+1)*(zeta-1)/2;
			dNdzeta[25] =  (csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta+1)/2+(csi-1)*(csi+1)*(eta-1)*(eta+1)*zeta/2;
			dNdzeta[26] =  -(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta+1)-(csi-1)*(csi+1)*(eta-1)*(eta+1)*(zeta-1);
				break;

		case Element::FE_PRISM6:
				double L[3];
				L[0] = 1-csi-eta;
				L[1] = csi;
				L[2] = eta;

				dNdcsi.resize(6);
				dNdcsi[ 0] = -(1-zeta)/2.0;
				dNdcsi[ 1] =  (1-zeta)/2.0;
				dNdcsi[ 2] = 0;
				dNdcsi[ 3] = -(1+zeta)/2.0;
				dNdcsi[ 4] =  (1+zeta)/2.0;
				dNdcsi[ 5] = 0;

				dNdeta.resize(6);
				dNdeta[ 0] = -(1-zeta)/2.0;
				dNdeta[ 1] = 0;
				dNdeta[ 2] = (1-zeta)/2.0;
				dNdeta[ 3] = -(1+zeta)/2.0;
				dNdeta[ 4] = 0;
				dNdeta[ 5] = (1+zeta)/2.0;

				dNdzeta.resize(6);
				dNdzeta[ 0] = -L[0]/2.0;
				dNdzeta[ 1] = -L[1]/2.0;
				dNdzeta[ 2] = -L[2]/2.0;
				dNdzeta[ 3] = L[0]/2.0;
				dNdzeta[ 4] = L[1]/2.0;
				dNdzeta[ 5] = L[2]/2.0;
				break;

		default:
			//TODO this part should never be reached
			assert(false);
			break;
	}
#undef csi
#undef eta
#undef zeta

	// let's fill in the tuple
	sfd.get<0>() = dNdcsi;
	sfd.get<1>() = dNdeta;
	sfd.get<2>() = dNdzeta;
	return sfd;
}


void Analysis::setDegree(Element::Type &type, int d)
{
	degree[type] = d;
}


void Analysis::setDefaultIntegrationDegrees()
{
	//TODO tweak integration points
	degree[Element::FE_TRIANGLE3] = 1;
	degree[Element::FE_TRIANGLE6] = 1;
	degree[Element::FE_TRIANGLE10] = 1;
	degree[Element::FE_TRIANGLE15] = 1;

	degree[Element::FE_QUADRANGLE4] = 1;
	degree[Element::FE_QUADRANGLE8] = 1;
	degree[Element::FE_QUADRANGLE9] = 1;

	degree[Element::FE_TETRAHEDRON4] = 4;
	degree[Element::FE_TETRAHEDRON10] = 4;
	degree[Element::FE_TETRAHEDRON20] = 4;
	degree[Element::FE_TETRAHEDRON35] = 4;
	degree[Element::FE_TETRAHEDRON56] = 4;

	degree[Element::FE_HEXAHEDRON8] = 4;
	degree[Element::FE_HEXAHEDRON20] = 4;
	degree[Element::FE_HEXAHEDRON27] = 4;

	degree[Element::FE_PRISM6] = 4;
	degree[Element::FE_PRISM15] = 4;
	degree[Element::FE_PRISM18] = 4;

	degree[Element::FE_PYRAMID5] = 4;
	degree[Element::FE_PYRAMID14] = 4;
	degree[Element::FE_PYRAMID13] = 4;

	degree[Element::FE_ITRIANGLE9] = 1;
	degree[Element::FE_ITRIANGLE12] = 1;
	degree[Element::FE_ITRIANGLE15] = 1;
	degree[Element::FE_TRIANGLE21] = 1;
}


void Analysis::integration_points()
{
	using namespace boost;
	std::vector<tuple<fem::point, double> > ips;

	// Tetrahedron family, degree 1
	ips.push_back(tuple<fem::point,double>(fem::point(0.25,0.25,0.25), 1.0/6.0));
	ipwpl[Element::EF_TETRAHEDRON][1] = ips;

	// Tetrahedron family, degree 2
	ips.push_back(tuple<fem::point,double>(fem::point(0.58541019662496845446,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));
	ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.58541019662496845446,0.13819660112501051518),1.0/(6*4)));
	ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.58541019662496845446),1.0/(6*4)));
	ips.push_back(tuple<fem::point,double>(fem::point(0.13819660112501051518,0.13819660112501051518,0.13819660112501051518),1.0/(6*4)));

	ipwpl[Element::EF_TETRAHEDRON][2] = ips;
						
	// Tetrahedron family, degree 3
	ips.push_back(tuple<fem::point,double>(fem::point(0, 0, 0), 1.0/(40*6)));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3, 1.0/3, 1.0/3),  9.0/(40*6)));
	ipwpl[Element::EF_TETRAHEDRON][3] = ips;
						
	// Tetrahedron family, degree 3
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


	// Hexahedron family, degree 1 to 5
	for(int d = 1; d < 6; d++)
	{
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


	//prisms
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/3,1.0/3,0), 1*2/2));
	ipwpl[Element::EF_PRISM][1] = ips;

	ips.push_back(tuple<fem::point,double>(fem::point(2.0/3,1.0/6,-1.0/sqrt(3)), (1.0/3)*1/2));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,2.0/3,-1.0/sqrt(3)), (1.0/3)*1/2));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,1.0/6,-1.0/sqrt(3)), (1.0/3)*1/2));
	ips.push_back(tuple<fem::point,double>(fem::point(2.0/3,1.0/6, 1.0/sqrt(3)), (1.0/3)*1/2));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,2.0/3, 1.0/sqrt(3)), (1.0/3)*1/2));
	ips.push_back(tuple<fem::point,double>(fem::point(1.0/6,1.0/6, 1.0/sqrt(3)), (1.0/3)*1/2));
	ipwpl[Element::EF_PRISM][2] = ips;

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
			if(model.node_restrictions_list[i->first].dy() == false)
				lm[i->first].get<1>() = dof++;
			if(model.node_restrictions_list[i->first].dz() == false)
				lm[i->first].get<2>() = dof++;
		}
	}

	dof--;	// avoid the off by one error in resizing K_g and f_g

		// resize the FEM equation
	f.k.resize(dof,dof, false);
	f.f.resize(dof, false);
	f.d.resize(dof, false);
}


//inline void Analysis::add_elementary_to_global(const boost::numeric::ublas::symmetric_matrix<double, boost::numeric::ublas::upper> &k_elem, const boost::numeric::ublas::mapped_vector<double> &f_elem, FemEquation &f, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element)
inline void Analysis::add_elementary_stiffness_to_global(const boost::numeric::ublas::symmetric_matrix<double, boost::numeric::ublas::upper> &k_elem, FemEquation &f, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element)
{
	using namespace std;	//TODO remove cleanup code

	assert(k_elem.size1() == element.nodes.size()*3);
	assert(k_elem.size2() == element.nodes.size()*3);

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
					//cout << "id[u]: " << id[u] << ", jd[v]: " << jd[v] << endl;
					if( (id[u] != 0) && (jd[v] != 0) )
					{
						f.k(id[u]-1,jd[v]-1) += k_elem(3*i+u, 3*j+v);
					}
				}
			}
		}

		/*
		// and now let's process f_elem
		for(int u = 0; u < 3; u++)
		{
			if(id[u] != 0)
			{
				f.f(id[u]-1) += f_elem(3*i+u);
			}
		}
		*/
	}

}



}

