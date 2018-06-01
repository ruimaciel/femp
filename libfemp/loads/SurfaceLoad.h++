#ifndef FEMP_LOADS_SURFACE_LOAD_HPP
#define FEMP_LOADS_SURFACE_LOAD_HPP

#include <vector>

#include <Eigen/Core>

#include <libfemp/Element.h++>
#include <libfemp/Node.h++>
#include <libfemp/Point3D.h++>
#include <libfemp/elements/BaseElement.h++>	// added to help transition to properly polymorphic
#include <libfemp/quadrature_rules/SurfaceRule.h++>



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
	std::vector<fem::Point3D>	surface_forces;	// forces acting in each node, used to interpolate the surface load

public:
	virtual ~SurfaceLoad() {}

	/**
	 * Returns a vector with the reference IDs of all nodes associated with the element
	 **/
	virtual std::vector<node_ref_t> getNodeReferences() const;

	virtual int getNodeAmount() const;

	virtual unsigned int getDofAmount() const;

	/**
	 * Returns the force vector
	 * @param model an object of type fem::Model
	 **/
	virtual Eigen::VectorXd getForceVector(Model &model) const;

	/**
	 * @brief makeSurfaceLoad helper factory method added to migrate surface loads to a properly polymorphic implementation
	 * @param element
	 * @return
	 */
	static SurfaceLoad * makeSurfaceLoad(const Element * element);

public:
	// TODO convert to pure virtual interface after migrating to polymorphic loads
	virtual std::vector<fem::Point3D> getLocalCoordinates() const = 0;
	virtual std::vector<double> getN(const Point3D &p) const = 0;
	virtual std::vector<double> getdNdcsi(const Point3D &p) const = 0;
	virtual std::vector<double> getdNdeta(const Point3D &p) const = 0;
	virtual std::vector<quadrature::SurfaceRule::Point> getDomainQuadratureRule() const = 0;
};

}	// namespace fem

#endif
