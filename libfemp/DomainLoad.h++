#ifndef FEMP_DOMAIN_LOAD_HPP
#define FEMP_DOMAIN_LOAD_HPP

#include <vector>
#include <libfemp/point.h++>
#include <libfemp/Element.h++>

namespace fem
{

class DomainLoad
{
public:
	point force;	// force value for the entire element

public:
	DomainLoad();
	DomainLoad(const DomainLoad &);
	~DomainLoad();
};

}
#endif
