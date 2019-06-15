#ifndef FEMP_ELEMENTRESULTS_STRAINS_HPP
#define FEMP_ELEMENTRESULTS_STRAINS_HPP

namespace fem {

/**
Structure intended to store the different strain values calculated from an element's node
**/
template <typename Scalar>
struct Strains {
    Scalar e11;
    Scalar e22;
    Scalar e33;
    Scalar e12;
    Scalar e23;
    Scalar e13;

    void setZero() { e11 = e22 = e33 = e12 = e23 = e13 = 0; }
};

} // namespace fem

#endif
