#include <libfemp/loads/NodalLoad.h++>

namespace fem {

NodalLoad::NodalLoad()
{
}

NodalLoad::NodalLoad(const NodalLoad& copied)
{
    this->force = copied.force;
}

NodalLoad::~NodalLoad()
{
}

double
NodalLoad::x() const
{
    return force.x();
}

double
NodalLoad::y() const
{
    return force.y();
}

double
NodalLoad::z() const
{
    return force.z();
}

const Point3D&
NodalLoad::getForce() const
{
    return this->force;
}

} // namespace fem
