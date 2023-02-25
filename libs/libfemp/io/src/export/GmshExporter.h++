#ifndef FEM_IO_GMSHEXPORTER_H
#define FEM_IO_GMSHEXPORTER_H

#include <libfemp/mesh/MeshModel.h++>
#include <ostream>

namespace fem {
namespace io {

class GmshExporter {
	public:
	GmshExporter();

	void execute(std::ofstream& mesh_file, const fem::mesh::MeshModel& mesh_model);
};

}  // namespace io
}  // namespace fem

#endif	// FEM_IO_GMSHEXPORTER_H
