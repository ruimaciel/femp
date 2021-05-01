#ifndef FEM_MESH_ELEMENT_H
#define FEM_MESH_ELEMENT_H

#include <memory>
#include <vector>

#include <libfemp/mesh/ElementVisitor.h++>

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

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_ELEMENT_H
