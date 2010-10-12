#ifndef LALIB_SOLVERS_CONJUGATE_GRADIENT_HPP
#define LALIB_SOLVERS_CONJUGATE_GRADIENT_HPP

#include "../Matrix.h++"
#include "../Vector.h++"
#include "../Operations.h++"

#include "SolverReturnCodes.h++"

#include "../output.h++"

namespace lalib
{


template<typename scalar, template<typename> class MatrixStoragePolicy, template<typename> class VectorStoragePolicy>
ReturnCode cg(Matrix<scalar, MatrixStoragePolicy> &A, Vector<scalar, VectorStoragePolicy> &x, Vector<scalar, VectorStoragePolicy> &b, const scalar delta, int max_iterations = 50) 
{
	assert(A.columns() == b.size());

	x.resize( b.size() );

	Vector<scalar> r, p;
	Vector<scalar> Ap;
	scalar rsold, rsnew, alpha;

	r = b - A*x;
	p = r;

	rsold = dot(r,r);

	for (int iter = 0; iter < max_iterations; iter++)
	{
		Ap = A*p;
		alpha = rsold/dot(p,Ap);
		//x = x + alpha*p;
		Axpy(x,alpha,p);
		Axpy(r,-alpha,Ap);

		rsnew = dot(r,r);

		if(rsnew < delta)
			return OK;

		p = r + (rsnew/rsold)*p;
		rsold = rsnew;
	}

	return EXCESSIVE_ITERATIONS;
}



}

#endif
