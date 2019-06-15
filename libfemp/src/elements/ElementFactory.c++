#include <libfemp/elements/ElementFactory.h++>

#include <libfemp/FemException.h++>
#include <libfemp/Node.h++>
#include <libfemp/elements/all.h++>

/**
 * Factory function created to ease the transition to properly polymorphic element definitions
 **/
fem::BaseElement* getElement(fem::Element const& old_element)
{
    using namespace fem;
    BaseElement* new_element = nullptr;

    std::vector<node_ref_t> const& nodes = old_element.getNodeReferences();

    // sets the current element routines
    switch (old_element.type) {
    case Element::FE_TETRAHEDRON4:
        new_element = new Tetrahedron4();
        break;

    case Element::FE_TETRAHEDRON10:
        new_element = new Tetrahedron10();
        break;

    case Element::FE_HEXAHEDRON8:
        new_element = new Hexahedron8();
        break;

    case Element::FE_HEXAHEDRON20:
        new_element = new Hexahedron20();
        break;

    case Element::FE_HEXAHEDRON27:
        new_element = new Hexahedron27();
        break;

    case Element::FE_PRISM6:
        new_element = new Prism6();
        break;

    case Element::FE_PRISM15:
        new_element = new Prism15();
        break;

    case Element::FE_PRISM18:
        new_element = new Prism18();
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
