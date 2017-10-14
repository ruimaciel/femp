#ifndef FEMP_LOADS_SURFACE_LOAD_HPP
#define FEMP_LOADS_SURFACE_LOAD_HPP

#include <vector>

#include <Eigen/Core>

#include <libfemp/Element.h++>
#include <libfemp/Node.h++>
#include <libfemp/Point.h++>



namespace fem
{


class Model;	// forward declaration

/**
 * Represents a pressure applied on a surface
 **/
class SurfaceLoad
	: public Element
{
public:
	std::vector<fem::Point>	surface_forces;	// forces acting in each node, used to interpolate the surface load

public:
	SurfaceLoad();
	virtual ~SurfaceLoad() {};

	/**
	 * Returns a vector with the reference IDs of all nodes associated with the element
	 **/
	virtual std::vector<node_ref_t> getNodeReferences() const;


	/**
	 * Returns the force vector
	 * @param model an object of type fem::Model
	 **/
	virtual Eigen::VectorXd getForceVector(Model &model) const;
	
};

}	// namespace fem

#endif
