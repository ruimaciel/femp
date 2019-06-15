#ifndef LALIB_MATRIX_STORAGE_POLICY_LOWER_TRIANGULAR_HPP
#define LALIB_MATRIX_STORAGE_POLICY_LOWER_TRIANGULAR_HPP

#include <assert.h>
#include <iostream> // debug only
#include <vector>

namespace lalib {

/**
LowerTriangular: a storage policy class for the lower triangular, square, dense, dynamically resizeable matrix that stores the values in rows
**/
template <typename scalar>
class LowerTriangular {
public:
    struct Data {
        size_t t_rows; // number of rows
        size_t t_columns; // number of columns

        std::vector<scalar> data;
    } data;

public:
    LowerTriangular(const size_t rows = 0, const size_t columns = 0);
    ~LowerTriangular() {};

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
LowerTriangular<scalar>::LowerTriangular(const size_t rows, const size_t columns)
{
    resize(rows, columns);
}

template <typename scalar>
void LowerTriangular<scalar>::clear()
{
    using namespace std;
    for (typename vector<scalar>::iterator i = data.data.begin(); i != data.data.end(); i++) {
        *i = 0;
    }
}

template <typename scalar>
scalar LowerTriangular<scalar>::value(const size_t row, const size_t column)
{
    assert(column < data.t_columns);

    if (column > row)
        return 0;
    return this->data.data[(row + 1) * row / 2 + column];
}

template <typename scalar>
scalar& LowerTriangular<scalar>::operator()(const size_t row, const size_t column)
{
    assert(column < data.t_columns);
    assert(row >= column);

    return this->data.data[(row + 1) * row / 2 + column];
}

template <typename scalar>
void LowerTriangular<scalar>::resize(const size_t rows, const size_t columns)
{
    assert(rows == columns);

    using namespace std;

    data.data.resize((2 + columns) * (1 + columns) / 2);

    data.t_rows = rows;
    data.t_columns = columns;
}

} // namespace lalib
#endif
