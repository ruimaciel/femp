#ifndef ELEMENT_RESULTS_HPP
#define ELEMENT_RESULTS_HPP

#include <ostream>
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
	std::vector<Strains<Scalar> >	strains;	// strains calculated in each of the element's nodes
	std::vector<Stresses<Scalar> >	stresses;	// stresses calculated in each of the element's nodes

	std::vector<Scalar>	von_mises;

	Scalar eig_vec[3][3];	// stress tensor eigen vectors 
	Scalar eig_val[3];		// stress tensor eigen values 

	/**
	resizes all lists
	**/
	void resize(const unsigned int );
};


template<typename Scalar>
void 
ElementResults<Scalar>::resize(const unsigned int size)
{
	stresses.resize(size);
	strains.resize(size);
	von_mises.resize(size);
}


template<typename Scalar>
std::ostream &operator<< (std::ostream &os, ElementResults<Scalar> const &element_results)
{
	os << "\t strain:\n";
	for(typename std::vector<Strains<Scalar> >::const_iterator i = element_results.strains.begin(); i != element_results.strains.end(); i++)	// strains calculated in each of the element's nodes
	{
		os << "\t\te_11: " << i->e11;
		os << "\te_22: " << i->e22;
		os << "\te_33: " << i->e33;
		os << "\te_12: " << i->e12;
		os << "\te_23: " << i->e23;
		os << "\te_13: " << i->e13;
		os << "\n";
	}
	os << "\t stress:\n";
	for(typename std::vector<Stresses<Scalar> >::const_iterator i = element_results.stresses.begin(); i != element_results.stresses.end(); i++)	// stresses calculated in each of the element's nodes
	{
		os << "\t\ts_11: " << i->s11;
		os << "\ts_22: " << i->s22;
		os << "\ts_33: " << i->s33;
		os << "\ts_12: " << i->s12;
		os << "\ts_23: " << i->s23;
		os << "\ts_13: " << i->s13;
		os << "\n";
	}
	os << "\t von mises:\n";
	for(typename std::vector<Scalar>::const_iterator i = element_results.von_mises.begin(); i != element_results.von_mises.end(); i++)	// stresses calculated in each of the element's nodes
	{
		os << "\t\tv: " << *i;
		os << "\n";
	}

	// code useful for debugging: remove later
	os << "\t eigen stuff\n";
	for(int i = 0; i < 3; i++)
	{
		os << "\t\teve" << i << " = [";
		os << element_results.eig_vec[0][i] << ", " << element_results.eig_vec[1][i] << ", " << element_results.eig_vec[2][i] << "]', ";
		os << "eva" << i << " = ";
		os << element_results.eig_val[i] << "\n";
	}

	os << "T = [" ;
	os << element_results.stresses[4].s11 << " " <<  element_results.stresses[4].s12 << " " << element_results.stresses[4].s13 << ";\n";
	os << element_results.stresses[4].s12 << " " <<  element_results.stresses[4].s22 << " " << element_results.stresses[4].s23 << ";\n";
	os << element_results.stresses[4].s13 << " " <<  element_results.stresses[4].s23 << " " << element_results.stresses[4].s33 << "]\n";

	os << std::endl;
	return os;
}

}


#endif
