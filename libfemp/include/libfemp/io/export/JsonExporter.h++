#ifndef FEM_IO_JSONEXPORTER_H
#define FEM_IO_JSONEXPORTER_H

#include <fstream>

#include <libfemp/Model.h++>

/**
 * @brief The JsonExporter class exports femp models to a JSON format
 */
class JsonExporter {
public:
    void output(std::ostream& out, const fem::Model& model);
};

#endif // FEM_IO_JSONEXPORTER_H
