#ifndef LALIB_VECTOR_STORAGE_POLICY_DENSE_HPP
#define LALIB_VECTOR_STORAGE_POLICY_DENSE_HPP

#include <assert.h>
#include <iostream> // debug only
#include <vector>

namespace lalib {

/**
DenseVector: a storage policy class intended to implement the interfaces specific to the dense, dynamically resizeable vector to be used in the Vector host class.
**/
template <typename scalar>
class DenseVector {
public:
    size_t t_size; // number of size

    std::vector<scalar> data;

public:
    DenseVector(const size_t size = 0);

    size_t size() const { return t_size; }

    /**
        Sets all values to zero
        **/
    void clear();

    /*
        Returns the value in [index]
        */
    scalar value(const size_t index) const;

    scalar& operator()(const size_t index);

    void resize(const size_t size);
};

template <typename scalar>
DenseVector<scalar>::DenseVector(const size_t size)
{
    resize(size);
}

template <typename scalar>
void DenseVector<scalar>::clear()
{
    for (typename std::vector<scalar>::iterator i = data.begin(); i != data.end(); i++) {
        *i = 0;
    }
}

template <typename scalar>
scalar DenseVector<scalar>::value(const size_t index) const
{
    assert(index < t_size);

    return this->data[index];
}

template <typename scalar>
scalar& DenseVector<scalar>::operator()(const size_t index)
{
    assert(index < t_size);

    return this->data[index];
}

template <typename scalar>
void DenseVector<scalar>::resize(const size_t size)
{
    using namespace std;

    data.resize(size);
    t_size = size;
}

} // namespace lalib
#endif
