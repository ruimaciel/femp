#ifndef LALIB_MATRIX_VECTOR_OPERATIONS_HPP
#define LALIB_MATRIX_VECTOR_OPERATIONS_HPP

namespace lalib {
/**
The default matrix-vector operator
@param	m	a matrix, instance of class Matrix<scalar, MatrixStoragePolicy>
@param	v	a vector, instance of class Vector<scalar, VectorStoragePolicy>
@return	a dense vector, instance of class Vector<scalar, DenseVector>
**/
template <typename scalar, template <typename> class MatrixStoragePolicy, template <typename> class VectorStoragePolicy>
Vector<scalar, DenseVector> operator*(Matrix<scalar, MatrixStoragePolicy>& m, Vector<scalar, VectorStoragePolicy>& v) {
	assert(m.columns() == v.size());

	Vector<scalar, DenseVector> v_out(m.rows());

	for (size_t i = 0; i < m.rows(); i++) {
		v_out(i) = 0;
		for (size_t j = 0; j < m.columns(); j++) {
			v_out(i) += m.value(i, j) * v.value(j);
		}
	}

	return v_out;
}

/**
The matrix-vector operator specialized for the SparseCRS matrices
@param	m	a matrix, instance of class Matrix<scalar, SparseCRS>
@param	v	a vector, instance of class Vector<scalar, VectorStoragePolicy>
@return	a dense vector, instance of class Vector<scalar, DenseVector>
**/

template <typename scalar, template <typename> class VectorStoragePolicy>
Vector<scalar, DenseVector> operator*(Matrix<scalar, SparseCRS>& m, Vector<scalar, VectorStoragePolicy>& v) {
	using namespace std;

	assert(m.columns() == v.size());

	Vector<scalar, DenseVector> v_out(m.rows());

	for (size_t row = 0; row != m.rows(); row++) {
		v_out(row) = 0;
		for (size_t i = m.data.row_pointer[row]; i < m.data.row_pointer[row + 1]; i++) {
			// cout << "i:" << i << endl;
			v_out(row) += m.data.values[i] * v.value(m.data.column_index[i]);
		}
	}

	return v_out;
}
// */
}  // namespace lalib

#endif
