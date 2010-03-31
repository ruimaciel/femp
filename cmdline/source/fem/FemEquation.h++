#ifndef FEM_EQUATION_HPP
#define FEM_EQUATION_HPP


#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace fem
{

struct FemEquation
{
	enum Error { 
	ERR_OK, 
	ERR_SINGULAR
	};

	FemEquation();
	~FemEquation();

	// compressed_vector offers "fast element lookup, superior  axpy speed, low memory usage, but low structure changes (insert, erase)
	boost::numeric::ublas::compressed_matrix<double> k;
	boost::numeric::ublas::compressed_vector<double> f;
	boost::numeric::ublas::compressed_vector<double> d;

	enum Error solve();

	/*
	Without pivoting
	*/
	enum Error my_plain_gauss_solve();

	/*
	With partial pivoting
	*/
	enum Error my_gauss_solve();

	/** solving the equation through the conjugate gradiant method
	@param e	acceptable margin of error
	**/
	enum Error CGsolve(float e);
};

}

#endif
