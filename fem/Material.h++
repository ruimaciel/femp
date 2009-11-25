#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <QString>


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

	public:
		Material();
		~Material();
};


}

#endif
