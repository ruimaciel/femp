#ifndef SUBSTITUTION_HPP
#define SUBSTITUTION_HPP

#include "../Matrix.hpp"
#include "SolverReturnCodes.hpp"

namespace lalib {
/**
Generic forward substitution routine for dense matrices and dense vectors
**/
template <typename scalar, template <typename> class MatrixStoragePolicy, template <typename> class VectorStoragePolicy>
ReturnCode forward_substitution(Matrix<scalar, MatrixStoragePolicy>& L, Vector<scalar, VectorStoragePolicy>& x, Vector<scalar, VectorStoragePolicy>& b) {
	if (L.rows() != L.columns()) return ERR_NOT_SQUARE;

	// Ly = b
	scalar s = 0;
	for (size_t i = 0; i < L.rows(); i++) {
		s = 0;
		for (size_t j = 0; j < i; j++) {
			s += L(i, j) * x(j);
		}
		x(i) = (b.value(i) - s) / L(i, i);
	}

	return OK;
}

/**
Generic back substitution routine for dense matrices and dense vectors
**/
template <typename scalar, template <typename> class MatrixStoragePolicy, template <typename> class VectorStoragePolicy>
ReturnCode back_substitution(Matrix<scalar, MatrixStoragePolicy>& L, Vector<scalar, VectorStoragePolicy>& x, Vector<scalar, VectorStoragePolicy>& b) {
	if (L.rows() != L.columns()) return ERR_NOT_SQUARE;

	scalar s = 0;
	for (size_t j = L.columns() - 1; j > 0; j--) {
		s = 0;
		for (size_t i = j + 1; i < L.rows(); i++) {
			s += L(i, j) * x(i);
		}
		x(j) = (b(j) - s) / L(j, j);
	}

	s = 0;
	for (size_t i = 1; i < L.rows(); i++) {
		s += L(i, 0) * x(i);
	}
	x(0) = (b(0) - s) / L(0, 0);

	return OK;
}
}  // namespace lalib
#endif
