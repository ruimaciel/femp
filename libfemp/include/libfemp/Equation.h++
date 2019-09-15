#ifndef FEMP_EQUATION_H
#define FEMP_EQUATION_H

#include <la/Matrix.h++>
#include <la/Vector.h++>

namespace fem {

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

} // namespace femp

#endif // FEMP_EQUATION_H
