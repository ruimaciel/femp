#include "Analysis.h++"

#include "../lalib/Matrix.h++"
#include "../lalib/Vector.h++"
#include <Eigen/Sparse>
#include <Eigen/LU>

#include "../Logs.h++"

#include "elements/BaseElement.h++"


namespace fem
{

Analysis::Analysis()
{
	// build all lists of integration points/weights pairs
	setDefaultIntegrationDegrees();
}


Analysis::Analysis(const Analysis &copied)
{
	// copy the FEM equation
	this->K = copied.K;
	this->f = copied.f;
	this->d = copied.d;
}


Analysis::~Analysis()
{
}


enum Analysis::Error Analysis::build_fem_equation(Model &model, const LoadPattern &lp)
{
	mylog.setPrefix("Analysis::build_fem_equation()");

	using namespace std;
	using namespace Eigen;

	// perform sanity checks on the model
	if(model.element_list.empty() )
		return ERR_NO_ELEMENTS;

		// generate the location matrix
	make_location_matrix(model);

		// declare variables
	double detJ = 0;

	Matrix3d J, invJ;
	std::vector< Eigen::Matrix<double,6,6> > D_list;

		// set up the temporary variables for the elementary matrix and vector
	Matrix<double,Dynamic, Dynamic> k_elem;
	Matrix<double,Dynamic,1> f_elem;
	Matrix<double,Dynamic,Dynamic> B;
	Matrix<double,Dynamic,Dynamic> Bt;
	Matrix<double,6,6> D = model.material_list[0].generateD();

	size_t material_index = 0;

	BaseElement<double> *element = NULL;	// points to the current element class

	int nnodes;	// number of nodes
	std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator dof;	// for the force vector scatter operation


