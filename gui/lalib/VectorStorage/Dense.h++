#ifndef LALIB_VECTOR_STORAGE_POLICY_DENSE_HPP
#define LALIB_VECTOR_STORAGE_POLICY_DENSE_HPP


#include <assert.h>
#include <vector>
#include <iostream>	// debug only


namespace lalib
{

/**
DenseVector: a storage policy class intended to implement the interfaces specific to the dense, dynamically resizeable vector to be used in the Vector host class.
**/
template<typename scalar>
class DenseVector
{
	protected:
		size_t	t_size;		// number of size

		std::vector< scalar >	data;	
		
	public:
		DenseVector(const size_t size = 0 = 0);
		~DenseVector()	{};

		size_t size()		{ return t_size; };

		/*
		Returns the value in [index]
		*/
		scalar value(const size_t index);

		scalar & operator() (const size_t index);


		void resize(const size_t size);
};



template<typename scalar>
DenseVector<scalar>::DenseVector(const size_t size)
{
	resize(size);
}



template<typename scalar>
scalar DenseVector<scalar>::value(const size_t index)
{
	assert(index < t_size);

	return this->data[index];
}


template<typename scalar>
scalar & DenseVector<scalar>::operator() (const size_t index)
{
	assert(index < t_size);

	return this->data[index];
}


template<typename scalar>
void DenseVector<scalar>::resize(const size_t size)
{
	using namespace std;

	data.resize(size);
	t_size = size;
}


}	// namespace lalib
#endif
