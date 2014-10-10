#ifndef UBLAS_SOLVERS_HPP
#define UBLAS_SOLVERS_HPP

#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

/*
Linear algebra helper functions
*/


namespace fem
{

/*
   return the inverse of a 3 by 3 matrix
 */
boost::numeric::ublas::matrix<double> invert3by3(const boost::numeric::ublas::matrix<double> &M, double det);


/*
   return the determinant of a 3 by 3 matrix
 */
double det3by3(const boost::numeric::ublas::matrix<double> &M);


bool solve_cholesky( boost::numeric::ublas::compressed_matrix<double> &A, boost::numeric::ublas::vector<double> &b);

bool solve_conjugate_gradient( boost::numeric::ublas::compressed_matrix<double> &A, boost::numeric::ublas::vector<double> &b, float e);

bool solve_gauss( boost::numeric::ublas::compressed_matrix<double> &A, boost::numeric::ublas::vector<double> &b);


}
#endif
