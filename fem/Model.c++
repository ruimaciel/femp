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

	//build a list of constitutive matrices
	std::vector< symmetric_matrix<double, upper> > D_list;
	for(std::vector<Material>::iterator element = material_list.begin(); element != material_list.end(); element++)
	{
		D_list.push_back(element->generateD());
	}

	// cycle through all elements in the model
	for(std::vector<Element>::iterator element = element_list.begin(); element != element_list.end(); element++)
	{
		switch(element->type)
		{
			case Element::FE_TETRAHEDRON4:
			{
				symmetric_matrix<double, upper> k_elem(4*3,4*3);
				mapped_vector<double> f_elem(12);
				//TODO finish this
			}
			break;

			case Element::FE_HEXAHEDRON8:
			{
// shape function
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
				symmetric_matrix<double, upper> k_elem(24,24);
				mapped_vector<double> f_elem(24);
				matrix<double>	B(6,3*8);
				matrix<double>	Bt(3*8,6);
				matrix<double>	Jacobian(3,3), invJ(3,3);

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
				std::vector<std::pair<fem::point, double> > integration_points;
				double x[3], w[3];
				gauleg(x,w,3);
				for(int i = 0; i < 2; i++)
				{
					for(int j = 0; j < 2; j++)
					{
						for(int k = 0; k < 2; k++)
						{
							integration_points.push_back(std::pair<fem::point,double>(fem::point(x[i],x[j],x[k]), w[i]*w[j]*w[k]));
						}
					}
				}

				// cycle through the number of integration points
				k_elem.clear();
				for (std::vector<std::pair<fem::point,double> >::iterator i = integration_points.begin(); i != integration_points.end(); i++)
				{
					std::cout << "pos: [" << i->first.x() << "," << i->first.y() << "," << i->first.z() << "],\tweight: " << i->second << std::endl;

					// generate the jacobian
					Jacobian = J(i->first,*element);
					double detJ = det3by3(Jacobian);
					invJ = invert3by3(Jacobian,detJ);


					// cycle through the element's nodes to set up the B matrix
					B.clear();
					for(int n = 0; n < 8; n++)
					{
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
						B(0,3*n) = dNdx;
						B(1,3*n+1) = dNdy;
						B(2,3*n+2) = dNdz;
						B(3,3*n) = dNdy;	B(3,3*n+1) = dNdx;
						B(4,3*n) = dNdz;	B(4,3*n+2) = dNdx;
						B(5,3*n+1) = dNdz;	B(4,3*n+2) = dNdy;
					}
					Bt = trans(B);
					symmetric_matrix<double> D = D_list[element->material];

					matrix<double> temp;

					// and now, k_elem = Bt*D*B*detJ*i->second;
					std::cout << Bt << std::endl;
					std::cout << D << std::endl;

					temp = prod(Bt,D);
					temp = prod(temp,B);
					temp *= detJ*i->second;
					std::cout << temp << std::endl;

					//k_elem += temp;
				}
			}
			break;

			default:
			cerr << "Model::build_fem_structure: unsupported element" << element->type << endl;
			break;
		}
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
