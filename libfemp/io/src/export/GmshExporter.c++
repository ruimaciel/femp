#include "GmshExporter.h++"

#include <fstream>
#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/ElementVisitor.h++>
#include <libfemp/mesh/Node.h++>
#include <libfemp/mesh/elements/Hexahedron20.h++>
#include <libfemp/mesh/elements/Hexahedron27.h++>
#include <libfemp/mesh/elements/Hexahedron8.h++>
#include <libfemp/mesh/elements/Prism15.h++>
#include <libfemp/mesh/elements/Prism18.h++>
#include <libfemp/mesh/elements/Prism6.h++>
#include <libfemp/mesh/elements/Tetrahedron10.h++>
#include <libfemp/mesh/elements/Tetrahedron20.h++>
#include <libfemp/mesh/elements/Tetrahedron35.h++>
#include <libfemp/mesh/elements/Tetrahedron4.h++>
#include <libfemp/mesh/elements/Tetrahedron56.h++>

namespace fem {
namespace io {

class GmshElementExporterVisitor : public fem::mesh::ElementVisitor {
   public:
	GmshElementExporterVisitor(std::ofstream& mesh_file) : m_mesh_file_stream(mesh_file) {}

	void visit(mesh::Hexahedron8& element) {
		m_mesh_file_stream << 5;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Hexahedron20& element) {
		m_mesh_file_stream << 17;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Hexahedron27& element) {
		m_mesh_file_stream << 12;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Prism6& element) {
		m_mesh_file_stream << 6;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Prism15& element) {
		m_mesh_file_stream << 18;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Prism18& element) {
		m_mesh_file_stream << 13;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Tetrahedron4& element) {
		m_mesh_file_stream << 4;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Tetrahedron10& element) {
		m_mesh_file_stream << 11;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Tetrahedron20& element) {
		m_mesh_file_stream << 17;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Tetrahedron35& element) {
		m_mesh_file_stream << 35;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

	void visit(mesh::Tetrahedron56& element) {
		m_mesh_file_stream << 31;
		m_mesh_file_stream << element.id();
		for (std::shared_ptr<fem::mesh::Node> node : element.getNodes()) {
			m_mesh_file_stream << " " << node->id();
		}
		m_mesh_file_stream << "\n";
	}

   private:
	std::ofstream& m_mesh_file_stream;
};

GmshExporter::GmshExporter() {}

void GmshExporter::execute(std::ofstream& mesh_file, const mesh::MeshModel& mesh_model) {
	// export header
	mesh_file << "$MeshFormat\n";
	mesh_file << "2.2 0 8\n";  // hardcoded to simplify logic
	mesh_file << "$EndMeshFormat\n";

	// export nodes
	mesh_file << "$Nodes\n";
	mesh_file << mesh_model.getNodes().size() << "\n";
	for (std::shared_ptr<fem::mesh::Node> node : mesh_model.getNodes()) {
		mesh_file << node->id() << node->x() << " " << node->y() << " " << node->y() << "\n";
	}
	mesh_file << "$EndNodes\n";

	// export elements
	mesh_file << "$Elements\n";
	mesh_file << mesh_model.getNodes().size() << "\n";
	GmshElementExporterVisitor elementExporter(mesh_file);
	for (std::shared_ptr<fem::mesh::Element> element : mesh_model.getElements()) {
		element->accept(elementExporter);
	}
	mesh_file << "$EndElements\n";
}

}  // namespace io
}  // namespace fem
