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
		std::vector<point> force_shape;	// force values on each of the element's nodes, which are interpolated across the domain

	public:
		DomainLoad();
		DomainLoad(const DomainLoad &);
		~DomainLoad();
};

}
#endif
