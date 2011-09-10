#ifndef ELEMENT_RESULTS_HPP
#define ELEMENT_RESULTS_HPP

#include "Strains.h++"
#include "Stresses.h++"

#include "../Element.h++"


/**
Stores the results for each element
**/
template<Scalar>
struct ElementResults
{
	ElementResults();

	std::vector<Strains<Scalar> >	strains;	// strains calculated in each of the element's nodes
	std::vector<Stresses<Scalar> >	stresses;	// stresses calculated in each of the element's nodes

	std::vector<Scalar>	von_mises;

	/**
	resizes all lists
	**/
	void resize(const unsigned int );
};



template<Scalar>
ElementResults<Scalar>::ElementResults()
{
	stress.clear();
	strain.clear();
	von_mises.clear();
}


template<Scalar>
void 
ElementResults<Scalar>::resize(const unsigned int size)
{
	stress.resize(size);
	strain.resize(size);
	von_mises.resize(size);
}


#endif
