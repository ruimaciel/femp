#include "Surface.h++"

#include <assert.h>


namespace fem
{


bool
Surface::set(Element::Type &type, std::vector<size_t> &nodes)
{
	if(!compatible(type,nodes))
		return false;

	this->m_type = type;
	this->m_node_references = nodes;

	return true;
}


void
Surface::pushElementReference(const size_t reference, const Element::Type &element_type, const unsigned char surface)
{
	ReferencedElement re;
	re.reference = reference;
	re.surface = surface;
	switch(element_type)
	{
		case Element::FE_HEXAHEDRON8:
			assert(surface < 6);
			re.element_local_reference.resize(4);
			switch(surface)
			{
				case 0:
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 0;
					re.element_local_reference[2] = 3;
					re.element_local_reference[3] = 2;
					break;
				case 1:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 4;
					re.element_local_reference[2] = 7;
					re.element_local_reference[3] = 3;
					break;
				case 2:
					// face 3:
					re.element_local_reference[0] = 4;
					re.element_local_reference[1] = 5;
					re.element_local_reference[2] = 6;
					re.element_local_reference[3] = 7;
					break;
				case 3:
					// face 4:
					re.element_local_reference[0] = 5;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 2;
					re.element_local_reference[3] = 6;
					break;
				case 4:
					// face 5:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 4;
					break;
				case 5:
					// face 6:
					re.element_local_reference[0] = 2;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 7;
					re.element_local_reference[3] = 6;
					break;
			}

			break;

		case Element::FE_HEXAHEDRON20:
			assert(surface < 6);
			re.element_local_reference.resize(8);
			switch(surface)
			{
				case 0:
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 0;
					re.element_local_reference[2] = 3;
					re.element_local_reference[3] = 2;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 9;
					re.element_local_reference[6] = 13;
					re.element_local_reference[7] = 11;
					break;
				case 1:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 4;
					re.element_local_reference[2] = 7;
					re.element_local_reference[3] = 3;
					re.element_local_reference[4] = 10;
					re.element_local_reference[5] = 17;
					re.element_local_reference[6] = 15;
					re.element_local_reference[7] = 9;
					break;
				case 2:
					// face 3:
					re.element_local_reference[0] = 4;
					re.element_local_reference[1] = 5;
					re.element_local_reference[2] = 6;
					re.element_local_reference[3] = 7;
					re.element_local_reference[4] = 16;
					re.element_local_reference[5] = 18;
					re.element_local_reference[6] = 19;
					re.element_local_reference[7] = 17;
					break;
				case 3:
					// face 4:
					re.element_local_reference[0] = 5;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 2;
					re.element_local_reference[3] = 6;
					re.element_local_reference[4] = 12;
					re.element_local_reference[5] = 11;
					re.element_local_reference[6] = 14;
					re.element_local_reference[7] = 18;
					break;
				case 4:
					// face 5:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 4;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 12;
					re.element_local_reference[6] = 16;
					re.element_local_reference[7] = 10;
					break;
				case 5:
					// face 6:
					re.element_local_reference[0] = 2;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 7;
					re.element_local_reference[3] = 6;
					re.element_local_reference[4] = 13;
					re.element_local_reference[5] = 15;
					re.element_local_reference[6] = 19;
					re.element_local_reference[7] = 14;
					break;
			}
			break;

		case Element::FE_HEXAHEDRON27:
			assert(surface < 6);
			re.element_local_reference.resize(9);
			switch(surface)
			{
				case 0:
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 0;
					re.element_local_reference[2] = 3;
					re.element_local_reference[3] = 2;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 9;
					re.element_local_reference[6] = 13;
					re.element_local_reference[7] = 11;
					re.element_local_reference[8] = 20;
					break;
				case 1:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 4;
					re.element_local_reference[2] = 7;
					re.element_local_reference[3] = 3;
					re.element_local_reference[4] = 10;
					re.element_local_reference[5] = 17;
					re.element_local_reference[6] = 15;
					re.element_local_reference[7] = 9;
					re.element_local_reference[8] = 22;
					break;
				case 2:
					// face 3:
					re.element_local_reference[0] = 4;
					re.element_local_reference[1] = 5;
					re.element_local_reference[2] = 6;
					re.element_local_reference[3] = 7;
					re.element_local_reference[4] = 16;
					re.element_local_reference[5] = 18;
					re.element_local_reference[6] = 19;
					re.element_local_reference[7] = 17;
					re.element_local_reference[8] = 25;
					break;
				case 3:
					// face 4:
					re.element_local_reference[0] = 5;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 2;
					re.element_local_reference[3] = 6;
					re.element_local_reference[4] = 12;
					re.element_local_reference[5] = 11;
					re.element_local_reference[6] = 14;
					re.element_local_reference[7] = 18;
					re.element_local_reference[8] = 23;
					break;
				case 4:
					// face 5:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 4;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 12;
					re.element_local_reference[6] = 16;
					re.element_local_reference[7] = 10;
					re.element_local_reference[8] = 21;
					break;
				case 5:
					// face 6:
					re.element_local_reference[0] = 2;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 7;
					re.element_local_reference[3] = 6;
					re.element_local_reference[4] = 13;
					re.element_local_reference[5] = 15;
					re.element_local_reference[6] = 19;
					re.element_local_reference[7] = 14;
					re.element_local_reference[8] = 24;
					break;
			}
			break;

		case Element::FE_TETRAHEDRON4:
			assert(surface < 4);
			re.element_local_reference.resize(3);
			switch(surface)
			{
				case 0:
					// face 1:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 1;
					break;

				case 1:
					// face 2:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 2;
					break;

				case 2:
					// face 3:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 3;
					break;

				case 3:
					// face 4:
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 3;
					break;
			}
			break;

		case Element::FE_TETRAHEDRON10:
			assert(surface < 4);
			re.element_local_reference.resize(6);
			switch(surface)
			{
				case 0:
					// face 1:
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 0;
					re.element_local_reference[2] = 2;
					re.element_local_reference[3] = 4;
					re.element_local_reference[4] = 6;
					re.element_local_reference[5] = 5;
					break;

				case 1:
					// face 2:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 2;
					re.element_local_reference[3] = 7;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 6;
					break;
				case 2:
					// face 3:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 3;
					re.element_local_reference[3] = 4;
					re.element_local_reference[4] = 9;
					re.element_local_reference[5] = 7;
					break;
				case 3:
					// face 4:
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 3;
					re.element_local_reference[3] = 5;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 9;
					break;
			}
			break;

		case Element::FE_PRISM6:
			assert(surface < 5);
			re.element_local_reference.resize(4);
			switch(surface)
			{
				case 0:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 4;
					re.element_local_reference[3] = 3;
					break;
				case 1:

					// face 2: quadrangle with the coplanar YY
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 2;
					break;

				case 2:
					// face 3: quadrangle with the diagonal
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 4;
					break;

				case 3:
					/*
					   prism faces: 3 quadrangles, 2 triangles
					 */
					// face 5: near triangle
					re.element_local_reference.resize(6);
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 1;
					break;

				case 4:
					// face 6: far triangle
					re.element_local_reference[0] = 3;
					re.element_local_reference[1] = 4;
					re.element_local_reference[2] = 5;
					break;
			}
			break;

		case Element::FE_PRISM15:
			assert(surface < 5);
			re.element_local_reference.resize(8);
			switch(surface)
			{
				case 0:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 4;
					re.element_local_reference[3] = 3;
					re.element_local_reference[4] = 6;
					re.element_local_reference[5] = 10;
					re.element_local_reference[6] = 12;
					re.element_local_reference[7] = 8;
					break;
				case 1:

					// face 2: quadrangle with the coplanar YY
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 2;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 13;
					re.element_local_reference[6] = 11;
					re.element_local_reference[7] = 7;
					break;

				case 2:
					// face 3: quadrangle with the diagonal
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 4;
					re.element_local_reference[4] = 9;
					re.element_local_reference[5] = 11;
					re.element_local_reference[6] = 14;
					re.element_local_reference[7] = 10;
					break;

				case 3:
					/*
					   prism faces: 3 quadrangles, 2 triangles
					 */
					// face 5: near triangle
					re.element_local_reference.resize(6);
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 1;
					re.element_local_reference[3] = 7;
					re.element_local_reference[4] = 9;
					re.element_local_reference[5] = 6;
					break;

				case 4:
					// face 6: far triangle
					re.element_local_reference[0] = 3;
					re.element_local_reference[1] = 4;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 12;
					re.element_local_reference[4] = 14;
					re.element_local_reference[5] = 13;
					break;
			}
			break;

		case Element::FE_PRISM18:
			assert(surface < 5);
			re.element_local_reference.resize(9);
			switch(surface)
			{
				case 0:
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 1;
					re.element_local_reference[2] = 4;
					re.element_local_reference[3] = 3;
					re.element_local_reference[4] = 6;
					re.element_local_reference[5] = 10;
					re.element_local_reference[6] = 12;
					re.element_local_reference[7] = 8;
					re.element_local_reference[8] = 15;
					break;
				case 1:

					// face 2: quadrangle with the coplanar YY
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 3;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 2;
					re.element_local_reference[4] = 8;
					re.element_local_reference[5] = 13;
					re.element_local_reference[6] = 11;
					re.element_local_reference[7] = 7;
					re.element_local_reference[8] = 16;
					break;

				case 2:
					// face 3: quadrangle with the diagonal
					re.element_local_reference[0] = 1;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 4;
					re.element_local_reference[4] = 9;
					re.element_local_reference[5] = 11;
					re.element_local_reference[6] = 14;
					re.element_local_reference[7] = 10;
					re.element_local_reference[8] = 17;
					break;

				case 3:
					/*
					   prism faces: 3 quadrangles, 2 triangles
					 */
					// face 5: near triangle
					re.element_local_reference.resize(6);
					re.element_local_reference[0] = 0;
					re.element_local_reference[1] = 2;
					re.element_local_reference[2] = 1;
					re.element_local_reference[3] = 7;
					re.element_local_reference[4] = 9;
					re.element_local_reference[5] = 6;
					break;

				case 4:
					// face 6: far triangle
					re.element_local_reference[0] = 3;
					re.element_local_reference[1] = 4;
					re.element_local_reference[2] = 5;
					re.element_local_reference[3] = 12;
					re.element_local_reference[4] = 14;
					re.element_local_reference[5] = 13;
					break;
			}
			break;

		default:
			// this part should never be reached
			assert(false);
			break;
	}
	this->m_elements.push_back(re);
}


bool
Surface::internal()
{
	return m_elements.size() > 1? true: false;
}


bool
Surface::external()
{
	return !internal();
}


Element::Type
Surface::getType()
{
	return m_type;
}


bool
Surface::compatible(const Element::Type &type, std::vector<size_t> &nodes)
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


bool
Surface::operator==(const Surface &other) const
{
	using namespace std;

	if(this->m_type != other.m_type)
		return false;

	// test if both surfaces contain the same nodes
	vector<size_t>::const_iterator i, j;
	for(i = this->m_node_references.begin(); i != this->m_node_references.end(); i++)
	{
		for(j = other.m_node_references.begin(); j != other.m_node_references.end(); j++)
		{
			if(*j == *i)
				break;
		}

		if(j == other.m_node_references.end())
			return false;
	}

	return true;
}


}
