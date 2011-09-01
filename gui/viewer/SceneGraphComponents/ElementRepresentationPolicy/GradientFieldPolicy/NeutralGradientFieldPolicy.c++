#include "NeutralGradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

NeutralGradientFieldPolicy::NeutralGradientFieldPolicy()
{
}



void 
NeutralGradientFieldPolicy::calculateGradientValues (fem::Element &element)
{
	m_gradient_value.clear();
	switch(element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			m_gradient_value.resize(4);
			break;

		case fem::Element::FE_TETRAHEDRON10:
			m_gradient_value.resize(10);
			break;

		case fem::Element::FE_HEXAHEDRON8:
			m_gradient_value.resize(8);
			break;

		case fem::Element::FE_HEXAHEDRON20:
			m_gradient_value.resize(20);
			break;

		case fem::Element::FE_HEXAHEDRON27:
			m_gradient_value.resize(27);
			break;

		case fem::Element::FE_PRISM6:
			m_gradient_value.resize(6);
			break;

		case fem::Element::FE_PRISM15:
			m_gradient_value.resize(15);
			break;

		case fem::Element::FE_PRISM18:
			m_gradient_value.resize(18);
			break;

		default:
			throw SceneGraphException("unknown element type request");
			return;
			break;
	}
}


