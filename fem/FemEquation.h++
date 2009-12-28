#ifndef FEM_EQUATION_HPP
#define FEM_EQUATION_HPP


#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace fem
{

struct FemEquation
{
	boost::numeric::ublas::symmetric_matrix<double, boost::numeric::ublas::upper> k;
	boost::numeric::ublas::mapped_vector<double> f;
};

}

#endif
