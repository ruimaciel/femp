#ifndef FEMP_RESULTSRANGES_HPP
#define FEMP_RESULTSRANGES_HPP

namespace fem {

/**
 * Convenience structure to store the representation ranges for all quantities which are rendered
 */
template <typename Scalar>
struct ResultsRanges {
    ResultsRanges();

    Scalar max_strain11;
    Scalar max_strain22;
    Scalar max_strain33;
    Scalar max_strain12;
    Scalar max_strain23;
    Scalar max_strain13;
    Scalar min_strain11;
    Scalar min_strain22;
    Scalar min_strain33;
    Scalar min_strain12;
    Scalar min_strain23;
    Scalar min_strain13;

    Scalar max_stress11;
    Scalar max_stress22;
    Scalar max_stress33;
    Scalar max_stress12;
    Scalar max_stress23;
    Scalar max_stress13;
    Scalar min_stress11;
    Scalar min_stress22;
    Scalar min_stress33;
    Scalar min_stress12;
    Scalar min_stress23;
    Scalar min_stress13;

    Scalar max_von_mises;
    Scalar min_von_mises;

    Scalar max_tension; // used by tension fields
    Scalar max_compression; // used by tension fields

    void setZero();
};

template <typename Scalar>
ResultsRanges<Scalar>::ResultsRanges()
{
    this->setZero();
}

template <typename Scalar>
void ResultsRanges<Scalar>::setZero()
{
    max_strain11 = 0;
    max_strain22 = 0;
    max_strain33 = 0;
    max_strain12 = 0;
    max_strain23 = 0;
    max_strain13 = 0;
    min_strain11 = 0;
    min_strain22 = 0;
    min_strain33 = 0;
    min_strain12 = 0;
    min_strain23 = 0;
    min_strain13 = 0;
    max_stress11 = 0;
    max_stress22 = 0;
    max_stress33 = 0;
    max_stress12 = 0;
    max_stress23 = 0;
    max_stress13 = 0;
    min_stress11 = 0;
    min_stress22 = 0;
    min_stress33 = 0;
    min_stress12 = 0;
    min_stress23 = 0;
    min_stress13 = 0;
    max_von_mises = 0;
    min_von_mises = 0;

    max_tension = 0;
    max_compression = 0;
}

} // namespace fem

#endif
