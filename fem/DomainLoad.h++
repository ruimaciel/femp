#ifndef DOMAIN_LOAD_HPP
#define DOMAIN_LOAD_HPP

#include <vector>
#include "point.h++"
#include "Element.h++"

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
