#ifndef LALIB_MATRIX_STORAGE_POLICY_DIAGONAL_HPP
#define LALIB_MATRIX_STORAGE_POLICY_DIAGONAL_HPP


#include <assert.h>
#include <vector>


namespace lalib
{

/**
Diagonal: a storage policy class for the Matrix host class.
This class implements the interface for the diagonal matrix format
**/
template<typename scalar>
class Diagonal
{
	public:
		struct Data
		{
			size_t	t_rows;		// number of rows
			size_t	t_columns;	// number of columns

			std::vector<scalar> data;
		} data;

	public:
		Diagonal(const size_t rows = 0, const size_t columns = 0);
		~Diagonal()	{};

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
Diagonal<scalar>::Diagonal(const size_t rows, const size_t columns)
{
	resize(rows, columns);
}



template<typename scalar>
scalar Diagonal<scalar>::value(const size_t row, const size_t column)
{
	using namespace std;

	assert(row < data.t_rows);
	assert(column < data.t_columns);


	if(row != column)
		return 0;

	return data.data[row];
}


template<typename scalar>
scalar & Diagonal<scalar>::operator() (const size_t row, const size_t column)
{
	assert(row < data.t_rows);
	assert(column < data.t_columns);

	assert(row == column);

	return this->data.data[row];
}


template<typename scalar>
void Diagonal<scalar>::resize(const size_t rows, const size_t columns)
{
	using namespace std;


	rows < columns ? data.data.resize(rows): data.data.resize(columns);

	data.t_rows = rows;
	data.t_columns = columns;
}


}	// namespace lalib

#endif
