#ifndef LALIB_MATRIX_STORAGE_POLICY_SPARSE_DOK_HPP
#define LALIB_MATRIX_STORAGE_POLICY_SPARSE_DOK_HPP


#include <assert.h>
#include <map>
#include <iostream>	// debug only


namespace lalib
{

/**
SparseDOK: a storage policy class for the Matrix host class.
This class implements the interface for the sparse Dictionary of Keys (DOK) matrix format
**/
template<typename scalar>
class SparseDOK
{
	public:
		struct Data
		{
			size_t	t_rows;		// number of rows
			size_t	t_columns;	// number of columns

			std::map< size_t, scalar> 	data;
		} data;

	public:
		SparseDOK(const size_t rows = 1, const size_t columns = 1);
		~SparseDOK()	{};

		/**
		Sets all values to zero
		**/
		void clear();

		size_t rows()		{ return data.t_rows; };
		size_t columns()	{ return data.t_columns; };

		/*
		Returns the value in [row,column] 
		*/
		scalar value(const size_t row, const size_t column);

		scalar & operator() (const size_t row, const size_t column);


		void resize(const size_t row, const size_t column);
};



template<typename scalar>
SparseDOK<scalar>::SparseDOK(const size_t rows, const size_t columns)
{
	resize(rows, columns);
}


template<typename scalar>
void SparseDOK<scalar>::clear()
{
	using namespace std;
	data.data.clear();
}


template<typename scalar>
scalar SparseDOK<scalar>::value(const size_t row, const size_t column)
{
	using namespace std;

	assert(row < data.t_rows);
	assert(column < data.t_columns);

	typename map<size_t, scalar>::iterator	i;

	i = data.data.find(row*data.t_columns + column);
	if(i == data.data.end())
		return 0;

	return i->second;
}


template<typename scalar>
scalar & SparseDOK<scalar>::operator() (const size_t row, const size_t column)
{
	assert(row < data.t_rows);
	assert(column < data.t_columns);

	return this->data.data[row*data.t_columns + column];
}


template<typename scalar>
void SparseDOK<scalar>::resize(const size_t rows, const size_t columns)
{
	using namespace std;

	data.data.clear();

	data.t_rows = rows;
	data.t_columns = columns;
}


}	// namespace lalib
#endif
