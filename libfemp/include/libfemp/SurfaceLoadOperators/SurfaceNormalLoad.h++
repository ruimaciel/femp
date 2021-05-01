#ifndef FEMP_SURFACELOADOPERATORS_SURFACENORMALLOAD_HPP
#define FEMP_SURFACELOADOPERATORS_SURFACENORMALLOAD_HPP

#include <libfemp/SurfaceLoadOperators/SurfaceLoadOperator.h++>

namespace fem {

/**
 * Defines a surface load which is normal to the surface
 */
class SurfaceNormalLoad
    : public SurfaceLoadOperator {
public:
    SurfaceNormalLoad();

    void setLoadMagnitude(float const& magnitude);

    void operator()(fem::SurfaceLoad& surface_load, fem::Model& model) override;

protected:
    float m_magnitude;
};

} // namespace fem

#endif
