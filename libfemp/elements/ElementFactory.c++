#include "ElementFactory.h++"

#include <libfemp/elements/all.h++>
#include <libfemp/Node.h++>
#include <libfemp/FemException.h++>


/**
 * Factory function created to ease the transition to properly polymorphic element definitions
 **/
template<typename Scalar>
fem::BaseElement<Scalar> * getElement(fem::Element const &old_element)
{
	using namespace fem;
	BaseElement<Scalar> * new_element = nullptr;

	std::vector<node_ref_t> const & nodes = old_element.nodes;

	// sets the current element routines
	switch(old_element.type)
	{
		case Element::FE_TETRAHEDRON4:
			new_element = new Tetrahedron4<Scalar>();
			break;

		case Element::FE_TETRAHEDRON10:
			new_element = new Tetrahedron10<Scalar>();
			break;

		case Element::FE_HEXAHEDRON8:
			new_element = new Hexahedron8<Scalar>();
			break;

		case Element::FE_HEXAHEDRON20:
			new_element = new Hexahedron20<Scalar>();
			break;

		case Element::FE_HEXAHEDRON27:
			new_element = new Hexahedron27<Scalar>();
			break;

		case Element::FE_PRISM6:
			new_element = new Prism6<Scalar>();
			break;

		case Element::FE_PRISM15:
			new_element = new Prism15<Scalar>();
			break;

		case Element::FE_PRISM18:
			new_element = new Prism18<Scalar>();
			break;

		default:
			// TODO throw exception
			throw FemException("unknown element type");
			return nullptr;
			break;
	}

	new_element->nodes = nodes;

	return new_element;
}


// template function explicit instantiation
template<> fem::BaseElement<float> * getElement<float>(fem::Element const &);
template<> fem::BaseElement<double> * getElement<double>(fem::Element const &);

