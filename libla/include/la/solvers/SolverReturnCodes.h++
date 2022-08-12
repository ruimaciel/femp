#ifndef LALIB_SOLVERS_RETURN_CODES_HPP
#define LALIB_SOLVERS_RETURN_CODES_HPP

namespace lalib {
enum ReturnCode {
	OK = 0,
	ERR_EXCESSIVE_ITERATIONS,
	ERR_NOT_SQUARE,
	ERR_SINGULAR_MATRIX

};
}

#endif
