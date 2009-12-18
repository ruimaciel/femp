#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <QString>
#include <blitz/tinymat.h>


namespace fem
{

class Material {
	public:
		enum Type {
			MAT_LINEAR_ELASTIC = 0
		};

		QString label;	// a label describing this material
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
		blitz::TinyMatrix<double, 6, 6> generateD();
};


}

#endif
