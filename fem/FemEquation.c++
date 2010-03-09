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

	enum FemEquation::Error FemEquation::solve()
	{
		//TODO detect and avoid singular matrix
		using namespace boost::numeric::ublas;

		permutation_matrix<> pm(k.size1());	// k will be symmetric
		
		if(lu_factorize(k,pm) == true) // LU factorized
			return ERR_SINGULAR;

		d = boost::numeric::ublas::solve(k,f,upper_tag());

		//All went well
		return ERR_OK;
	}

}

