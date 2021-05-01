#ifndef FEMP_NODAL_DISPLACEMENT_HPP
#define FEMP_NODAL_DISPLACEMENT_HPP

#include <libfemp/Point3D.h++>

namespace fem {

class NodalDisplacement {
public:
    Point3D displacement;

public:
    NodalDisplacement();
    NodalDisplacement(const NodalDisplacement& copied);
    ~NodalDisplacement();
};

} // namespace fem

#endif
