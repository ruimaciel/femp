#ifndef LIBLA_MATRIX_HPP
#define LIBLA_MATRIX_HPP

#include <assert.h>

#include <vector>

#include "MatrixStorage/Dense.h++"
#include "MatrixStorage/Diagonal.h++"
#include "MatrixStorage/LowerTriangular.h++"
#include "MatrixStorage/SparseCCS.h++"
#include "MatrixStorage/SparseCRS.h++"
#include "MatrixStorage/SparseDOK.h++"

namespace lalib {

template <typename scalar, template <typename> class MatrixStoragePolicy = DenseMatrix>
class Matrix : public MatrixStoragePolicy<scalar> {
	public:
	Matrix(const size_t rows = 1, const size_t columns = 1);
	Matrix(Matrix<scalar, MatrixStoragePolicy>& other);
	~Matrix(){};

	size_t rows() {
		return MatrixStoragePolicy<scalar>::rows();
	};
	size_t columns() {
		return MatrixStoragePolicy<scalar>::columns();
	};

	/**
				Sets all values to zero
				**/
	void clear();

	/**
				Returns the value [row,column] defined in this matrix
				**/
	scalar value(const size_t row, const size_t column);

	/**
				Returns a reference to this matrix' element in [row,column]
				**/
	scalar& operator()(const size_t row, const size_t column);
};

template <typename scalar, template <typename> class MatrixStoragePolicy>
Matrix<scalar, MatrixStoragePolicy>::Matrix(const size_t rows, const size_t columns) : MatrixStoragePolicy<scalar>(rows, columns) {}

template <typename scalar, template <typename> class MatrixStoragePolicy>
Matrix<scalar, MatrixStoragePolicy>::Matrix(Matrix<scalar, MatrixStoragePolicy>& other) : MatrixStoragePolicy<scalar>(other) {
	this->data = other.data;
}

template <typename scalar, template <typename> class MatrixStoragePolicy>
void Matrix<scalar, MatrixStoragePolicy>::clear() {
	MatrixStoragePolicy<scalar>::clear();
}

template <typename scalar, template <typename> class MatrixStoragePolicy>
scalar Matrix<scalar, MatrixStoragePolicy>::value(const size_t row, const size_t column) {
	return MatrixStoragePolicy<scalar>::value(row, column);
}

template <typename scalar, template <typename> class MatrixStoragePolicy>
scalar& Matrix<scalar, MatrixStoragePolicy>::operator()(const size_t row, const size_t column) {
	return MatrixStoragePolicy<scalar>::operator()(row, column);
}
}  // namespace lalib

#endif
