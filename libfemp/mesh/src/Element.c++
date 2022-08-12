#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

Element::Element(size_t element_id) : m_element_id(element_id) {}

size_t Element::id() const { return this->m_element_id; }

}  // namespace mesh
}  // namespace fem
