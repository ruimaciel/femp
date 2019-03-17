#ifndef LALIB_SOLVERS_CONJUGATE_GRADIENT_HPP
#define LALIB_SOLVERS_CONJUGATE_GRADIENT_HPP

#include <string>

#include <boost/lexical_cast.hpp>

#include "../Matrix.h++"
#include "../Vector.h++"
#include "../Operations.h++"

#include "../ProgressIndicatorStrategy.h++"

#include "SolverReturnCodes.h++"

#include "../output.h++"

namespace lalib
{


template<typename scalar, template<typename> class MatrixStoragePolicy, template<typename> class VectorStoragePolicy>
ReturnCode cg(Matrix<scalar, MatrixStoragePolicy> &A, Vector<scalar, VectorStoragePolicy> &x, Vector<scalar, VectorStoragePolicy> &b, const scalar delta, int max_iterations, ProgressIndicatorStrategy *progress) 
{
	assert(A.columns() == b.size());

	x.resize( b.size() );

	Vector<scalar> r, p;
	Vector<scalar> Ap;
	scalar rsold, rsnew, alpha;

	r = b - A*x;
	p = r;

	rsold = dot(r,r);

	progress->markSectionLimit(max_iterations);

	for (int iter = 0; iter < max_iterations; iter++)
	{
		
		if(iter%10 == 0) progress->markProgress(iter);

		Ap = A*p;
		alpha = rsold/dot(p,Ap);
		//x = x + alpha*p;
		Axpy(x,alpha,p);
		Axpy(r,-alpha,Ap);

		rsnew = dot(r,r);

		if(rsnew < delta)
		{
			std::string temp;
			temp = "Residue: ";
			temp.append(boost::lexical_cast<std::string>(rsnew));
			progress->message(temp);
			return OK;
		}

		p = r + (rsnew/rsold)*p;
		rsold = rsnew;
	}

	std::string temp;
	temp = "Failed to converge.  Residue: ";
	temp.append(boost::lexical_cast<std::string>(rsnew));
	progress->error(temp);
	return ERR_EXCESSIVE_ITERATIONS;
}



}

#endif
