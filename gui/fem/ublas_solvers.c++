#include "ublas_solvers.h++"


namespace fem
{

boost::numeric::ublas::matrix<double> invert3by3(const boost::numeric::ublas::matrix<double> &M, double det)
{
	assert(M.size1() == 3);
	assert(M.size2() == 3);
	assert(det > 0);
	/*
	   (%i1) M: matrix([a,b,c],[d,e,f],[g,h,i]);
	   [ a  b  c ]
	   [         ]
	   (%o1)      [ d  e  f ]
	   [         ]
	   [ g  h  i ]

	   (%i2) N: invert(M), detout;
	   [ e i - f h  c h - b i  b f - c e ]
	   [                                 ]
	   [ f g - d i  a i - c g  c d - a f ]
	   [                                 ]
	   [ d h - e g  b g - a h  a e - b d ]
	   (%o2) ---------------------------------------------
	   a (e i - f h) + b (f g - d i) + c (d h - e g)
	 */

	boost::numeric::ublas::matrix<double> invJ(3,3);
	invJ(0,0) = (M(1,1)*M(2,2) - M(1,2)*M(2,1))/det;
	invJ(0,1) = (M(0,2)*M(2,1) - M(0,1)*M(2,2))/det;
	invJ(0,2) = (M(0,1)*M(1,2) - M(0,2)*M(1,1))/det;
	invJ(1,0) = (M(1,2)*M(2,0) - M(1,0)*M(2,2))/det;
	invJ(1,1) = (M(0,0)*M(2,2) - M(0,2)*M(2,0))/det;
	invJ(1,2) = (M(0,2)*M(1,0) - M(0,0)*M(1,2))/det;
	invJ(2,0) = (M(1,0)*M(2,1) - M(1,1)*M(2,0))/det;
	invJ(2,1) = (M(0,1)*M(2,0) - M(0,0)*M(2,1))/det;
	invJ(2,2) = (M(0,0)*M(1,1) - M(0,1)*M(1,0))/det;

	return invJ;
}


double det3by3(const boost::numeric::ublas::matrix<double> &M)
{
	assert(M.size1() == 3);
	assert(M.size2() == 3);
	return	M(0,0)*( M(1,1)*M(2,2) - M(1,2)*M(2,1)) + \
		M(0,1)*( M(1,2)*M(2,0) - M(1,0)*M(2,2)) + \
		M(0,2)*( M(1,0)*M(2,1) - M(1,1)*M(2,0));
}


bool solve_cholesky( boost::numeric::ublas::compressed_matrix<double> &A, boost::numeric::ublas::vector<double> &b)
{
	double s;
	for(size_t j = 0; j < A.size2(); j++)
	{
		for(size_t i = 0; i < A.size1(); i++)
		{
			s = A(i,j);
			for(size_t m = 0; m < j; m++)
			{
				s -= A(i,m)*A(j,m);
			}

			if(i == j)
			{
				if(s > 0)
				{
					A(j,j) = sqrt(s);
				}
				else
				{
					// matrix not positive definite
					return false;
				}
			}
			else
			{
				A(i,j) = s/A(j,j);
			}
		}
	}

	// solve Ly = b
	for (size_t i = 0; i < A.size1(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			b(i) -= A(i, j) * b(j);
		}
		b(i) /= A(i, i);
	}

	// Backward solve L'x = y
	for (size_t i = A.size1() - 1; i > 0; i--)
	{
		for (size_t j = i + 1; j < A.size2(); j++)
		{
			b(i) -= A(j, i) * b(j);
		}
		b(i) /= A(i, i);
	}
	for (size_t j = 1; j < A.size2(); j++)
	{
		b(0) -= A(j, 0) * b(j);
	}
	b(0) /= A(0, 0);

	return true;
}


bool solve_conjugate_gradient( boost::numeric::ublas::compressed_matrix<double> &A, boost::numeric::ublas::vector<double> &b, float e)
{
	using namespace std;

	boost::numeric::ublas::compressed_vector<double> r1;
	boost::numeric::ublas::compressed_vector<double> r2;
	boost::numeric::ublas::compressed_vector<double> p;
	boost::numeric::ublas::vector<double> d;
	double alpha;
	double beta;
	// size_t iter = 0;

	r1.resize(b.size());
	d.resize(b.size());

	// initialize the vector
	/*
	for(size_t i = 0; i < b.size(); i++)
	{
		d[i] = 1;
	}
	*/
	d = b;

	r1 = b - prec_prod(A,d);
	p = r1;
	r2 = r1;

	do
	{
		//iter++;
		alpha = inner_prod(r1,r1) / inner_prod(p,prec_prod(A,p));
		d = d + alpha*p;
		r2 = r1 - alpha*prec_prod(A,p);
		beta = inner_prod(r2,r2)/inner_prod(r1,r1);

		p = r2 + beta*p;

		r1 = r2;

		/*
		   std::cout << "alpha: " << alpha << std::endl;
		   std::cout << "d: \n" << d << std::endl;
		   std::cout << "r: \n" << r2 << std::endl;
		 */

	} while ( norm_2(r2) > e);

	/*
	   std::cout << "iterations: " << iter << endl;
	   std::cout << "d: \n" << d << std::endl;
	 */

	return true;	
}


bool solve_gauss( boost::numeric::ublas::compressed_matrix<double> &A, boost::numeric::ublas::vector<double> &b)
{
	//TODO implement partial pivoting

	using namespace std;

	assert(A.size1() == A.size2());
	double factor;
	size_t row[A.size1()];	// for the pivoting
	size_t temp;	// temporary pivot

	// initialize the row pivoting map
	for(size_t i = 0; i < A.size1(); i++)
		row[i] = i;

	// Gauss factorization
	for(size_t diag = 0; diag < A.size1(); diag++)
	{
		// choose pivot
		for(size_t i = diag+1; i < A.size1(); i++)
		{
			if(abs(A(row[i],diag)) > abs(A(row[diag],diag)) )
			{
				// cout << "pivot change: diag " << row[diag] << " for row " << row[i] << endl;
				temp = row[i];
				row[i] = row[diag];
				row[diag] = temp;
			}
		}

		// check if matrix is singular
		//TODO check if this is a decent test
		if( abs(A(row[diag],diag)) < 1e-16)
		{
			return false;
		}

		// reduce current line to 1 in diagonal
		factor = A(row[diag],diag);

		// normalize the current leading row
		for(size_t j = diag; j < A.size2(); j++)
		{
			A(row[diag],j) /= factor;
		}
		b(row[diag]) /= factor;

		// subtract from all the others
		for(size_t i = diag+1; i < A.size1(); i++)
		{
			factor = A(row[i],diag);
			//for(size_t j = diag; j < A.size2(); j++)
			for(size_t j = 0; j < A.size2(); j++)
			{
				A(row[i],j) -= factor*A(row[diag],j);
			}
			b(row[i]) -= factor*b(row[diag]);
		}
	}

	// back substitution
	for(size_t j = A.size1()-1; j > 0 ; j--)
	{
		for(size_t i = 0; i < j; i++)
		{
			b(row[i]) -= A(row[i],j)*b(row[j]);
		}
		// cout << endl;
	}

	// rearrange the tweaked pivots
	//TODO find a better way
	boost::numeric::ublas::vector<double> d;
	d.resize(b.size());
	for(size_t i = 0; i < b.size(); i++)
		d(i) = b(row[i]);
	b = d;

	// all went well
	return true;
}



}
