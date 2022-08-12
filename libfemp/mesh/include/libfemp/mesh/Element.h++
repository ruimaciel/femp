#ifndef FEM_MESH_ELEMENT_H
#define FEM_MESH_ELEMENT_H

#include <libfemp/mesh/ElementVisitor.h++>
#include <memory>
#include <vector>

namespace fem {
namespace mesh {

class Element {
   public:
	Element(size_t element_id);
	virtual ~Element() = default;

	virtual size_t id() const;

	virtual int getNodeAmount() const = 0;

	virtual void accept(ElementVisitor& visitor) = 0;

   private:
	size_t m_element_id;
};

}  // namespace mesh
}  // namespace fem

#endif	// FEM_MESH_ELEMENT_H
