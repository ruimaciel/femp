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
		using namespace boost::numeric::ublas;

		// weed out singular systems
		if(f.nnz() == 0)
			return ERR_SINGULAR;

		permutation_matrix<> pm(k.size1());	// k will be symmetric
		
		lu_factorize(k,pm); // LU factorized

		inplace_solve(k,f,lower_tag());


		return ERR_OK;
	}


	enum FemEquation::Error FemEquation::CGsolve(float e)
	{
		using namespace std;

		boost::numeric::ublas::compressed_vector<double> r1;
		boost::numeric::ublas::compressed_vector<double> r2;
		boost::numeric::ublas::compressed_vector<double> p;
		double alpha;
		double beta;
		size_t iter = 0;

		r1.resize(f.size());
		d.resize(f.size());


		// initialize the vector
		for(size_t i = 0; i < f.size(); i++)
		{
			d[i] = 1;
		}

		r1 = f - prod(k,d);

		p = r1;

		r2 = r1;

		do
		{
			iter++;
			alpha = inner_prod(p,r1) / inner_prod(p,prod(k,p));
			d = d + alpha*p;
			r2 = r1 - alpha*prod(k,p);
			beta = inner_prod(r2,r2)/inner_prod(r1,r1);

			p = r2 + beta*p;

			r1 = r2;

			std::cout << "alpha: " << alpha << std::endl;
			std::cout << "d: \n" << d << std::endl;
			std::cout << "r: \n" << r2 << std::endl;

		} while ( norm_2(r2) > e*norm_2(f));
		cout << "iterations: " << iter << endl;
		std::cout << "d: \n" << d << std::endl;

		return ERR_OK;	
	}
}

