#ifndef FEMP_MATERIAL_HPP
#define FEMP_MATERIAL_HPP

#include <vector>
#include <string>

#include <Eigen/Core>

namespace fem
{


/**
Class representing a linear elastic material
**/
class Material
{
public:
	std::string label;	// a label describing this material

	double E, nu;	// linear elastic material

	double fy;	// elastic limit

public:
	/**
	Generates a constitutive matrix
	@return	a matrix type
	**/
	Eigen::Matrix<double,6,6> generateD() const;
};


typedef std::vector<Material>::size_type material_ref_t;


}	// namespace fem

#endif