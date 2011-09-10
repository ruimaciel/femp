#ifndef ELEMENT_RESULTS_HPP
#define ELEMENT_RESULTS_HPP

#include <vector>
#include "Strains.h++"
#include "Stresses.h++"

#include "../Element.h++"


namespace fem
{


/**
Stores the results for each element
**/
template<typename Scalar>
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



template<typename Scalar>
ElementResults<Scalar>::ElementResults()
{
	stresses.clear();
	strains.clear();
	von_mises.clear();
}


template<typename Scalar>
void 
ElementResults<Scalar>::resize(const unsigned int size)
{
	stresses.resize(size);
	strains.resize(size);
	von_mises.resize(size);
}


}


#endif
