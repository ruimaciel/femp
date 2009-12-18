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

	// model is OK.

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


}
