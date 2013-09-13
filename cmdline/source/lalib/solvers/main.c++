#include <stdio.h>
#include <vector>

#include <cholmod.h>
#include <cholmod_internal.h>

#include "../Matrix.h++"
#include "../Vector.h++"
#include "../Operations.h++"
#include "../output.h++"


int main (void)
{
	cholmod_sparse *A ;
	cholmod_triplet *T;
	cholmod_dense *x, *b, *r ;
	cholmod_factor *L ;
	double one [2] = {1,0}, m1 [2] = {-1,0} ;	    // basic scalars 
	cholmod_common c ;
	cholmod_start (&c) ;			    // start CHOLMOD 

	Int *Ti;
	Int *Tj;
	double *Tx;

	lalib::Matrix<double, lalib::SparseDOK> Ad;
	Ad.resize(5,5);

	Ad(0,0) = 1;	Ad(3,0) = 2;
	Ad(1,1) = 5;	Ad(1,2) = 6;
	Ad(2,1) = 6;	Ad(2,2) = 3;
					Ad(3,3) = 9;
							Ad(4,4) = 10;

	T = cholmod_allocate_triplet(Ad.rows(), Ad.columns(), Ad.data.data.size(), 0, CHOLMOD_REAL, &c);
	Ti = (Int *)T->i;
	Tj = (Int *)T->j;
	Tx = (double *)T->x;
	for(size_t n = 0; n < Ad.data.data.size(); n++)
	{
		Ti[n] = n/Ad.data.t_rows;
		Tj[n] = n%Ad.data.t_rows;
		Tx[n] = Ad.data.data[n];
	}


	cholmod_free_triplet(&T,&c);

	/*
	T = cholmod_read_triplet(stdin, &c);
	cholmod_print_triplet(T,"T",&c);
	A = cholmod_read_sparse (stdin, &c) ;	    // read in a matrix 
	cholmod_print_sparse (A, "A", &c) ;		    // print the matrix 
	if (A == NULL || A->stype == 0)		    // A must be symmetric 
	{
		cholmod_free_sparse (&A, &c) ;
		cholmod_finish (&c) ;
		return (0) ;
	}
	b = cholmod_ones (A->nrow, 1, A->xtype, &c) ;   // b = ones(n,1) 
	L = cholmod_analyze (A, &c) ;		    // analyze 
	cholmod_factorize (A, L, &c) ;		    // factorize 
	x = cholmod_solve (CHOLMOD_A, L, b, &c) ;	    // solve Ax=b 
	r = cholmod_copy_dense (b, &c) ;		    // r = b 
	cholmod_sdmult (A, 0, m1, one, x, r, &c) ;	    // r = r-Ax 
	printf ("norm(b-Ax) %8.1e\n",
			cholmod_norm_dense (r, 0, &c)) ;	    // print norm(r) 
	cholmod_free_factor (&L, &c) ;		    // free matrices 
	cholmod_free_sparse (&A, &c) ;
	cholmod_free_dense (&r, &c) ;
	cholmod_free_dense (&x, &c) ;
	cholmod_free_dense (&b, &c) ;
	*/
	
	cholmod_finish (&c) ;			    // finish CHOLMOD 
	return 0;
}
