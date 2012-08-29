#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <vector>
#include <string>
#include <Eigen/Core>

namespace fem
{


class Material {
	public:
		enum Type {
			MAT_LINEAR_ELASTIC = 0
		};

		std::string label;	// a label describing this material
		enum Type type;

		double E, nu;	// linear elastic material

		double fy;	// elastic limit

	public:
		/**
		Generates a constitutive matrix
		@return	a matrix type
		**/
		Eigen::Matrix<double,6,6> generateD();
};

typedef std::vector<Material>::size_type material_ref_t;

}

#endif
