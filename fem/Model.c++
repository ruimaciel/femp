#include "Model.h++"


namespace fem
{

Model::Model()
{
	default_material = 0;
}


Model::~Model()
{
}


void Model::clear()
{
	node_list.clear();
	element_list.clear();
	material_list.clear();
	node_restrictions_list.clear();
	load_pattern_list.clear();
}


void Model::setNode(size_t pos, double x, double y, double z)
{
	Node n;
	n.set(x,y,z);
	this->node_list[pos] = n;
}


void Model::pushElement(fem::Element e)
{
	e.material = default_material;
	this->element_list.push_back(e);
}


void Model::pushElement(fem::Element::Type type, std::vector<size_t> nodes)
{
	fem::Element e;
	e.set(type,nodes);
	e.material = default_material;
	this->pushElement(e);
}


enum Model::Error Model::pushNodeRestrictions(size_t pos, fem::NodeRestrictions nr)
{
	// check if node is set
	if(node_list.find(pos) == node_list.end())
		return ERR_INVALID_NODE_REFERENCE;

	//TODO perform aditional error checking

	// push node restrictions object
	node_restrictions_list[pos] = nr;

	// everything went smoothly
	return ERR_OK;
}


enum Model::Error Model::pushLoadPattern(fem::LoadPattern lp)
{
	//TODO perform error checks

	load_pattern_list.push_back(lp);

	return ERR_OK;
}


enum Model::Error Model::build_fem_equation(struct FemEquation &f, const LoadPattern &lp)
{
	using namespace std;
	using namespace boost::numeric::ublas;

	// perform sanity checks on the model
	if(element_list.empty() )
		return ERR_NO_ELEMENTS;

	// at this point the model is considered to be OK.
	//TODO resize the global stiffness matrix and nodal forces vector
	f.f.clear();
	f.f.resize(node_list.size()*3);	// remove this after implementing a decent resize code

	//build a list of constitutive matrices
	std::vector< symmetric_matrix<double, upper> > D_list;
	for(std::vector<Material>::iterator material = material_list.begin(); material != material_list.end(); material++)
	{
		D_list.push_back(material->generateD());
	}

