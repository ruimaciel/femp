#ifndef LALIB_OPERATIONS_HPP
#define LALIB_OPERATIONS_HPP

#include <iostream>	//TODO debug purposes only
#include <vector>
#include <map>

#include "Vector.h++"
#include "Matrix.h++"

#include "operations/mv.h++"
#include "operations/vv.h++"


namespace lalib
{

/*
template<typename scalar, templace<typename> class MatrixStoragePolicy> >
Matrix<scalar, MatrixStoragePolicy> & operator*(Matrix<scalar, MatrixStoragePolicy> &lhs, MatrixStoragePolicy &rhs)
{
}
*/


//TODO implement assignment operator
template<typename scalar, template<typename> class MatrixStoragePolicy> 
void assign(Matrix<scalar,MatrixStoragePolicy> &lhs, Matrix<scalar, SparseDOK> &rhs)
{
	using namespace std;

	lhs.resize(rhs.rows(), rhs.columns());

	for(typename map<size_t, scalar >::iterator i = rhs.data.data.begin(); i != rhs.data.data.end(); i++)
	{
		lhs(i->first/rhs.data.t_rows, i->first%rhs.data.t_rows) = i->second;
	}

}


/*
ppmvm: pre and post matrix-vector multiplication
**/
template<typename scalar, template<typename> class MatrixStoragePolicy, template<typename> class VectorStoragePolicy> 
scalar ppmvm(Vector<scalar, VectorStoragePolicy> &lhsv, Matrix<scalar,MatrixStoragePolicy> &m, Vector<scalar, VectorStoragePolicy> &rhsv)
{
	assert(lhsv.size() == m.rows());
	assert(lhsv.size() == m.columns());

	scalar out = 0;

	for(size_t i = 0; i < m.rows(); i++)
	{
		scalar v = 0;
		for(size_t j = 0; j < m.columns(); j++)
		{
			v += m.value(i,j)*rhsv.value(j); 
		}
		
		out += lhsv.value(i)*v;
	}

	return out;
}


// */
}

#endif
