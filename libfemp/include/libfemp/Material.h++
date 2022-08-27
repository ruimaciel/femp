#ifndef FEMP_MATERIAL_HPP
#define FEMP_MATERIAL_HPP

#include <string>
#include <vector>

namespace fem {

/**
 * Class representing a linear elastic material
 */
class Material {
	public:
	Material(std::string m_label, double youngsModulus, double poissonRatio);

	std::string getLabel() const;
	double getYoungsModulus() const;
	double getPoissonRatio() const;

	private:
	std::string m_label;  // a label describing this material

	double m_E;	  // Young's modulus
	double m_nu;  // Poisson ratio
};

using material_ref_t = std::vector<Material>::size_type;

}  // namespace fem

#endif
