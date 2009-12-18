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

	// perform sanity checks on the model
	if(element_list.empty() )
		return ERR_NO_ELEMENTS;

	// at this point the model is considered to be OK.

	//build a list of constitutive matrices
	vector<blitz::TinyMatrix<double, 6, 6> > D_list;
	for(vector<Material>::iterator it = material_list.begin(); it != material_list.end(); it++)
	{
		D_list.push_back(it->generateD());
	}

	// cycle through all elements in the model
	for(std::vector<Element>::iterator it = element_list.begin(); it != element_list.end(); it++)
	{
		switch(it->type)
		{
			case Element::FE_TETRAHEDRON4:
			{
				blitz::TinyMatrix<double,12, 12> k_elem;
				blitz::TinyVector<double,12> f_elem;
			}
			break;

			/*
			   case Element::FE_HEXAHEDRON8:
			   break;
			 */

			default:
			cerr << "Model::build_fem_structure: unsupported element" << it->type << endl;
			break;
		}
	}

	// fem equation is set.
	return ERR_OK;
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
	double z1,z,xm,pp,p3,p2,p1;
	m=(n+1)/2; /* The roots are symmetric, so we only find half of them. */
	for (i=1;i<=m;i++) { /* Loop over the desired roots. */
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
		x[i]=-z;      /* Scale the root to the desired interval, */
		x[n+1-i]=z;  /* and put in its symmetric counterpart.   */
		w[i]=2.0/((1.0-z*z)*pp*pp); /* Compute the weight             */
		w[n+1-i]=w[i];                 /* and its symmetric counterpart. */
	}
}

}
