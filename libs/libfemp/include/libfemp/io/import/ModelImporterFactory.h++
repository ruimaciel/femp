#ifndef FEM_IO_IMPORT_IMPORTERFACTORY_H
#define FEM_IO_IMPORT_IMPORTERFACTORY_H

#include <libfemp/io/import/Parser.h++>
#include <memory>

namespace fem {

/**
 * @brief The ModelImporterFactory class provides the interface to instantiate
 * importers
 */
class ModelImporterFactory {
	public:
	/**
	 * @brief makeMeshParser factory method that generates a parser for
	 * Gmsh's MSH file format.
	 * @return
	 */
	static std::shared_ptr<Parser> makeMshParser();

	/**
	 * @brief makeJsonParser factory method that generates a parser for
	 * FEMP's JSON file format
	 * @return
	 */
	static std::shared_ptr<Parser> makeFemJsonParser();
};

}  // namespace fem

#endif	// FEM_IO_IMPORT_IMPORTERFACTORY_H
