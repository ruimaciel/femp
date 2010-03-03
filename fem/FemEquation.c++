#include "FemEquation.h++"

#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/lu.hpp>

namespace fem
{

	FemEquation::FemEquation()
	{
		k.clear();
		f.clear();
	}


	FemEquation::~FemEquation()
	{
	}

	void FemEquation::solve()
	{
		using namespace boost::numeric::ublas;

		permutation_matrix<> pm(k.size1());	// k will be symmetric
		
		lu_factorize(k,pm); // LU factorized

		inplace_solve(k,f,upper_tag());
	}

}

