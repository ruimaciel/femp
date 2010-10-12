#ifndef LALIB_VECTOR_DENSE_STATIC_HPP
#define LALIB_VECTOR_DENSE_STATIC_HPP

#include <assert.h>



namespace lalib
{


template<typename scalar, size_t t_rows>
class DenseStaticVector 
{
	protected:
		bool transpose;
		scalar data[t_rows];

	public:
		DenseStaticVector();
		~DenseStaticVector()	{};

		
		/**
		Informs if the current instance is a row vector
		@return	true if it's a row vector
		**/
		bool isRow()	{	return transpose;	};

		/**
		Informs if the current instance is a column vector
		@return	true if it's a column vector
		**/
		bool isColumn()	{	return !transpose;	};


		size_t rows()		{ return t_rows;	};

		scalar &value(const size_t row);
};


template<typename scalar, size_t t_rows>
DenseStaticVector<scalar, t_rows>::DenseStaticVector()
{
	transpose = false;
}


template<typename scalar, size_t t_rows>
scalar & DenseStaticVector<scalar, t_rows>::value(const size_t row)
{
	assert(row < t_rows);

	return data[row];
}


}

#endif
