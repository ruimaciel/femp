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


template<typename scalar>
void assign(Matrix<scalar,SparseCCS> &lhs, Matrix<scalar, SparseDOK> &rhs)
{
	using namespace std;
	cout << "void assign(Matrix<scalar,SparseCCS> &lhs, Matrix<scalar, SparseDOK> &rhs)" << endl;

	lhs.data.values.clear(), lhs.data.values.reserve(rhs.nnz());
	lhs.data.row_index.clear(), lhs.data.row_index.reserve(rhs.nnz());
	lhs.data.column_pointer.clear(), lhs.data.column_pointer.reserve(rhs.columns());
	lhs.data.column_pointer.push_back(0);

	#define rrow (i->first%rhs.data.t_rows)
	#define rcol (i->first/rhs.data.t_rows)

	for(typename map<size_t, scalar >::iterator i = rhs.data.data.begin(); i != rhs.data.data.end(); i++)
	{
		lhs.data.values.push_back(i->second);
		if(rrow > lhs.data.t_rows)
		{
			lhs.data.t_rows = rrow;
		}
		lhs.data.row_index.push_back(rrow);
		if(lhs.data.column_pointer.size() -1 != rcol)
		{
			lhs.data.column_pointer.push_back(lhs.data.row_index.size()-1);
		}
	}
	lhs.data.column_pointer.push_back(lhs.data.row_index.size());
	lhs.data.t_rows++;
	#undef rrow
	#undef rcol

	/*
	cout << "values: [";
	for(typename vector<scalar>::iterator i = lhs.data.values.begin(); i != lhs.data.values.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "]\n";
	cout << "colp: [";
	for(vector<long int>::iterator i = lhs.data.column_pointer.begin(); i != lhs.data.column_pointer.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "]\n";
	cout << "row index: [";
	for(vector<long int>::iterator i = lhs.data.row_index.begin(); i!= lhs.data.row_index.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "]\n";
	*/
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


template<typename scalar, template<typename> class VectorStoragePolicy> 
scalar ppmvm(Vector<scalar, VectorStoragePolicy> &lhsv, Matrix<scalar,SparseDOK> &m, Vector<scalar, VectorStoragePolicy> &rhsv)
{
	assert(lhsv.size() == m.rows());
	assert(lhsv.size() == m.columns());

	scalar out = 0;
	scalar v = 0;

	size_t i = 0;	// row

	#define rrow (c->first%m.data.t_rows)
	#define rcol (c->first/m.data.t_rows)
	for(typename std::map<size_t, scalar>::iterator c = m.data.data.begin(); c != m.data.data.end(); c++)
	{
		if(i != rrow)
		{
			out += lhsv.value(i)*v;
			v = 0;
			i = rrow;
		}
		v += c->second*rhsv.value(rcol);
	}
	out += lhsv.value(i)*v;
	v = 0;
	#undef rrow
	#undef rcol


	return out;
}
// */
}

#endif
