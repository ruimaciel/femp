extern "C" {
#include <umfpack.h>
}

#include <la/solvers/Umfpack.h++>
#include <la/solvers/SolverReturnCodes.h++>


namespace lalib
{

/**
Umfpack routine
**/
ReturnCode
umfpack(Matrix<double, SparseCCS> &A, Vector<double> &x, Vector<double> &b, ProgressIndicatorStrategy *)
{
	assert(A.rows() == A.columns());
	assert(A.columns() == b.size());

	x.resize(A.rows());


	void *Numeric = nullptr;
	void *Symbolic = nullptr;

	double *null = (double *) NULL ;

	long int row = A.rows();
	long int column = A.columns();

	#define Ap A.data.column_pointer
	#define Ai A.data.row_index

	(void) umfpack_dl_symbolic (row, column, &Ap[0], &Ai[0], &A.data.values[0], &Symbolic, null, null) ;
	(void)umfpack_dl_numeric (&Ap[0], &Ai[0], &A.data.values[0], Symbolic, &Numeric, null, null);

	umfpack_dl_free_symbolic (&Symbolic) ;

	(void) umfpack_dl_solve (UMFPACK_A, &Ap[0], &Ai[0], &A.data.values[0], &x.data[0], &b.data[0], Numeric, null, null) ;
	//umfpack_dl_free_numeric (&Numeric) ;

	#undef Ap
	#undef Ai

	return OK;
}

}	// namespace lalib

