#ifndef FEMP_ELEMENTRESULTS_HPP
#define FEMP_ELEMENTRESULTS_HPP

#include <ostream>
#include <vector>
#include "Strains.h++"
#include "Stresses.h++"

#include <libfemp/Element.h++>


namespace fem
{


/**
Stores the results for each element
**/
struct ElementResults
{
	std::vector<Strains<double> >	strains;	// strains calculated in each of the element's nodes
	std::vector<Stresses<double> >	stresses;	// stresses calculated in each of the element's nodes

	std::vector<double>	von_mises;

	double eig_vec[3][3];	// stress tensor eigen vectors 
	double eig_val[3];		// stress tensor eigen values 

	/**
	resizes all lists
	**/
	void resize(const unsigned int );
};


}	// namespace fem


#endif
