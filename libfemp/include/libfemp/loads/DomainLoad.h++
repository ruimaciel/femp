#ifndef FEMP_DOMAIN_LOAD_HPP
#define FEMP_DOMAIN_LOAD_HPP

#include <libfemp/Point3D.h++>
#include <vector>

namespace fem {

class DomainLoad {
public:
    Point3D force; // force value for the entire element

public:
    DomainLoad();
    DomainLoad(const DomainLoad&);
    ~DomainLoad();

    /**
     * Returns the force
     */
    const Point3D& getForce() const;

    /**
     * Copy assignment operator
     */
    DomainLoad& operator=(DomainLoad const& copied);
};

} // namespace fem

#endif
