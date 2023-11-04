#include <io/import/FemJsonParser.hpp>
#include <io/import/MshParser.hpp>
#include <libfemp/SurfaceLoadOperators/SurfaceNormalLoad.hpp>
#include <libfemp/io/import/ModelImporterFactory.hpp>

namespace fem {

std::shared_ptr<Parser> ModelImporterFactory::makeMshParser() {
	// added SurfaceLoadOperator to help migrate to generic Model importers
	fem::SurfaceNormalLoad o;
	o.setLoadMagnitude(-1.0f);

	auto parser = std::make_shared<MshParser>();
	parser->setSurfaceLoadOperator(o);

	return parser;
}

std::shared_ptr<Parser> ModelImporterFactory::makeFemJsonParser() {
	return std::make_shared<FemJsonParser>();
}

}  // namespace fem
