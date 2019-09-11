#ifndef FEMP_SURFACE_HPP
#define FEMP_SURFACE_HPP

#include <boost/tuple/tuple.hpp>
#include <vector>

#include <libfemp/Element.h++>

namespace fem {

/**
 * Describes a surface belonging to at least one element
 */
class Surface {
public:
    struct ReferencedElement {
        size_t reference; // the reference to the element which shares this surface
        unsigned char surface; // the surface numbering.  In a hexahedron it can be [1-6]
        std::vector<size_t> element_local_reference; // a list of local references to the nodes in the element's local space
    };

public:
    /**
     * Sets this surface's properties
     * @param type	the type of surface
     * @param nodes	the nodes which define this surface
     * @return 	true if the number of nodes is compatible with the surface type, false otherwise
     */
    bool set(Element::Type& m_type, std::vector<size_t>& m_node_references);

    void pushElementReference(const size_t reference, const Element::Type& element_type, const unsigned char surface);

    /**
     * @return		true if it's an internal surface, false if it's an external surface
     */
    bool internal();
    bool external();

    Element::Type getType();

    /**
     * @return	true if the number of nodes is compatible with the surface type
     */
    bool compatible(const Element::Type& m_type, std::vector<size_t>& m_node_references);

    bool operator==(const Surface& other) const;

private:
    Element::Type m_type; // type of surface
    std::vector<size_t> m_node_references; // global references to the nodes which define this surface
    std::vector<ReferencedElement> m_elements; // stores 1 or 2 elements
};

}

#endif
