#ifndef MATERIAL_HPP
#define MATERIAL_HPP

// #include <QString>
#include <string>
#include <boost/numeric/ublas/symmetric.hpp>

namespace fem
{

class Material {
	public:
		enum Type {
			MAT_LINEAR_ELASTIC = 0
		};

		//QString label;	// a label describing this material
		std::string label;	// a label describing this material
		enum Type type;

		double E, nu;	// linear elastic material

		double fy;	// elastic limit

	public:
		Material();
		Material(const Material &);
		~Material();

		/**
		Generates a constitutive matrix
		@return	a matrix type
		**/
		boost::numeric::ublas::symmetric_matrix<double, boost::numeric::ublas::upper>  generateD();
};


}

#endif
