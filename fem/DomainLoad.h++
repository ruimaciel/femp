#ifndef DOMAIN_LOAD_HPP
#define DOMAIN_LOAD_HPP

#include "point.h++"


namespace fem
{

class DomainLoad
{
	public:
		point force;

	public:
		DomainLoad();
		DomainLoad(const DomainLoad &);
		~DomainLoad();
};

}
#endif