	// generate stiffness matrix by cycling through all elements in the model
	for(std::vector<Element>::iterator element = element_list.begin(); element != element_list.end(); element++)
	{
		qWarning("process element");
		switch(element->type)
		{
			/*
			case Element::FE_TETRAHEDRON4:
			{
				symmetric_matrix<double, upper> k_elem(4*3,4*3);
				mapped_vector<double> f_elem(4*3);
				//TODO finish this
			}
			break;
			*/

			case Element::FE_HEXAHEDRON8:
			{
			qWarning("hexahedron8");
/*	hexahedron8 node order
	3 ------ 2
	| \      . \
	|  7------- 6
	|  |     .  |
	0 .| . . 1  |
	 \ |       .|
	   4 ------ 5

	   N(csi,eta,zeta) = (1+csi1*csi)*(1+eta1*eta)*(1+zeta1*zeta)/8;
	   x(csi,eta,zeta) = sum(i = 1, i < 8, N(csi,eta,zeta)_i*x_i);
	   dN(csi,eta,zeta)/dcsi	= csi1*(1+eta1*eta)*(1+zeta1*zeta)/8;
	   dN(csi,eta,zeta)/deta	= eta1*(1+csi1*csi)*(1+zeta1*zeta)/8;
	   dN(csi,eta,zeta)/dzeta	= zeta1*(1+csi1*csi)*(1+eta1*eta)/8;
*/
				//testing hack. remove.
				if(element->nodes.size() != 8)
				{
					std::cerr << "Element without the right number of nodes" << std::endl;
					continue;
				}

				// set up the temporary variables for the elementary matrix and vector
				symmetric_matrix<double, upper> k_elem(8*3,8*3);
				mapped_vector<double> f_elem(8*3);
				matrix<double>	B(6,3*8);
				matrix<double>	Bt(3*8,6);
				matrix<double>	Jacobian(3,3), invJ(3,3);
				std::vector<std::pair<fem::point, double> > integration_points;
				int int_points = 2;	// tweak if needed
				double x[int_points], w[int_points];	// for the Gauss-Legendre integration points and weights
				double detJ = 0;

				// build a local coordinates list for the hexahedron's nodes
				std::vector<fem::point> local_coord;
				local_coord.push_back(fem::point(-1,-1,-1));
				local_coord.push_back(fem::point( 1,-1,-1));
				local_coord.push_back(fem::point( 1, 1,-1));
				local_coord.push_back(fem::point(-1, 1,-1));
				local_coord.push_back(fem::point(-1,-1, 1));
				local_coord.push_back(fem::point( 1,-1, 1));
				local_coord.push_back(fem::point( 1, 1, 1));
				local_coord.push_back(fem::point(-1, 1, 1));

				// build the integration point/weight list
				gauleg(x,w,int_points);
				for(int i = 0; i < int_points; i++)
				{
					for(int j = 0; j < int_points; j++)
					{
						for(int k = 0; k < int_points; k++)
						{
							integration_points.push_back(std::pair<fem::point,double>(fem::point(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
						}
					}
				}

				// cycle through the number of integration points
				k_elem.clear();
				size_t ei = std::distance(element_list.begin(), element) ;	// get the element index
				std::map<size_t,fem::DomainLoad>::const_iterator domain_load;
				domain_load = lp.domain_loads.find(ei);
				for (std::vector<std::pair<fem::point,double> >::iterator i = integration_points.begin(); i != integration_points.end(); i++)
				{
					// generate the jacobian
					Jacobian = J(i->first,*element);	// generate the jacobian matrix for this element
					detJ = det3by3(Jacobian);
					invJ = invert3by3(Jacobian,detJ);

					// cycle through the element's nodes to set up the B matrix
					B.clear();
					for(int n = 0; n < 8; n++)
					{
						//local: local coordinate constant
						// p: coordinates of the integration points
#define DCSI(p,local) local.x()*(1+local.y()*p.y())*(1+local.z()*p.z())/8.0
#define DETA(p,local) local.y()*(1+local.x()*p.x())*(1+local.z()*p.z())/8.0
#define DZETA(p,local) local.z()*(1+local.x()*p.x())*(1+local.y()*p.y())/8.0
						// set the partial derivatives
						double dNdx, dNdy, dNdz; 
						dNdx = invJ(0,0)*DCSI(i->first,local_coord[n]) + invJ(0,1)*DETA(i->first,local_coord[n]) + invJ(0,2)*DZETA(i->first,local_coord[n]); 
						dNdy = invJ(1,0)*DCSI(i->first,local_coord[n]) + invJ(1,1)*DETA(i->first,local_coord[n]) + invJ(1,2)*DZETA(i->first,local_coord[n]); 
						dNdz = invJ(2,0)*DCSI(i->first,local_coord[n]) + invJ(2,1)*DETA(i->first,local_coord[n]) + invJ(2,2)*DZETA(i->first,local_coord[n]); 
#undef DCSI
#undef DETA
#undef DZETA

						// set the current node portion of the B matrix
						B(0,3*n)	= dNdx;
						B(1,3*n+1)	= dNdy;
						B(2,3*n+2)	= dNdz;
						B(3,3*n)	= dNdy;	B(3,3*n+1) = dNdx;
						B(4,3*n)	= dNdz;	B(4,3*n+2) = dNdx;
						B(5,3*n+1)	= dNdz;	B(5,3*n+2) = dNdy;

						// set the force vector for the domain loads
						if(domain_load != lp.domain_loads.end())
						{
#define PSI(p,local) (1+local.x()*p.x())*(1+local.y()*p.y())*(1+local.z()*p.z())/8.0
							f_elem(3*n) += PSI(i->first,local_coord[n])*domain_load->second.force_shape[n].x()*detJ*i->second;
							f_elem(3*n+1) += PSI(i->first,local_coord[n])*domain_load->second.force_shape[n].y()*detJ*i->second;
							f_elem(3*n+2) += PSI(i->first,local_coord[n])*domain_load->second.force_shape[n].z()*detJ*i->second;
#undef PSI
						}
					}
					Bt = trans(B);
					symmetric_matrix<double> D = D_list[element->material];

					matrix<double> temp;
					// and now, k_elem = sum(Bt*D*B*detJ*i->second);
					temp = prod(Bt,D);
					temp = prod(temp,B);
					temp *= detJ*i->second;
					k_elem += temp;	// adding up the full result
				}

				// add the nodal loads contributions
				std::cout << D_list[element->material]  << endl;

				//TODO setup k from k_elem through scatter operation
				std::cout << k_elem << endl;
			}
			break;


			case Element::FE_HEXAHEDRON27:
			{
			qWarning("hexahedron27");
/*	hexahedron27 node order
	3----13----2
	|\         |\
	|15    24  | 14
	9  \ 20    11 \
	|   7----19+---6
	|22 |  26  | 23|
	0---+-8----1   |
	 \ 17    25 \  18
	 10 |  21    12|
	   \|         \|
	    4----16----5
*/
				//testing hack. remove.
				if(element->nodes.size() != 27)
				{
					std::cerr << "Element without the right number of nodes" << std::endl;
					continue;
				}

				// set up the temporary variables for the elementary matrix and vector
				symmetric_matrix<double, upper> k_elem(27*3,27*3);
				mapped_vector<double> f_elem(27*3);
				matrix<double>	B(6,3*27);
				matrix<double>	Bt(3*27,6);
				matrix<double>	Jacobian(3,3), invJ(3,3);
				std::vector<std::pair<fem::point, double> > integration_points;
				int int_points = 3;	// tweak if needed
				double x[int_points], w[int_points];	// for the Gauss-Legendre integration points and weights
				double detJ = 0;

				// build the integration point/weight list
				gauleg(x,w,int_points);
				for(int i = 0; i < int_points; i++)
				{
					for(int j = 0; j < int_points; j++)
					{
						for(int k = 0; k < int_points; k++)
						{
							integration_points.push_back(std::pair<fem::point,double>(fem::point(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
						}
					}
				}

				// cycle through the number of integration points
				k_elem.clear();
				size_t ei = std::distance(element_list.begin(), element) ;	// get the element index
				std::map<size_t,fem::DomainLoad>::const_iterator domain_load;
				domain_load = lp.domain_loads.find(ei);
				for (std::vector<std::pair<fem::point,double> >::iterator i = integration_points.begin(); i != integration_points.end(); i++)
				{
					// generate the jacobian
					Jacobian = J(i->first,*element);	// generate the jacobian matrix for this element
					detJ = det3by3(Jacobian);
					invJ = invert3by3(Jacobian,detJ);

					// cycle through the element's nodes to set up the B matrix
					B.clear();
					for(int n = 0; n < 27; n++)
					{
//local: local coordinate constant
// p: coordinates of the integration points
#define DCSI(p,local) local.x()*(1+local.y()*p.y())*(1+local.z()*p.z())/8.0
#define DETA(p,local) local.y()*(1+local.x()*p.x())*(1+local.z()*p.z())/8.0
#define DZETA(p,local) local.z()*(1+local.x()*p.x())*(1+local.y()*p.y())/8.0
						// set the partial derivatives
						double dNdx, dNdy, dNdz; 
						/*
						dNdx = invJ(0,0)*DCSI(i->first,local_coord[n]) + invJ(0,1)*DETA(i->first,local_coord[n]) + invJ(0,2)*DZETA(i->first,local_coord[n]); 
						dNdy = invJ(1,0)*DCSI(i->first,local_coord[n]) + invJ(1,1)*DETA(i->first,local_coord[n]) + invJ(1,2)*DZETA(i->first,local_coord[n]); 
						dNdz = invJ(2,0)*DCSI(i->first,local_coord[n]) + invJ(2,1)*DETA(i->first,local_coord[n]) + invJ(2,2)*DZETA(i->first,local_coord[n]); 
						*/
#undef DCSI
#undef DETA
#undef DZETA

						// set the current node portion of the B matrix
						B(0,3*n) = dNdx;
						B(1,3*n+1) = dNdy;
						B(2,3*n+2) = dNdz;
						B(3,3*n) = dNdy;	B(3,3*n+1) = dNdx;
						B(4,3*n) = dNdz;	B(4,3*n+2) = dNdx;
						B(5,3*n+1) = dNdz;	B(5,3*n+2) = dNdy;

						// set the force vector for the domain loads
						if(domain_load != lp.domain_loads.end())
						{
#define PSI(p,local) (1+local.x()*p.x())*(1+local.y()*p.y())*(1+local.z()*p.z())/8.0
							/*
							f_elem(3*n) += PSI(i->first,local_coord[n])*domain_load->second.force_shape[n].x()*detJ*i->second;
							f_elem(3*n+1) += PSI(i->first,local_coord[n])*domain_load->second.force_shape[n].y()*detJ*i->second;
							f_elem(3*n+2) += PSI(i->first,local_coord[n])*domain_load->second.force_shape[n].z()*detJ*i->second;
							*/
#undef PSI
						}
					}
					Bt = trans(B);
					symmetric_matrix<double> D = D_list[element->material];

					matrix<double> temp;
					// and now, k_elem = sum(Bt*D*B*detJ*i->second);
					temp = prod(Bt,D);
					temp = prod(temp,B);
					temp *= detJ*i->second;
					k_elem += temp;	// adding up the full result
				}

				// add the nodal loads contributions
				std::cout << D_list[element->material]  << endl;

				//TODO setup k from k_elem through scatter operation
				std::cout << k_elem << endl;
				std::cout << f_elem << endl;
			}
			break;

			default:
			cerr << "Model::build_fem_structure: unsupported element" << element->type << endl;
			break;
		}
	}


	// now set up the equivalent forces vector

	// set nodal forces
	for(std::map<size_t,fem::NodalLoad>::const_iterator nodal_load = lp.nodal_loads.begin(); nodal_load != lp.nodal_loads.end(); nodal_load++)
	{
		//TODO must implement the scatter operation
		size_t n;
		n = nodal_load->first;

		// set the nodal loads
		f.f[3*n] = nodal_load->second.force.data[0];
		f.f[3*n+1] = nodal_load->second.force.data[1];
		f.f[3*n+2] = nodal_load->second.force.data[2];
	}

	// fem equation is set.
	return ERR_OK;
}


boost::numeric::ublas::matrix<double> Model::J(double csi,double eta,double zeta, const Element &element)
{
#define DCSI(C,C1,E,E1,Z,Z1) C1*(1+E1*E)*(1+Z1*Z)/8.0
#define DETA(C,C1,E,E1,Z,Z1) E1*(1+C1*C)*(1+Z1*Z)/8.0
#define DZETA(C,C1,E,E1,Z,Z1) Z1*(1+C1*C)*(1+E1*E)/8.0
	boost::numeric::ublas::matrix<double> J(3,3);

	switch(element.type)
	{
		/*
		case Element::FE_TETRAHEDRON4:
			break;
		*/

		case Element::FE_HEXAHEDRON8:
			{
				// dN/dcsi
				J(0,0) = DCSI(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].x() + \
					 DCSI(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].x() + \
					 DCSI(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].x() + \
					 DCSI(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].x() + \
					 DCSI(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].x() + \
					 DCSI(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].x() + \
					 DCSI(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].x() + \
					 DCSI(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].x();
				J(0,1) = DCSI(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].y() + \
					 DCSI(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].y() + \
					 DCSI(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].y() + \
					 DCSI(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].y() + \
					 DCSI(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].y() + \
					 DCSI(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].y() + \
					 DCSI(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].y() + \
					 DCSI(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].y();
				J(0,2) = DCSI(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].z() + \
					 DCSI(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].z() + \
					 DCSI(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].z() + \
					 DCSI(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].z() + \
					 DCSI(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].z() + \
					 DCSI(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].z() + \
					 DCSI(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].z() + \
					 DCSI(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].z();
				// dN/deta
				J(1,0) = DETA(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].x() + \
					 DETA(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].x() + \
					 DETA(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].x() + \
					 DETA(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].x() + \
					 DETA(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].x() + \
					 DETA(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].x() + \
					 DETA(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].x() + \
					 DETA(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].x();
				J(1,1) = DETA(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].y() + \
					 DETA(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].y() + \
					 DETA(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].y() + \
					 DETA(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].y() + \
					 DETA(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].y() + \
					 DETA(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].y() + \
					 DETA(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].y() + \
					 DETA(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].y();
				J(1,2) = DETA(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].z() + \
					 DETA(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].z() + \
					 DETA(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].z() + \
					 DETA(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].z() + \
					 DETA(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].z() + \
					 DETA(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].z() + \
					 DETA(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].z() + \
					 DETA(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].z();
				// dN/dzeta
				J(2,0) = DZETA(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].x() + \
					 DZETA(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].x() + \
					 DZETA(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].x() + \
					 DZETA(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].x() + \
					 DZETA(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].x() + \
					 DZETA(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].x() + \
					 DZETA(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].x() + \
					 DZETA(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].x();
				J(2,1) = DZETA(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].y() + \
					 DZETA(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].y() + \
					 DZETA(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].y() + \
					 DZETA(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].y() + \
					 DZETA(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].y() + \
					 DZETA(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].y() + \
					 DZETA(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].y() + \
					 DZETA(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].y();
				J(2,2) = DZETA(csi,-1,eta,-1, zeta, -1)*node_list[element.nodes[0]].z() + \
					 DZETA(csi,-1,eta, 1, zeta, -1)*node_list[element.nodes[1]].z() + \
					 DZETA(csi,-1,eta, 1, zeta,  1)*node_list[element.nodes[2]].z() + \
					 DZETA(csi,-1,eta,-1, zeta,  1)*node_list[element.nodes[3]].z() + \
					 DZETA(csi, 1,eta,-1, zeta, -1)*node_list[element.nodes[4]].z() + \
					 DZETA(csi, 1,eta, 1, zeta, -1)*node_list[element.nodes[5]].z() + \
					 DZETA(csi, 1,eta, 1, zeta,  1)*node_list[element.nodes[6]].z() + \
					 DZETA(csi, 1,eta,-1, zeta,  1)*node_list[element.nodes[7]].z();
				// Jacobian matriz all set up. return it
				return J;
			}
			break;

		case Element::FE_HEXAHEDRON27:
			{
				double c[3] = {csi*(csi+1),	(csi-1)*(csi+1),	(csi-1)*csi};
				double e[3] = {eta*(eta+1),	(eta-1)*(eta+1),	(eta-1)*eta};
				double z[3] = {zeta*(zeta+1),	(zeta-1)*(zeta+1),	(zeta-1)*zeta};

				J(0,0) = node_list[element.nodes[7]].x()*((csi+1)*e[0]*z[0]/8+csi*e[0]*z[0]/8) \
					+node_list[element.nodes[20]].x()*(-(csi+1)*e[0]*z[0]/4-(csi-1)*e[0]*z[0]/4) \
					+node_list[element.nodes[8]].x()*(csi*e[0]*z[0]/8+(csi-1)*e[0]*z[0]/8) \
					+node_list[element.nodes[26]].x()*((csi+1)*e[1]*z[0]/2+(csi-1)*e[1]*z[0]/2) \
					+node_list[element.nodes[19]].x()*(-(csi+1)*e[1]*z[0]/4-csi*e[1]*z[0]/4) \
					+node_list[element.nodes[18]].x()*(-csi*e[1]*z[0]/4-(csi-1)*e[1]*z[0]/4) \
					+node_list[element.nodes[6]].x()*((csi+1)*e[2]*z[0]/8+csi*e[2]*z[0]/8) \
					+node_list[element.nodes[17]].x()*(-(csi+1)*e[2]*z[0]/4-(csi-1)*e[2]*z[0]/4) \
					+node_list[element.nodes[5]].x()*(csi*e[2]*z[0]/8+(csi-1)*e[2]*z[0]/8) \
					+node_list[element.nodes[25]].x()*((csi+1)*e[0]*z[2]/2+(csi-1)*e[0]*z[2]/2) \
					+node_list[element.nodes[15]].x()*(-(csi+1)*e[0]*z[2]/4-csi*e[0]*z[2]/4) \
					+node_list[element.nodes[16]].x()*(-csi*e[0]*z[2]/4-(csi-1)*e[0]*z[2]/4) \
					+node_list[element.nodes[24]].x()*((csi+1)*e[1]*z[2]/2+csi*e[1]*z[2]/2) \
					+node_list[element.nodes[27]].x()*(-(csi+1)*e[1]*z[2]-(csi-1)*e[1]*z[2]) \
					+node_list[element.nodes[23]].x()*(csi*e[1]*z[2]/2+(csi-1)*e[1]*z[2]/2) \
					+node_list[element.nodes[22]].x()*((csi+1)*e[2]*z[2]/2+(csi-1)*e[2]*z[2]/2) \
					+node_list[element.nodes[13]].x()*(-(csi+1)*e[2]*z[2]/4-csi*e[2]*z[2]/4) \
					+node_list[element.nodes[11]].x()*(-csi*e[2]*z[2]/4-(csi-1)*e[2]*z[2]/4) \
					+node_list[element.nodes[3]].x()*((csi+1)*e[0]*z[2]/8+csi*e[0]*z[2]/8) \
					+node_list[element.nodes[14]].x()*(-(csi+1)*e[0]*z[2]/4-(csi-1)*e[0]*z[2]/4) \
					+node_list[element.nodes[4]].x()*(csi*e[0]*z[2]/8+(csi-1)*e[0]*z[2]/8) \
					+node_list[element.nodes[21]].x()*((csi+1)*e[1]*z[2]/2+(csi-1)*e[1]*z[2]/2) \
					+node_list[element.nodes[12]].x()*(-(csi+1)*e[1]*z[2]/4-csi*e[1]*z[2]/4) \
					+node_list[element.nodes[10]].x()*(-csi*e[1]*z[2]/4-(csi-1)*e[1]*z[2]/4) \
					+node_list[element.nodes[2]].x()*((csi+1)*e[2]*z[2]/8+csi*e[2]*z[2]/8) \
					+node_list[element.nodes[9]].x()*(-(csi+1)*e[2]*z[2]/4-(csi-1)*e[2]*z[2]/4) \
					+node_list[element.nodes[1]].x()*(csi*e[2]*z[2]/8+(csi-1)*e[2]*z[2]/8);

					J(0,1) =node_list[element.nodes[7]].y()*((csi+1)*e[0]*z[0]/8+csi*e[0]*z[0]/8) \
					+node_list[element.nodes[20]].y()*(-(csi+1)*e[0]*z[0]/4-(csi-1)*e[0]*z[0]/4) \
					+node_list[element.nodes[8]].y()*(csi*e[0]*z[0]/8+(csi-1)*e[0]*z[0]/8) \
					+node_list[element.nodes[26]].y()*((csi+1)*e[1]*z[0]/2+(csi-1)*e[1]*z[0]/2) \
					+node_list[element.nodes[19]].y()*(-(csi+1)*e[1]*z[0]/4-csi*e[1]*z[0]/4) \
					+node_list[element.nodes[18]].y()*(-csi*e[1]*z[0]/4-(csi-1)*e[1]*z[0]/4) \
					+node_list[element.nodes[6]].y()*((csi+1)*e[2]*z[0]/8+csi*e[2]*z[0]/8) \
					+node_list[element.nodes[17]].y()*(-(csi+1)*e[2]*z[0]/4-(csi-1)*e[2]*z[0]/4) \
					+node_list[element.nodes[5]].y()*(csi*e[2]*z[0]/8+(csi-1)*e[2]*z[0]/8) \
					+node_list[element.nodes[25]].y()*((csi+1)*e[0]*z[1]/2+(csi-1)*e[0]*z[1]/2) \
					+node_list[element.nodes[15]].y()*(-(csi+1)*e[0]*z[1]/4-csi*e[0]*z[1]/4) \
					+node_list[element.nodes[16]].y()*(-csi*e[0]*z[1]/4-(csi-1)*e[0]*z[1]/4) \
					+node_list[element.nodes[24]].y()*((csi+1)*e[1]*z[1]/2+csi*e[1]*z[1]/2) \
					+node_list[element.nodes[27]].y()*(-(csi+1)*e[1]*z[1]-(csi-1)*e[1]*z[1]) \
					+node_list[element.nodes[23]].y()*(csi*e[1]*z[1]/2+(csi-1)*e[1]*z[1]/2) \
					+node_list[element.nodes[22]].y()*((csi+1)*e[2]*z[1]/2+(csi-1)*e[2]*z[1]/2) \
					+node_list[element.nodes[13]].y()*(-(csi+1)*e[2]*z[1]/4-csi*e[2]*z[1]/4) \
					+node_list[element.nodes[11]].y()*(-csi*e[2]*z[1]/4-(csi-1)*e[2]*z[1]/4) \
					+node_list[element.nodes[3]].y()*((csi+1)*e[0]*z[2]/8+csi*e[0]*z[2]/8) \
					+node_list[element.nodes[14]].y()*(-(csi+1)*e[0]*z[2]/4-(csi-1)*e[0]*z[2]/4) \
					+node_list[element.nodes[4]].y()*(csi*e[0]*z[2]/8+(csi-1)*e[0]*z[2]/8) \
					+node_list[element.nodes[21]].y()*((csi+1)*e[1]*z[2]/2+(csi-1)*e[1]*z[2]/2) \
					+node_list[element.nodes[12]].y()*(-(csi+1)*e[1]*z[2]/4-csi*e[1]*z[2]/4) \
					+node_list[element.nodes[10]].y()*(-csi*e[1]*z[2]/4-(csi-1)*e[1]*z[2]/4) \
					+node_list[element.nodes[2]].y()*((csi+1)*e[2]*z[2]/8+csi*e[2]*z[2]/8) \
					+node_list[element.nodes[9]].y()*(-(csi+1)*e[2]*z[2]/4-(csi-1)*e[2]*z[2]/4) \
					+node_list[element.nodes[1]].y()*(csi*e[2]*z[2]/8+(csi-1)*e[2]*z[2]/8);

					J(0,2) = node_list[element.nodes[7]].z()*((csi+1)*e[0]*z[0]/8+csi*e[0]*z[0]/8) \
					+node_list[element.nodes[20]].z()*(-(csi+1)*e[0]*z[0]/4-(csi-1)*e[0]*z[0]/4) \
					+node_list[element.nodes[8]].z()*(csi*e[0]*z[0]/8+(csi-1)*e[0]*z[0]/8) \
					+node_list[element.nodes[26]].z()*((csi+1)*e[1]*z[0]/2+(csi-1)*e[1]*z[0]/2) \
					+node_list[element.nodes[19]].z()*(-(csi+1)*e[1]*z[0]/4-csi*e[1]*z[0]/4) \
					+node_list[element.nodes[18]].z()*(-csi*e[1]*z[0]/4-(csi-1)*e[1]*z[0]/4) \
					+node_list[element.nodes[6]].z()*((csi+1)*e[2]*z[0]/8+csi*e[2]*z[0]/8) \
					+node_list[element.nodes[17]].z()*(-(csi+1)*e[2]*z[0]/4-(csi-1)*e[2]*z[0]/4) \
					+node_list[element.nodes[5]].z()*(csi*e[2]*z[0]/8+(csi-1)*e[2]*z[0]/8) \
					+node_list[element.nodes[25]].z()*((csi+1)*e[0]*z[1]/2+(csi-1)*e[0]*z[1]/2) \
					+node_list[element.nodes[15]].z()*(-(csi+1)*e[0]*z[1]/4-csi*e[0]*z[1]/4) \
					+node_list[element.nodes[16]].z()*(-csi*e[0]*z[1]/4-(csi-1)*e[0]*z[1]/4) \
					+node_list[element.nodes[24]].z()*((csi+1)*e[1]*z[1]/2+csi*e[1]*z[1]/2) \
					+node_list[element.nodes[27]].z()*(-(csi+1)*e[1]*z[1]-(csi-1)*e[1]*z[1]) \
					+node_list[element.nodes[23]].z()*(csi*e[1]*z[1]/2+(csi-1)*e[1]*z[1]/2) \
					+node_list[element.nodes[22]].z()*((csi+1)*e[2]*z[1]/2+(csi-1)*e[2]*z[1]/2) \
					+node_list[element.nodes[13]].z()*(-(csi+1)*e[2]*z[1]/4-csi*e[2]*z[1]/4) \
					+node_list[element.nodes[11]].z()*(-csi*e[2]*z[1]/4-(csi-1)*e[2]*z[1]/4) \
					+node_list[element.nodes[3]].z()*((csi+1)*e[0]*z[2]/8+csi*e[0]*z[2]/8) \
					+node_list[element.nodes[14]].z()*(-(csi+1)*e[0]*z[2]/4-(csi-1)*e[0]*z[2]/4) \
					+node_list[element.nodes[4]].z()*(csi*e[0]*z[2]/8+(csi-1)*e[0]*z[2]/8) \
					+node_list[element.nodes[21]].z()*((csi+1)*e[1]*z[2]/2+(csi-1)*e[1]*z[2]/2) \
					+node_list[element.nodes[12]].z()*(-(csi+1)*e[1]*z[2]/4-csi*e[1]*z[2]/4) \
					+node_list[element.nodes[10]].z()*(-csi*e[1]*z[2]/4-(csi-1)*e[1]*z[2]/4) \
					+node_list[element.nodes[2]].z()*((csi+1)*e[2]*z[2]/8+csi*e[2]*z[2]/8) \
					+node_list[element.nodes[9]].z()*(-(csi+1)*e[2]*z[2]/4-(csi-1)*e[2]*z[2]/4) \
					+node_list[element.nodes[1]].z()*(csi*e[2]*z[2]/8+(csi-1)*e[2]*z[2]/8);

					J(1,0) = node_list[element.nodes[7]].x()*(c[0]*(eta+1)*z[0]/8+c[0]*eta*z[0]/8) \
					+node_list[element.nodes[19]].x()*(-c[0]*(eta+1)*z[0]/4-c[0]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[26]].x()*(c[1]*(eta+1)*z[0]/2+c[1]*(eta-1)*z[0]/2) \
					+node_list[element.nodes[20]].x()*(-c[1]*(eta+1)*z[0]/4-c[1]*eta*z[0]/4) \
					+node_list[element.nodes[8]].x()*(c[2]*(eta+1)*z[0]/8+c[2]*eta*z[0]/8) \
					+node_list[element.nodes[18]].x()*(-c[2]*(eta+1)*z[0]/4-c[2]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[6]].x()*(c[0]*eta*z[0]/8+c[0]*(eta-1)*z[0]/8) \
					+node_list[element.nodes[17]].x()*(-c[1]*eta*z[0]/4-c[1]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[5]].x()*(c[2]*eta*z[0]/8+c[2]*(eta-1)*z[0]/8) \
					+node_list[element.nodes[24]].x()*(c[0]*(eta+1)*z[1]/2+c[0]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[15]].x()*(-c[0]*(eta+1)*z[1]/4-c[0]*eta*z[1]/4) \
					+node_list[element.nodes[25]].x()*(c[1]*(eta+1)*z[1]/2+c[1]*eta*z[1]/2) \
					+node_list[element.nodes[27]].x()*(-c[1]*(eta+1)*z[1]-c[1]*(eta-1)*z[1]) \
					+node_list[element.nodes[23]].x()*(c[2]*(eta+1)*z[1]/2+c[2]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[16]].x()*(-c[2]*(eta+1)*z[1]/4-c[2]*eta*z[1]/4) \
					+node_list[element.nodes[13]].x()*(-c[0]*eta*z[1]/4-c[0]*(eta-1)*z[1]/4) \
					+node_list[element.nodes[22]].x()*(c[1]*eta*z[1]/2+c[1]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[11]].x()*(-c[2]*eta*z[1]/4-c[2]*(eta-1)*z[1]/4) \
					+node_list[element.nodes[3]].x()*(c[0]*(eta+1)*z[2]/8+c[0]*eta*z[2]/8) \
					+node_list[element.nodes[12]].x()*(-c[0]*(eta+1)*z[2]/4-c[0]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[21]].x()*(c[1]*(eta+1)*z[2]/2+c[1]*(eta-1)*z[2]/2) \
					+node_list[element.nodes[14]].x()*(-c[1]*(eta+1)*z[2]/4-c[1]*eta*z[2]/4) \
					+node_list[element.nodes[4]].x()*(c[2]*(eta+1)*z[2]/8+c[2]*eta*z[2]/8) \
					+node_list[element.nodes[10]].x()*(-c[2]*(eta+1)*z[2]/4-c[2]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[2]].x()*(c[0]*eta*z[2]/8+c[0]*(eta-1)*z[2]/8) \
					+node_list[element.nodes[9]].x()*(-c[1]*eta*z[2]/4-c[1]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[1]].x()*(c[2]*eta*z[2]/8+c[2]*(eta-1)*z[2]/8);

					J(1,1) = node_list[element.nodes[7]].y()*(c[0]*(eta+1)*z[0]/8+c[0]*eta*z[0]/8) \
					+node_list[element.nodes[19]].y()*(-c[0]*(eta+1)*z[0]/4-c[0]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[26]].y()*(c[1]*(eta+1)*z[0]/2+c[1]*(eta-1)*z[0]/2) \
					+node_list[element.nodes[20]].y()*(-c[1]*(eta+1)*z[0]/4-c[1]*eta*z[0]/4) \
					+node_list[element.nodes[8]].y()*(c[2]*(eta+1)*z[0]/8+c[2]*eta*z[0]/8) \
					+node_list[element.nodes[18]].y()*(-c[2]*(eta+1)*z[0]/4-c[2]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[6]].y()*(c[0]*eta*z[0]/8+c[0]*(eta-1)*z[0]/8) \
					+node_list[element.nodes[17]].y()*(-c[1]*eta*z[0]/4-c[1]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[5]].y()*(c[2]*eta*z[0]/8+c[2]*(eta-1)*z[0]/8) \
					+node_list[element.nodes[24]].y()*(c[0]*(eta+1)*z[1]/2+c[0]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[15]].y()*(-c[0]*(eta+1)*z[1]/4-c[0]*eta*z[1]/4) \
					+node_list[element.nodes[25]].y()*(c[1]*(eta+1)*z[1]/2+c[1]*eta*z[1]/2) \
					+node_list[element.nodes[27]].y()*(-c[1]*(eta+1)*z[1]-c[1]*(eta-1)*z[1]) \
					+node_list[element.nodes[23]].y()*(c[2]*(eta+1)*z[1]/2+c[2]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[16]].y()*(-c[2]*(eta+1)*z[1]/4-c[2]*eta*z[1]/4) \
					+node_list[element.nodes[13]].y()*(-c[0]*eta*z[1]/4-c[0]*(eta-1)*z[1]/4) \
					+node_list[element.nodes[22]].y()*(c[1]*eta*z[1]/2+c[1]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[11]].y()*(-c[2]*eta*z[1]/4-c[2]*(eta-1)*z[1]/4) \
					+node_list[element.nodes[3]].y()*(c[0]*(eta+1)*z[2]/8+c[0]*eta*z[2]/8) \
					+node_list[element.nodes[12]].y()*(-c[0]*(eta+1)*z[2]/4-c[0]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[21]].y()*(c[1]*(eta+1)*z[2]/2+c[1]*(eta-1)*z[2]/2) \
					+node_list[element.nodes[14]].y()*(-c[1]*(eta+1)*z[2]/4-c[1]*eta*z[2]/4) \
					+node_list[element.nodes[4]].y()*(c[2]*(eta+1)*z[2]/8+c[2]*eta*z[2]/8) \
					+node_list[element.nodes[10]].y()*(-c[2]*(eta+1)*z[2]/4-c[2]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[2]].y()*(c[0]*eta*z[2]/8+c[0]*(eta-1)*z[2]/8) \
					+node_list[element.nodes[9]].y()*(-c[1]*eta*z[2]/4-c[1]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[1]].y()*(c[2]*eta*z[2]/8+c[2]*(eta-1)*z[2]/8);

				J(1,2) = node_list[element.nodes[7]].z()*(c[0]*(eta+1)*z[0]/8+c[0]*eta*z[0]/8) \
					+node_list[element.nodes[19]].z()*(-c[0]*(eta+1)*z[0]/4-c[0]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[26]].z()*(c[1]*(eta+1)*z[0]/2+c[1]*(eta-1)*z[0]/2) \
					+node_list[element.nodes[20]].z()*(-c[1]*(eta+1)*z[0]/4-c[1]*eta*z[0]/4) \
					+node_list[element.nodes[8]].z()*(c[2]*(eta+1)*z[0]/8+c[2]*eta*z[0]/8) \
					+node_list[element.nodes[18]].z()*(-c[2]*(eta+1)*z[0]/4-c[2]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[6]].z()*(c[0]*eta*z[0]/8+c[0]*(eta-1)*z[0]/8) \
					+node_list[element.nodes[17]].z()*(-c[1]*eta*z[0]/4-c[1]*(eta-1)*z[0]/4) \
					+node_list[element.nodes[5]].z()*(c[2]*eta*z[0]/8+c[2]*(eta-1)*z[0]/8) \
					+node_list[element.nodes[24]].z()*(c[0]*(eta+1)*z[1]/2+c[0]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[15]].z()*(-c[0]*(eta+1)*z[1]/4-c[0]*eta*z[1]/4) \
					+node_list[element.nodes[25]].z()*(c[1]*(eta+1)*z[1]/2+c[1]*eta*z[1]/2) \
					+node_list[element.nodes[27]].z()*(-c[1]*(eta+1)*z[1]-c[1]*(eta-1)*z[1]) \
					+node_list[element.nodes[23]].z()*(c[2]*(eta+1)*z[1]/2+c[2]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[16]].z()*(-c[2]*(eta+1)*z[1]/4-c[2]*eta*z[1]/4) \
					+node_list[element.nodes[13]].z()*(-c[0]*eta*z[1]/4-c[0]*(eta-1)*z[1]/4) \
					+node_list[element.nodes[22]].z()*(c[1]*eta*z[1]/2+c[1]*(eta-1)*z[1]/2) \
					+node_list[element.nodes[11]].z()*(-c[2]*eta*z[1]/4-c[2]*(eta-1)*z[1]/4) \
					+node_list[element.nodes[3]].z()*(c[0]*(eta+1)*z[2]/8+c[0]*eta*z[2]/8) \
					+node_list[element.nodes[12]].z()*(-c[0]*(eta+1)*z[2]/4-c[0]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[21]].z()*(c[1]*(eta+1)*z[2]/2+c[1]*(eta-1)*z[2]/2) \
					+node_list[element.nodes[14]].z()*(-c[1]*(eta+1)*z[2]/4-c[1]*eta*z[2]/4) \
					+node_list[element.nodes[4]].z()*(c[2]*(eta+1)*z[2]/8+c[2]*eta*z[2]/8) \
					+node_list[element.nodes[10]].z()*(-c[2]*(eta+1)*z[2]/4-c[2]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[2]].z()*(c[0]*eta*z[2]/8+c[0]*(eta-1)*z[2]/8) \
					+node_list[element.nodes[9]].z()*(-c[1]*eta*z[2]/4-c[1]*(eta-1)*z[2]/4) \
					+node_list[element.nodes[1]].z()*(c[2]*eta*z[2]/8+c[2]*(eta-1)*z[2]/8);

					J(2,0) = node_list[element.nodes[7]].x()*(c[0]*e[0]*(zeta+1)/8+c[0]*e[0]*zeta/8)\
					+node_list[element.nodes[15]].x()*(-c[0]*e[0]*(zeta+1)/4-c[0]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[25]].x()*(c[1]*e[0]*(zeta+1)/2+c[1]*e[0]*(zeta-1)/2) \
					+node_list[element.nodes[20]].x()*(-c[1]*e[0]*(zeta+1)/4-c[1]*e[0]*zeta/4) \
					+node_list[element.nodes[8]].x()*(c[2]*e[0]*(zeta+1)/8+c[2]*e[0]*zeta/8) \
					+node_list[element.nodes[16]].x()*(-c[2]*e[0]*(zeta+1)/4-c[2]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[24]].x()*(c[0]*e[1]*(zeta+1)/2+c[0]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[19]].x()*(-c[0]*e[1]*(zeta+1)/4-c[0]*e[1]*zeta/4) \
					+node_list[element.nodes[26]].x()*(c[1]*e[1]*(zeta+1)/2+c[1]*e[1]*zeta/2) \
					+node_list[element.nodes[27]].x()*(-c[1]*e[1]*(zeta+1)-c[1]*e[1]*(zeta-1)) \
					+node_list[element.nodes[23]].x()*(c[2]*e[1]*(zeta+1)/2+c[2]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[18]].x()*(-c[2]*e[1]*(zeta+1)/4-c[2]*e[1]*zeta/4) \
					+node_list[element.nodes[6]].x()*(c[0]*e[2]*(zeta+1)/8+c[0]*e[2]*zeta/8) \
					+node_list[element.nodes[13]].x()*(-c[0]*e[2]*(zeta+1)/4-c[0]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[22]].x()*(c[1]*e[2]*(zeta+1)/2+c[1]*e[2]*(zeta-1)/2) \
					+node_list[element.nodes[17]].x()*(-c[1]*e[2]*(zeta+1)/4-c[1]*e[2]*zeta/4) \
					+node_list[element.nodes[5]].x()*(c[2]*e[2]*(zeta+1)/8+c[2]*e[2]*zeta/8) \
					+node_list[element.nodes[11]].x()*(-c[2]*e[2]*(zeta+1)/4-c[2]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[3]].x()*(c[0]*e[0]*zeta/8+c[0]*e[0]*(zeta-1)/8) \
					+node_list[element.nodes[14]].x()*(-c[1]*e[0]*zeta/4-c[1]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[4]].x()*(c[2]*e[0]*zeta/8+c[2]*e[0]*(zeta-1)/8) \
					+node_list[element.nodes[12]].x()*(-c[0]*e[1]*zeta/4-c[0]*e[1]*(zeta-1)/4) \
					+node_list[element.nodes[21]].x()*(c[1]*e[1]*zeta/2+c[1]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[10]].x()*(-c[2]*e[1]*zeta/4-c[2]*e[1]*(zeta-1)/4) \
					+node_list[element.nodes[2]].x()*(c[0]*e[2]*zeta/8+c[0]*e[2]*(zeta-1)/8) \
					+node_list[element.nodes[9]].x()*(-c[1]*e[2]*zeta/4-c[1]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[1]].x()*(c[2]*e[2]*zeta/8+c[2]*e[2]*(zeta-1)/8);

					J(2,1) = node_list[element.nodes[7]].y()*(c[0]*e[0]*(zeta+1)/8+c[0]*e[0]*zeta/8) \
					+node_list[element.nodes[15]].y()*(-c[0]*e[0]*(zeta+1)/4-c[0]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[25]].y()*(c[1]*e[0]*(zeta+1)/2+c[1]*e[0]*(zeta-1)/2) \
					+node_list[element.nodes[20]].y()*(-c[1]*e[0]*(zeta+1)/4-c[1]*e[0]*zeta/4) \
					+node_list[element.nodes[8]].y()*(c[2]*e[0]*(zeta+1)/8+c[2]*e[0]*zeta/8) \
					+node_list[element.nodes[16]].y()*(-c[2]*e[0]*(zeta+1)/4-c[2]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[24]].y()*(c[0]*e[1]*(zeta+1)/2+c[0]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[19]].y()*(-c[0]*e[1]*(zeta+1)/4-c[0]*e[1]*zeta/4) \
					+node_list[element.nodes[26]].y()*(c[1]*e[1]*(zeta+1)/2+c[1]*e[1]*zeta/2) \
					+node_list[element.nodes[27]].y()*(-c[1]*e[1]*(zeta+1)-c[1]*e[1]*(zeta-1)) \
					+node_list[element.nodes[23]].y()*(c[2]*e[1]*(zeta+1)/2+c[2]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[18]].y()*(-c[2]*e[1]*(zeta+1)/4-c[2]*e[1]*zeta/4) \
					+node_list[element.nodes[6]].y()*(c[0]*e[2]*(zeta+1)/8+c[0]*e[2]*zeta/8) \
					+node_list[element.nodes[13]].y()*(-c[0]*e[2]*(zeta+1)/4-c[0]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[22]].y()*(c[1]*e[2]*(zeta+1)/2+c[1]*e[2]*(zeta-1)/2) \
					+node_list[element.nodes[17]].y()*(-c[1]*e[2]*(zeta+1)/4-c[1]*e[2]*zeta/4) \
					+node_list[element.nodes[5]].y()*(c[2]*e[2]*(zeta+1)/8+c[2]*e[2]*zeta/8) \
					+node_list[element.nodes[11]].y()*(-c[2]*e[2]*(zeta+1)/4-c[2]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[3]].y()*(c[0]*e[0]*zeta/8+c[0]*e[0]*(zeta-1)/8) \
					+node_list[element.nodes[14]].y()*(-c[1]*e[0]*zeta/4-c[1]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[4]].y()*(c[2]*e[0]*zeta/8+c[2]*e[0]*(zeta-1)/8) \
					+node_list[element.nodes[12]].y()*(-c[0]*e[1]*zeta/4-c[0]*e[1]*(zeta-1)/4) \
					+node_list[element.nodes[21]].y()*(c[1]*e[1]*zeta/2+c[1]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[10]].y()*(-c[2]*e[1]*zeta/4-c[2]*e[1]*(zeta-1)/4) \
					+node_list[element.nodes[2]].y()*(c[0]*e[2]*zeta/8+c[0]*e[2]*(zeta-1)/8) \
					+node_list[element.nodes[9]].y()*(-c[1]*e[2]*zeta/4-c[1]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[1]].y()*(c[2]*e[2]*zeta/8+c[2]*e[2]*(zeta-1)/8) ;

					J(2,2) = node_list[element.nodes[7]].z()*(c[0]*e[0]*(zeta+1)/8+c[0]*e[0]*zeta/8) \
					+node_list[element.nodes[15]].z()*(-c[0]*e[0]*(zeta+1)/4-c[0]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[25]].z()*(c[1]*e[0]*(zeta+1)/2+c[1]*e[0]*(zeta-1)/2) \
					+node_list[element.nodes[20]].z()*(-c[1]*e[0]*(zeta+1)/4-c[1]*e[0]*zeta/4) \
					+node_list[element.nodes[8]].z()*(c[2]*e[0]*(zeta+1)/8+c[2]*e[0]*zeta/8) \
					+node_list[element.nodes[16]].z()*(-c[2]*e[0]*(zeta+1)/4-c[2]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[24]].z()*(c[0]*e[1]*(zeta+1)/2+c[0]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[19]].z()*(-c[0]*e[1]*(zeta+1)/4-c[0]*e[1]*zeta/4) \
					+node_list[element.nodes[26]].z()*(c[1]*e[1]*(zeta+1)/2+c[1]*e[1]*zeta/2) \
					+node_list[element.nodes[27]].z()*(-c[1]*e[1]*(zeta+1)-c[1]*e[1]*(zeta-1)) \
					+node_list[element.nodes[23]].z()*(c[2]*e[1]*(zeta+1)/2+c[2]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[18]].z()*(-c[2]*e[1]*(zeta+1)/4-c[2]*e[1]*zeta/4) \
					+node_list[element.nodes[6]].z()*(c[0]*e[2]*(zeta+1)/8+c[0]*e[2]*zeta/8) \
					+node_list[element.nodes[13]].z()*(-c[0]*e[2]*(zeta+1)/4-c[0]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[22]].z()*(c[1]*e[2]*(zeta+1)/2+c[1]*e[2]*(zeta-1)/2) \
					+node_list[element.nodes[17]].z()*(-c[1]*e[2]*(zeta+1)/4-c[1]*e[2]*zeta/4) \
					+node_list[element.nodes[5]].z()*(c[2]*e[2]*(zeta+1)/8+c[2]*e[2]*zeta/8) \
					+node_list[element.nodes[11]].z()*(-c[2]*e[2]*(zeta+1)/4-c[2]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[3]].z()*(c[0]*e[0]*zeta/8+c[0]*e[0]*(zeta-1)/8) \
					+node_list[element.nodes[14]].z()*(-c[1]*e[0]*zeta/4-c[1]*e[0]*(zeta-1)/4) \
					+node_list[element.nodes[4]].z()*(c[2]*e[0]*zeta/8+c[2]*e[0]*(zeta-1)/8) \
					+node_list[element.nodes[12]].z()*(-c[0]*e[1]*zeta/4-c[0]*e[1]*(zeta-1)/4) \
					+node_list[element.nodes[21]].z()*(c[1]*e[1]*zeta/2+c[1]*e[1]*(zeta-1)/2) \
					+node_list[element.nodes[10]].z()*(-c[2]*e[1]*zeta/4-c[2]*e[1]*(zeta-1)/4) \
					+node_list[element.nodes[2]].z()*(c[0]*e[2]*zeta/8+c[0]*e[2]*(zeta-1)/8) \
					+node_list[element.nodes[9]].z()*(-c[1]*e[2]*zeta/4-c[1]*e[2]*(zeta-1)/4) \
					+node_list[element.nodes[1]].z()*(c[2]*e[2]*zeta/8+c[2]*e[2]*(zeta-1)/8) ;
				return J;
			}
			break;

		default:
			std::cerr << "Model::J(): missing type" << std::endl;
			break;
	}
#undef DCSI
#undef DETA
#undef DZETA
}



boost::numeric::ublas::matrix<double> Model::invert3by3(const boost::numeric::ublas::matrix<double> &M, double det)
{
	assert(M.size1() == 3);
	assert(M.size2() == 3);
	assert(det > 0);
	/*
	   (%i1) M: matrix([a,b,c],[d,e,f],[g,h,i]);
	   [ a  b  c ]
	   [         ]
	   (%o1)                             [ d  e  f ]
	   [         ]
	   [ g  h  i ]
	   (%i2) N: invert(M), detout;
	   [ e i - f h  c h - b i  b f - c e ]
	   [                                 ]
	   [ f g - d i  a i - c g  c d - a f ]
	   [                                 ]
	   [ d h - e g  b g - a h  a e - b d ]
	   (%o2)            ---------------------------------------------
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


double Model::det3by3(const boost::numeric::ublas::matrix<double> &M)
{
	assert(M.size1() == 3);
	assert(M.size2() == 3);
	return	M(0,0)*( M(1,1)*M(2,2) - M(1,2)*M(2,1)) + \
		M(0,1)*( M(1,2)*M(2,0) - M(1,0)*M(2,2)) + \
		M(0,2)*( M(1,0)*M(2,1) - M(1,1)*M(2,0));
}


boost::numeric::ublas::matrix<double> Model::J(fem::point p, const Element &element)
{
	return J(p.x(),p.y(), p.z(), element);
}


enum Model::Error Model::run(const LoadPattern &lp)
{
	struct FemEquation f;
	//TODO finish this

	//this is a nasty hack to test the code. To be removed.
	build_fem_equation(f, lp);

	return ERR_OK;
}


void Model::gauleg(double x[], double w[], int n)
{
	//TODO test this code
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

}
