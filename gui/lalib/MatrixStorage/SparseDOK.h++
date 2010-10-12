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

			std::map< size_t, std::map<size_t, scalar> > 	data;
		} data;

	public:
		SparseDOK(const size_t rows = 0, const size_t columns = 0);
		~SparseDOK()	{};

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
scalar SparseDOK<scalar>::value(const size_t row, const size_t column)
{
	using namespace std;

	assert(row < data.t_rows);
	assert(column < data.t_columns);

	typename map<size_t, map<size_t,scalar> >::iterator value_row;
	typename map<size_t, scalar>::iterator	value_column;

	value_row = data.data.find(row);
	if(value_row == data.data.end())
		return 0;	// value wasn't added to the matrix yet

	value_column = value_row->second.find(column);
	if(value_column == value_row->second.end())
		return 0;

	return value_column->second;
}


template<typename scalar>
scalar & SparseDOK<scalar>::operator() (const size_t row, const size_t column)
{
	assert(row < data.t_rows);
	assert(column < data.t_columns);

	return this->data.data[row][column];
}


template<typename scalar>
void SparseDOK<scalar>::resize(const size_t rows, const size_t columns)
{
	using namespace std;

	if(data.t_rows > rows)
	{
		// remove all extra rows
		for(typename map<size_t, map<size_t, scalar> >::iterator excess_row = data.data.lower_bound(rows); excess_row != data.data.end(); excess_row = data.data.lower_bound(rows))
		{
			data.data.erase(excess_row);
		}
	}
	if(data.t_columns > columns )
	{
		for(typename map<size_t, map<size_t, scalar> >::iterator i = data.data.begin(); i != data.data.end(); i++)
		{
			// remove all extra rows
			for(typename map<size_t, scalar>::iterator excess_column = i->second.lower_bound(columns); excess_column != i->second.end(); excess_column = i->second.lower_bound(columns))
			{
				i->second.erase(excess_column);
			}
		}
	}

	data.t_rows = rows;
	data.t_columns = columns;
}


}	// namespace lalib
#endif
