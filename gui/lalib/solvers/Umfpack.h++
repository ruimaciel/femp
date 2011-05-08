#ifndef LALIB_SOLVERS_UMFPACK_HPP
#define LALIB_SOLVERS_UMFPACK_HPP


#include <iostream>	//TODO remove after debugging
#include <vector>
#include <umfpack.h>

#include "SolverReturnCodes.h++"

#include "../Matrix.h++"
#include "../Vector.h++"


namespace lalib
{

/**
Umfpack routine
**/
ReturnCode umfpack(Matrix<double, SparseCCS> &A, Vector<double> &x, Vector<double> &b)
{
	assert(A.rows() == A.columns());
	assert(A.columns() == b.size());

	x.resize(A.rows());

	std::vector<int> Ap;
	Ap.resize(A.data.column_pointer.size());
	for(size_t i = 0; i < A.data.column_pointer.size(); i++)
	{
		Ap[i] = (int)A.data.column_pointer[i];
	}
	std::vector<int> Ai;
	Ai.resize(A.data.row_index.size());
	for(size_t i = 0; i < A.data.row_index.size(); i++)
	{
		Ai[i] = (int)A.data.row_index[i];
	}

	void *Numeric = NULL;
	void *Symbolic = NULL;

	double *null = (double *) NULL ;

	long int row = A.rows();
	long int column = A.columns();

	(void) umfpack_di_symbolic (row, column, &Ap[0], &Ai[0], &A.data.values[0], &Symbolic, null, null) ;
	(void)umfpack_di_numeric (&Ap[0], &Ai[0], &A.data.values[0], Symbolic, &Numeric, null, null);
	
	umfpack_di_free_symbolic (&Symbolic) ;

	(void) umfpack_di_solve (UMFPACK_A, &Ap[0], &Ai[0], &A.data.values[0], &x.data[0], &b.data[0], Numeric, null, null) ;
	//umfpack_dl_free_numeric (&Numeric) ;


	return OK;
}

}
#endif
