#include "Surface.h++"


namespace fem
{


bool Surface::set(Element::Type &type, std::vector<size_t> &nodes)
{
	if(!compatible(type,nodes))
		return false;

	this->type = type;
	this->nodes = nodes;

	return true;
}


void Surface::pushElementReference(const size_t reference, const unsigned char surface)
{
	ReferencedElement re;
	re.reference = reference;
	re.surface = surface;
	this->elements.push_back(re);
}


bool Surface::compatible(const Element::Type &type, std::vector<size_t> &nodes)
{
	switch(type)
	{
		case Element::FE_TRIANGLE3:
			if(nodes.size() != 3)
				return false;
			break;

		case Element::FE_TRIANGLE6:
			if(nodes.size() != 6)
				return false;
			break;

		case Element::FE_TRIANGLE10:
			if(nodes.size() != 10)
				return false;
			break;

		case Element::FE_TRIANGLE15:
			if(nodes.size() != 15)
				return false;
			break;

		case Element::FE_TRIANGLE21:
			if(nodes.size() != 21)
				return false;
			break;

		case Element::FE_QUADRANGLE4:
			if(nodes.size() != 4)
				return false;
			break;

		case Element::FE_QUADRANGLE8:
			if(nodes.size() != 8)
				return false;
			break;


		case Element::FE_QUADRANGLE9:
			if(nodes.size() != 9)
				return false;
			break;

		default:
			// this part should never be reached
			return false;
	}

	return true;
}


bool Surface::operator==(const Surface &other) const
{
	using namespace std;

	if(this->type != other.type)
		return false;

	// test if both surfaces contain the same nodes
	vector<size_t>::const_iterator i, j;
	for(i = this->nodes.begin(); i != this->nodes.end(); i++)
	{
		for(j = other.nodes.begin(); j != other.nodes.end(); j++)
		{
			if(*j == *i)
				break;
		}

		if(j == other.nodes.end())
			return false;
	}

	return true;
}


}
