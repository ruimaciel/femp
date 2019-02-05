#ifndef FEMP_EQUATION_H
#define FEMP_EQUATION_H

#include <libla/Matrix.h++>
#include <libla/Vector.h++>

namespace fem
{

class Equation
{
public:
	Equation();

	lalib::Matrix<double, lalib::SparseDOK> K;
	lalib::Vector<double> f;
	lalib::Vector<double> d;
};

}	// namespace femp

#endif // EQUATION_H
