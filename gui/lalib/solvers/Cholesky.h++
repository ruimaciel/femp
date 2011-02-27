#ifndef LALIB_SOLVERS_CHOLESKY_HPP
#define LALIB_SOLVERS_CHOLESKY_HPP


#include <cmath>
#include <iostream>	//TODO remove after debugging

#include "SolverReturnCodes.h++"
#include "substitution.h++"

#include "../Matrix.h++"

namespace lalib
{

/**
Generic cholesky decomposition for dense matrices, works on all matrix types
**/
template<typename scalar, template<typename> class MatrixStoragePolicy, template<typename> class LMatrixStoragePolicy, template<typename> class VectorStoragePolicy>
ReturnCode cholesky(Matrix<scalar, MatrixStoragePolicy> &A, Vector<scalar, VectorStoragePolicy> &x, Vector<scalar, VectorStoragePolicy> &b, Matrix<scalar, LMatrixStoragePolicy> &L)
{
	assert(A.rows() == A.columns());
	assert(A.columns() == b.size());

	using namespace std;

	scalar s;
	//lalib::Matrix<scalar, lalib::LowerTriangular> L;

	L.resize(A.rows(), A.columns());


	// A=LL^t, factor L
	for(size_t j = 0; j < A.columns(); j++)
	{
		for(size_t i = j; i < A.rows(); i++)
		{
			s = A.value(i,j);
			for(size_t m = 0; m < j; m++)	// j index incremented to avoid m < 0 - 1
			{
				s -= L(i,m)*L(j,m);
			}

			if(i == j)
			{
				L(j,j) = sqrt(s);
			}
			else
			{
				L(i,j) = s/L(j,j);
			}
			s = L(i,j);	// debug purposes
		}
	}

	ReturnCode code;
	// Ly = b
	code = forward_substitution(L,x,b);
	if(code != OK)
		return code;

	//Lx=y
	code = back_substitution(L,x,x);
	if(code != OK)
		return code;


	return OK;
}

}

#endif

