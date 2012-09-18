#ifndef LALIB_VECTOR_STORAGE_POLICY_SPARSE_CS_HPP
#define LALIB_VECTOR_STORAGE_POLICY_SPARSE_CS_HPP


#include <assert.h>
#include <vector>
#include <iostream>	// debug only


namespace lalib
{

/**
SparseCS: a storage policy class intended to implement the interfaces specific to the sparse, dynamically resizeable vector 
**/
template<typename Scalar>
class SparseCS
{
	public:
		struct Data
		{
			size_t	t_size;		// size

			std::vector< size_t >	column_index;	
			std::vector< Scalar >	values;	
		} data;
		
	public:
		SparseCS(const size_t size = 0);
		~SparseCS()	{};

		size_t size() const		{ return data.t_size; };

		/**
		Sets all values to zero
		**/
		void clear();

		/*
		Returns the value in [index]
		*/
		Scalar value(const size_t index) const;

		Scalar & operator() (const size_t index);


		void resize(const size_t size);

		/*
		Reserve memory for at least size-many non-zero entries
		@param	size	number of entries to reserve memory for
		*/
		void reserve(const size_t size);

		void push_back(size_t index, Scalar value);
};



template<typename Scalar>
SparseCS<Scalar>::SparseCS(const size_t size)
{
	resize(size);
}


template<typename Scalar>
void SparseCS<Scalar>::clear()
{
	data.values.clear();
	data.column_index.clear();
}


template<typename Scalar>
Scalar SparseCS<Scalar>::value(const size_t index) const
{
	assert(index < data.t_size);

	for(size_t i = 0; i != data.column_index.size(); i++)
	{
		if(data.column_index[i] == index)
			return data.values[i];
		if(data.column_index[i] > index)
			return 0;
	}

	return 0;
}


template<typename Scalar>
Scalar & SparseCS<Scalar>::operator() (const size_t index)
{
	assert(index < data.t_size);

	for(size_t i = 0; i != data.column_index.size(); i++)
	{
		if(data.column_index[i] == index)
			return data.values[i];
		if(data.column_index[i] > index)
		{
			std::vector<size_t>::iterator ci = data.column_index.begin() + i;
			data.column_index.insert(ci,index);
			typename std::vector<Scalar>::iterator cv = data.values.begin() + i;
			data.values.insert(cv, 0);
			return data.values[i];
		}
	}

	data.column_index.push_back(index);
	data.values.push_back(0);
	return data.values.back();
}


template<typename Scalar>
void SparseCS<Scalar>::resize(const size_t size)
{
	using namespace std;

	data.column_index.clear();
	data.values.clear();
	data.t_size = size;
}


template<typename Scalar>
void SparseCS<Scalar>::reserve(const size_t size)
{
	using namespace std;

	data.column_index.reserve(size);
	data.values.reserve(size);
}


template<typename Scalar>
void SparseCS<Scalar>::push_back(const size_t size, Scalar value)
{
	using namespace std;

	data.column_index.push_back(size);
	data.values.push_back(value);
}
}	// namespace lalib
#endif
