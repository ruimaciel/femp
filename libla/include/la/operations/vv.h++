#ifndef LALIB_VECTOR_VECTOR_OPERATIONS_HPP
#define LALIB_VECTOR_VECTOR_OPERATIONS_HPP

#include "../Vector.h++"

#include <math.h>

namespace lalib {

template <typename scalar, template <typename> class VectorStoragePolicy>
Vector<scalar, VectorStoragePolicy> operator+(Vector<scalar, VectorStoragePolicy> v1, Vector<scalar, VectorStoragePolicy> v2)
{
    assert(v1.size() == v2.size());

    Vector<scalar, VectorStoragePolicy> v_out(v1.size());

    for (size_t i = 0; i < v_out.size(); i++) {
        v_out(i) = v1.value(i) + v2.value(i);
    }

    return v_out;
}

template <typename scalar, template <typename> class VectorStoragePolicy>
Vector<scalar, VectorStoragePolicy> operator-(Vector<scalar, VectorStoragePolicy> v1, Vector<scalar, VectorStoragePolicy> v2)
{
    assert(v1.size() == v2.size());

    Vector<scalar, VectorStoragePolicy> v_out(v1.size());

    for (size_t i = 0; i < v_out.size(); i++) {
        v_out(i) = v1.value(i) - v2.value(i);
    }

    return v_out;
}

template <typename scalar, template <typename> class VectorStoragePolicy>
Vector<scalar, VectorStoragePolicy> operator*(scalar alpha, Vector<scalar, VectorStoragePolicy> v)
{
    Vector<scalar, VectorStoragePolicy> v_out(v.size());

    for (size_t i = 0; i < v_out.size(); i++) {
        v_out(i) = alpha * v.value(i);
    }

    return v_out;
}

/**
v1 += alpha*v2
**/
template <typename scalar, template <typename> class VectorStoragePolicy>
void Axpy(Vector<scalar, VectorStoragePolicy>& v1, scalar alpha, Vector<scalar, VectorStoragePolicy>& v2)
{
    assert(v1.size() == v2.size());

    for (size_t i = 0; i < v1.size(); i++) {
        v1(i) += alpha * v2.value(i);
    }
}

/**
The default dot product operator
@return a scalar value
**/
template <typename scalar, template <typename> class VectorStoragePolicy>
scalar dot(Vector<scalar, VectorStoragePolicy>& v1, Vector<scalar, VectorStoragePolicy>& v2)
{
    assert(v1.size() == v2.size());

    scalar d = v1.value(0) * v2.value(0);

    for (size_t i = 1; i < v1.size(); i++) {
        d += v1.value(i) * v2.value(i);
    }

    return d;
}

template <typename scalar, template <typename> class VectorStoragePolicy>
scalar normL2(Vector<scalar, VectorStoragePolicy>& v)
{
    scalar norm = v.value(0) * v.value(0);
    for (size_t i = 1; i < v.size(); i++) {
        norm += v.value(i) * v.value(i);
    }

    return sqrt(norm);
}

template <typename scalar, template <typename> class VectorStoragePolicy>
scalar normLinf(Vector<scalar, VectorStoragePolicy>& v)
{
    scalar norm = v.value(0);
    for (size_t i = 1; i < v.size(); i++) {
        if (norm < v.value(i))
            norm = v.value(i);
    }

    return norm;
}
}

#endif
