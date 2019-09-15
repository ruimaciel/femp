#ifndef LALIB_MATRIX_STORAGE_POLICY_OPENGL_HPP
#define LALIB_MATRIX_STORAGE_POLICY_OPENGL_HPP

#include <assert.h>
#include <iostream> // debug only
#include <vector>

namespace lalib {

/**
Opengl: a storage policy class intended to implement the interfaces specific to the dense, dynamically resizeable matrix to be used in the Matrix host class.
**/
template <typename scalar>
class Opengl {
public:
    struct Data {
        scalar data[16];
    } data;

public:
    Opengl(const size_t rows, const size_t columns);
    ~Opengl() {};

    size_t rows() { return 4; };
    size_t columns() { return 4; };

    /*
		Returns the value in [row,column] 
		*/
    scalar value(const size_t row, const size_t column);

    scalar& operator()(const size_t row, const size_t column);

    void resize(const size_t row, const size_t column);
};

template <typename scalar>
Opengl<scalar>::Opengl(const size_t rows, const size_t columns)
{
    // the default arguments for class Matrix's constructors set the size as 1.  This class ignores that.
    for (int i = 0; i < 16; i++)
        data.data[i] = 0;
}

template <typename scalar>
scalar Opengl<scalar>::value(const size_t row, const size_t column)
{
    assert(row < 4);
    assert(column < 4);

    return this->data.data[column * 4 + row];
}

template <typename scalar>
scalar& Opengl<scalar>::operator()(const size_t row, const size_t column)
{
    assert(row < 4);
    assert(column < 4);

    return this->data.data[column * 4 + row];
}

template <typename scalar>
void Opengl<scalar>::resize(const size_t, const size_t)
{
    assert(false); // opengl matrices aren't resizeable
}

} // namespace lalib
#endif
