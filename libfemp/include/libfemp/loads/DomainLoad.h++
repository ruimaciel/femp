#ifndef FEMP_DOMAIN_LOAD_HPP
#define FEMP_DOMAIN_LOAD_HPP

#include <vector>
#include <libfemp/Point3D.h++>

namespace fem
{

class DomainLoad
{
public:
	Point3D force;	// force value for the entire element

public:
	DomainLoad();
	DomainLoad(const DomainLoad &);
	~DomainLoad();


	/**
	 * returns the force
	 **/
	const Point3D & getForce() const;


	/**
	 * Copy assignment operator
	 **/
	DomainLoad operator=(DomainLoad const &copied);
};

}	// namespace fem

#endif