		// generate stiffness matrix by cycling through all elements in the model
	mylog.message("Beginning stiffness matrix");
	for(std::vector<Element>::iterator element_iterator = model.element_list.begin(); element_iterator != model.element_list.end(); element_iterator++)
	{
			// sets the current element routines
		switch(element_iterator->type)
		{
			case Element::FE_TETRAHEDRON4:
				element = &tetra4;
				break;

			case Element::FE_TETRAHEDRON10:
				element = &tetra10;
				break;

			case Element::FE_HEXAHEDRON8:
				element = &hexa8;
				break;

			case Element::FE_HEXAHEDRON20:
				element = &hexa20;
				break;

			case Element::FE_HEXAHEDRON27:
				element = &hexa27;
				break;

			case Element::FE_PRISM6:
				element = &prism6;
				break;

			case Element::FE_PRISM15:
				element = &prism15;
				break;

			case Element::FE_PRISM18:
				element = &prism18;
				break;

			default:
				mylog.message("unsupported element");
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

			// get the number of expected nodes used by the current element_iterator type
		nnodes = element_iterator->node_number();

			// resize the elementary matrices to fit the new node size
		k_elem.resize(nnodes*3,nnodes*3);
		f_elem.resize(nnodes*3);
		B.resize(6,3*nnodes);
		Bt.resize(3*nnodes,6);

			// initialize variables
		k_elem.setZero();
		f_elem.setZero();
		B.setZero();

			// build the element_iterator stiffness matrix: cycle through the number of integration points
		// cout << "base ipwpl size: " << ipwpl[element_iterator->family()].size() << endl;
		// cout << "element ipwpl size: " << element->ipwpl.size() << endl;
		
		for (std::vector<boost::tuple<fem::point,double> >::iterator i = element->ipwpl[degree[element_iterator->type]].begin(); i != element->ipwpl[degree[element_iterator->type]].end(); i++)
		{
			cout << "ipwpl: " << i->get<0>() << ",\t" << i->get<1>() << endl;
#define X(N) model.node_list[element_iterator->nodes[N]].x()
#define Y(N) model.node_list[element_iterator->nodes[N]].y()
#define Z(N) model.node_list[element_iterator->nodes[N]].z()

				// set the shape function and it's partial derivatives for this integration point
			element->setdNdcsi( i->get<0>() );
			element->setdNdeta( i->get<0>() );
			element->setdNdzeta( i->get<0>() );

				// generate the jacobian
			J.setZero();
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += element->dNdcsi[n]*X(n);	J(0,1) += element->dNdcsi[n]*Y(n);	J(0,2) += element->dNdcsi[n]*Z(n);
				J(1,0) += element->dNdeta[n]*X(n);	J(1,1) += element->dNdeta[n]*Y(n);	J(1,2) += element->dNdeta[n]*Z(n);
				J(2,0) += element->dNdzeta[n]*X(n);	J(2,1) += element->dNdzeta[n]*Y(n);	J(2,2) += element->dNdzeta[n]*Z(n);
			}

			//std::cout << "J:\n" << J << "\n" << endl;

			detJ = J.determinant();

				// return error if we stumble on a negative determinant
			if(detJ <= 0)
			{
				QString m;
				m.sprintf("stumbled on a negative determinant on element_iterator %ld", distance(model.element_list.begin(), element_iterator));
				mylog.message(m);
				
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
#define dNdx invJ(0,0)*element->dNdcsi[n] + invJ(0,1)*element->dNdeta[n] + invJ(0,2)*element->dNdzeta[n]
#define dNdy invJ(1,0)*element->dNdcsi[n] + invJ(1,1)*element->dNdeta[n] + invJ(1,2)*element->dNdzeta[n]
#define dNdz invJ(2,0)*element->dNdcsi[n] + invJ(2,1)*element->dNdeta[n] + invJ(2,2)*element->dNdzeta[n]

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
	
			if(material_index != element_iterator->material)
				D = model.material_list[element_iterator->material].generateD();

			// add this integration point's contribution
			k_elem += Bt*D*B*detJ*i->get<1>();
		}
		//cout << "k elem: " << k_elem << endl;

			// add elementary stiffness matrix to the global stiffness matrix 
		add_elementary_stiffness_to_global(k_elem, lm, *element_iterator);
	}

		// now set up the equivalent forces vector
	// set nodal force contribution made by the domain loads
	for(std::map<size_t,fem::DomainLoad>::const_iterator domain_load = lp.domain_loads.begin(); domain_load != lp.domain_loads.end(); domain_load++)
	{
		//TODO rewrite to rely on the element_reference classes
		fem::Element *element_reference;
		element_reference = &model.element_list[domain_load->first];
		nnodes = element_reference->node_number();

		// set the routines for the current element
		switch(element_reference->type)
		{
			case Element::FE_TETRAHEDRON4:
				element = &tetra4;
				break;

			case Element::FE_TETRAHEDRON10:
				element = &tetra10;
				break;

			case Element::FE_HEXAHEDRON8:
				element = &hexa8;
				break;

			case Element::FE_HEXAHEDRON20:
				element = &hexa20;
				break;

			case Element::FE_HEXAHEDRON27:
				element = &hexa27;
				break;

			case Element::FE_PRISM6:
				element = &prism6;
				break;

			case Element::FE_PRISM15:
				element = &prism15;
				break;

			case Element::FE_PRISM18:
				element = &prism18;
				break;

			default:
				mylog.message("unsupported element");
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

		f_elem.resize(nnodes*3);
		f_elem.setZero();

		// as the distribution is linear across the domain then degree 1 is enough
		for (std::vector<boost::tuple<fem::point,double> >::iterator i = element->ipwpl[ddegree[element_reference->type]].begin(); i != element->ipwpl[ddegree[element_reference->type]].end(); i++)
		{
				// build the Jacobian
			element->setN( i->get<0>());
			element->setdNdcsi( i->get<0>() );
			element->setdNdeta( i->get<0>() );
			element->setdNdzeta( i->get<0>() );

				// generate the jacobian
			J.setZero();
#define X(N)	model.node_list[element_reference->nodes[N]].x()
#define Y(N)	model.node_list[element_reference->nodes[N]].y()
#define Z(N)	model.node_list[element_reference->nodes[N]].z()
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += element->dNdcsi[n]*X(n);	J(0,1) += element->dNdcsi[n]*Y(n);	J(0,2) += element->dNdcsi[n]*Z(n);
				J(1,0) += element->dNdeta[n]*X(n);	J(1,1) += element->dNdeta[n]*Y(n);	J(1,2) += element->dNdeta[n]*Z(n);
				J(2,0) += element->dNdzeta[n]*X(n);	J(2,1) += element->dNdzeta[n]*Y(n);	J(2,2) += element->dNdzeta[n]*Z(n);
			}

			detJ = J.determinant();
			if(detJ <= 0)
			{
				QString m;
				m.sprintf("stumbled on a negative determinant on element_reference %ld", domain_load->first);
				mylog.message(m);

				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			// and now the f_elem
			for(int n = 0; n < nnodes; n++)
			{
#define N(n) element->N[n]
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

		// integrate the surface loads
	//TODO finish this
	mylog.message("Surface loads");

	for(std::vector<fem::SurfaceLoad>::const_iterator surface_load = lp.surface_loads.begin(); surface_load != lp.surface_loads.end(); surface_load++)
	{
		switch(surface_load->type)
		{
			case Element::FE_TRIANGLE3:
				element = &tri3;
				break;

			case Element::FE_TRIANGLE6:
				element = &tri6;
				break;

			case Element::FE_TRIANGLE10:
				element = &tri10;
				break;

			case Element::FE_QUADRANGLE4:
				element = &quad4;
				break;

			case Element::FE_QUADRANGLE8:
				element = &quad8;
				break;

			case Element::FE_QUADRANGLE9:
				element = &quad9;
				break;

			default:
				mylog.message("unsupported element");
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

		nnodes = surface_load->node_number();
		f_elem.resize(nnodes*3);
		f_elem.setZero();

		for (std::vector<boost::tuple<fem::point,double> >::iterator i = element->ipwpl[degree[surface_load->type]].begin(); i != element->ipwpl[degree[surface_load->type]].end(); i++)
		{
				// get shape function and shape function derivatives in this integration point's coordinate
			element->setN( i->get<0>() );
			element->setdNdcsi(i->get<0>() );
			element->setdNdeta(i->get<0>() );

				// calculate the Jacobian
			J.setZero();
#define X(N)	model.node_list[surface_load->nodes[N]].x()
#define Y(N)	model.node_list[surface_load->nodes[N]].y()
#define Z(N)	model.node_list[surface_load->nodes[N]].z()
			J(0,0) = 1;	J(1,0) = 1;	J(2,0) = 1;
			for(int n = 0; n < nnodes; n++)
			{
				J(0,1) += element->dNdcsi[n]*X(n);	J(1,1) += element->dNdcsi[n]*Y(n);	J(2,1) += element->dNdcsi[n]*Z(n);
				J(0,2) += element->dNdeta[n]*X(n);	J(1,2) += element->dNdeta[n]*Y(n);	J(2,2) += element->dNdeta[n]*Z(n);
			}
			//cout << "\nJ matrix:\n" << J << endl;

			detJ = J.determinant();
			if(detJ <= 0)
			{
				mylog.message("stumbled on a negative determinant on the surface load");

				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}


#define N(n) element->N[n]
#define b(COORD) domain_load->second.force.COORD()
#define W    i->get<1>()
				// calculate q(csi, eta, zeta)
			fem::point q;
			for(int j = 0; j < nnodes; j++)
			{
				q += N(j)*surface_load->surface_forces[j];
			}
			
			//cout << "\nq: " << q << endl;

			for(int n = 0; n < nnodes; n++)
			{

				f_elem(3*n  ) += N(n)*q.x()*detJ*W;
				f_elem(3*n+1) += N(n)*q.y()*detJ*W;
				f_elem(3*n+2) += N(n)*q.z()*detJ*W;
			}
		}
		//cout << "\nf_elem:\n" << f_elem << endl;

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

	// set nodal forces
	mylog.message("Nodal loads");
	for(std::map<size_t,fem::NodalLoad>::const_iterator nodal_load = lp.nodal_loads.begin(); nodal_load != lp.nodal_loads.end(); nodal_load++)
	{
		size_t n;
		n = nodal_load->first;

		// set the nodal loads
		if(lm[n].get<0>() != 0)
			f(lm[n].get<0>()-1) += nodal_load->second.x();
		if(lm[n].get<1>() != 0)
			f(lm[n].get<1>()-1) += nodal_load->second.y();
		if(lm[n].get<2>() != 0)
			f(lm[n].get<2>()-1) += nodal_load->second.z();
	}

	//DEBUG
	//cout << "K[" << k.rows() << ", " << k.cols() << "]" << endl;
	
	mylog.message("Finished building FEM equation");

	mylog.clearPrefix();

	// fem equation is set.
	return ERR_OK;
}


void Analysis::output_fem_equation(std::ostream &out)
{
	out << "\t\"fem equation\" : {\n";

	// output stiffness matrix
	out << "\t\t\"stiffness matrix\" : [\n";
	for(size_t i = 0; i < K.rows(); i++)
	{
		out << "\t\t\t[";
		for(size_t j = 0; j < K.columns(); j++)
		{
			if(j != 0)
				out << ",";
			out << "\t" << K.value(i,j);
		}
		out << "]";
		if(i + 1 < K.rows())
			out << ",";
		out << "\n";
	}
	out << "\t\t],\n";

	// output force vector
	out << "\t\t\"force vector\" : [\n";
	for(size_t i = 0; i < f.size(); i++)
	{
		out << "\t\t\t";
		out << f.value(i);
		if(i +1 < f.size() )
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

	degree[Element::FE_TETRAHEDRON4 ] = 1;	ddegree[Element::FE_TETRAHEDRON4 ] = 1;
	degree[Element::FE_TETRAHEDRON10] = 2;	ddegree[Element::FE_TETRAHEDRON10] = 2;
	degree[Element::FE_TETRAHEDRON20] = 4;	ddegree[Element::FE_TETRAHEDRON20] = 3;
	degree[Element::FE_TETRAHEDRON35] = 4;	ddegree[Element::FE_TETRAHEDRON35] = 1;
	degree[Element::FE_TETRAHEDRON56] = 4;	ddegree[Element::FE_TETRAHEDRON56] = 1;

	degree[Element::FE_HEXAHEDRON8 ] = 2;	ddegree[Element::FE_HEXAHEDRON8 ] = 1;
	degree[Element::FE_HEXAHEDRON20] = 3;	ddegree[Element::FE_HEXAHEDRON20] = 2;
	degree[Element::FE_HEXAHEDRON27] = 3;	ddegree[Element::FE_HEXAHEDRON27] = 2;

	degree[Element::FE_PRISM6 ] = 2;	ddegree[Element::FE_PRISM6 ] = 1;
	degree[Element::FE_PRISM15] = 4;	ddegree[Element::FE_PRISM15] = 2;
	degree[Element::FE_PRISM18] = 4;	ddegree[Element::FE_PRISM18] = 2;

	degree[Element::FE_PYRAMID5 ] = 4;	ddegree[Element::FE_PYRAMID5 ] = 1;
	degree[Element::FE_PYRAMID14] = 4;	ddegree[Element::FE_PYRAMID14] = 1;
	degree[Element::FE_PYRAMID13] = 4;	ddegree[Element::FE_PYRAMID13] = 1;

	degree[Element::FE_ITRIANGLE9 ] = 1;	ddegree[Element::FE_ITRIANGLE9 ] = 1;
	degree[Element::FE_ITRIANGLE12] = 1;	ddegree[Element::FE_ITRIANGLE12] = 1;
	degree[Element::FE_ITRIANGLE15] = 1;	ddegree[Element::FE_ITRIANGLE15] = 1;
	degree[Element::FE_TRIANGLE21 ] = 1;	ddegree[Element::FE_TRIANGLE21 ] = 1;
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
	K.resize(dof,dof);
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
						K(id[u]-1,jd[v]-1) += k_elem(3*i+u, 3*j+v);
					}
				}
			}
		}
	}
}


}

