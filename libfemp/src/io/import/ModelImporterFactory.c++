#include <libfemp/io/import/ModelImporterFactory.h++>

#include <libfemp/io/import/MshParser.h++>
#include <libfemp/io/import/FemJsonParser.h++>

#include <libfemp/SurfaceLoadOperators/SurfaceNormalLoad.h++>

namespace fem {

std::shared_ptr<Parser> ModelImporterFactory::makeMshParser()
{
    // added SurfaceLoadOperator to help migrate to generic Model importers
    fem::SurfaceNormalLoad o;
    o.setLoadMagnitude(-1.0f);

    auto parser = std::make_shared<MshParser>();
    parser->setSurfaceLoadOperator(o);

    return parser;
}

std::shared_ptr<Parser> ModelImporterFactory::makeFemJsonParser()
{
    return std::make_shared<FemJsonParser>();
}

} // namespace fem
