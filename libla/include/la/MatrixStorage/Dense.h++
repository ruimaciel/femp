#ifndef LALIB_MATRIX_STORAGE_POLICY_DENSE_HPP
#define LALIB_MATRIX_STORAGE_POLICY_DENSE_HPP

#include <assert.h>
#include <iostream> // debug only
#include <vector>

namespace lalib {

/**
DenseMatrix: a storage policy class intended to implement the interfaces specific to the dense, dynamically resizeable matrix to be used in the Matrix host class.
**/
template <typename scalar>
class DenseMatrix {
public:
    struct Data {
        size_t t_rows; // number of rows
        size_t t_columns; // number of columns

        std::vector<scalar> data;
    } data;

public:
    DenseMatrix(const size_t rows = 0, const size_t columns = 0);
    ~DenseMatrix() {};

    /**
		Sets all values to zero
		**/
    void clear();

    size_t rows() { return data.t_rows; };
    size_t columns() { return data.t_columns; };

    /*
		Returns the value in [row,column] 
		*/
    scalar value(const size_t row, const size_t column);

    scalar& operator()(const size_t row, const size_t column);

    void resize(const size_t row, const size_t column);
};

template <typename scalar>
DenseMatrix<scalar>::DenseMatrix(const size_t rows, const size_t columns)
{
    resize(rows, columns);
}

template <typename scalar>
void DenseMatrix<scalar>::clear()
{
    using namespace std;

    data.data.clear();
    data.data.resize(rows * columns);
}

template <typename scalar>
scalar DenseMatrix<scalar>::value(const size_t row, const size_t column)
{
    assert(row < data.t_rows);
    assert(column < data.t_columns);

    return this->data.data[row * data.t_rows + column];
}

template <typename scalar>
scalar& DenseMatrix<scalar>::operator()(const size_t row, const size_t column)
{
    assert(row < data.t_rows);
    assert(column < data.t_columns);

    return this->data.data[row * data.t_rows + column];
}

template <typename scalar>
void DenseMatrix<scalar>::resize(const size_t rows, const size_t columns)
{
    using namespace std;

    data.data.resize(rows);
    data.t_rows = rows;

    data.t_rows = rows;
    data.t_columns = columns;

    data.data.clear();
    data.data.resize(data.t_rows * data.t_columns);
}

} // namespace lalib
#endif
