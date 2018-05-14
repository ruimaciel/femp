#ifndef FEMP_QUADRANGLE_FAMILY_HPP
#define FEMP_QUADRANGLE_FAMILY_HPP


#include <memory>

#include "../elements/BaseElement.h++"
#include <libfemp/quadrature_rules/Quadrangle.h++>


namespace fem
{

class QuadrangleFamily
		: public BaseElement
{
public:
	int stiffness_degree;	// Quadrature rule degree to integrate stiffness matrices
	int domain_degree;	// Quadrature rule degree to integrate domain loads

	std::unique_ptr<quadrature::QuadrangleRule>	m_stiffness_quadrature_rule;	// quadrature rule for stiffness calculations
	std::unique_ptr<quadrature::QuadrangleRule>	m_domain_quadrature_rule;	// quadrature rule for domain calculations

public:
	QuadrangleFamily();

	enum BaseElement::ElementFamily family() const;

	virtual int getNodeAmount() const = 0;

	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const	{ return 3*this->getNodeAmount(); }

	/**
	Returns a list of quadrature rules
	**/
	std::vector<boost::tuple<fem::Point3D, double> > getStiffnessQuadratureRule();
	std::vector<boost::tuple<fem::Point3D, double> > getDomainQuadratureRule();

public:	//TODO this is a transistion interface: to be implemented in SurfaceLoad
	virtual std::vector<double> getN(const Point3D &p) = 0;
	virtual std::vector<double> getdNdcsi(const Point3D &p) = 0;
	virtual std::vector<double> getdNdeta(const Point3D &p) = 0;

protected:
	void generateQuadratureData();
};


}

#endif
