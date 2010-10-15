#ifndef LALIB_SOLVERS_CHOLESKY_HPP
#define LALIB_SOLVERS_CHOLESKY_HPP


#include <cmath>
#include <iostream>	//TODO remove after debugging

#include "SolverReturnCodes.h++"

#include "../Matrix.h++"

namespace lalib
{

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

	// Ly = b
	for(size_t i = 0; i < L.rows(); i++)
	{
		s = 0;
		for(size_t j = 0; j < i; j++)
		{
			s += L(i,j)*x(j);
		}
		x(i) = (b(i) - s)/L(i,i);
	}

	//Lx=y
	for(size_t j = L.columns() - 1; j > 0; j--)
	{
		s = 0;
		for(size_t i = j+1; i < L.rows(); i++)
		{
			s += L(i,j)*x(i);
		}
		x(j) = (x(j) - s)/L(j,j);
	}

	s = 0;
	for(size_t i = 1; i < L.rows(); i++)
	{
		s += L(i,0)*x(i);
	}
	x(0) = (x(0) - s)/L(0,0);

	return OK;
}

}

#endif

