#ifndef FEMP_ELEMENTRESULTS_STRESSES_HPP
#define FEMP_ELEMENTRESULTS_STRESSES_HPP

namespace fem {

/**
 * Structure intended to store the different stress values calculated from an element's node
 */
template <typename Scalar>
struct Stresses {
    Scalar s11;
    Scalar s22;
    Scalar s33;
    Scalar s12;
    Scalar s23;
    Scalar s13;

    void setZero() { s11 = s22 = s33 = s12 = s23 = s13 = 0; }
};

} // namespace fem

#endif
