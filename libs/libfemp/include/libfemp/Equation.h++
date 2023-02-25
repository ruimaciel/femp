#ifndef FEMP_EQUATION_HPP
#define FEMP_EQUATION_HPP

// la includes
#include <la/Matrix.h++>
#include <la/Vector.h++>

// std includes
#include <stddef.h>

namespace fem {

/**
 * Represents a static analysis equation
 **/
class Equation {
	public:
	Equation();

	lalib::Matrix<double, lalib::SparseDOK> K;
	lalib::Vector<double> f;
	lalib::Vector<double> d;

	public:
	size_t size() const;
	void setProblemSize(size_t size);
};

}  // namespace fem

#endif	// FEMP_EQUATION_H
