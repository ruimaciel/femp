#ifndef FEM_EQUATION_HPP
#define FEM_EQUATION_HPP


#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace fem
{

struct FemEquation
{
	FemEquation();
	~FemEquation();

	// compressed_vector offers "fast element lookup, superior  axpy speed, low memory usage, but low structure changes (insert, erase)
	boost::numeric::ublas::compressed_matrix<double> k;
	boost::numeric::ublas::compressed_vector<double> f;
};

}

#endif
