#ifndef FEMP_DOMAIN_LOAD_HPP
#define FEMP_DOMAIN_LOAD_HPP

#include <vector>
#include <libfemp/Point.h++>
#include <libfemp/Element.h++>

namespace fem
{

class DomainLoad
{
public:
	Point force;	// force value for the entire element

public:
	DomainLoad();
	DomainLoad(const DomainLoad &);
	~DomainLoad();
};

}	// namespace fem

#endif
