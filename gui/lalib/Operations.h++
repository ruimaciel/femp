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


// */
}

#endif
