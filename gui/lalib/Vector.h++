#ifndef LALIB_VECTOR_HPP
#define LALIB_VECTOR_HPP

#include <assert.h>

#include <vector>


#include "VectorStorage/Dense.h++"


namespace lalib
{



template<typename scalar, template<typename> class VectorStoragePolicy = DenseVector>
class Vector 
	: public VectorStoragePolicy<scalar>
{
	public:
		Vector(const size_t size = 1);
		~Vector()	{};


		size_t size()		{ return VectorStoragePolicy<scalar>::size(); };

		/**
		Sets all values to zero
		**/
		void clear();

		/**
		Returns the value [index,column] defined in this matrix
		**/
		scalar value(const size_t index);


		/**
		Returns a reference to this matrix' element in [index,column] 
		**/
		scalar & operator()(const size_t index);
};


template<typename scalar, template<typename> class VectorStoragePolicy>
Vector<scalar, VectorStoragePolicy>::Vector(const size_t size)
	: VectorStoragePolicy<scalar>(size)
{
}



template<typename scalar, template<typename> class VectorStoragePolicy>
void Vector<scalar, VectorStoragePolicy>::clear()
{
	VectorStoragePolicy<scalar>::clear();
}


template<typename scalar, template<typename> class VectorStoragePolicy>
scalar Vector<scalar, VectorStoragePolicy>::value(const size_t index)
{
	return VectorStoragePolicy<scalar>::value(index);
}


template<typename scalar, template<typename> class VectorStoragePolicy>
scalar & Vector<scalar, VectorStoragePolicy>::operator() (const size_t index)
{
	return VectorStoragePolicy<scalar>::operator()(index);
}



}

#endif
