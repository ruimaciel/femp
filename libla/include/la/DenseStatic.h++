#ifndef LIBLA_MATRIX_DENSE_STATIC_HPP
#define LIBLA_MATRIX_DENSE_STATIC_HPP

#include <assert.h>

namespace lalib {

template <typename scalar, size_t t_rows, size_t t_columns>
class DenseStaticMatrix {
protected:
    scalar data[t_rows][t_columns];

public:
    DenseStaticMatrix() {};
    ~DenseStaticMatrix() {};

    size_t rows() { return t_rows; };
    size_t columns() { return t_columns; };

    scalar& value(const size_t row, const size_t colum);
};

template <typename scalar, size_t t_rows, size_t t_columns>
scalar& DenseStaticMatrix<scalar, t_rows, t_columns>::value(const size_t row, const size_t column)
{
    assert(row < t_rows);
    assert(column < t_columns);

    return data[row][column];
}

}

#endif
