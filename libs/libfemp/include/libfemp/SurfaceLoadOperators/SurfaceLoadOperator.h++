#ifndef FEMP_SURFACELOADOPERATORS_SURFACELOADOPERATOR_HPP
#define FEMP_SURFACELOADOPERATORS_SURFACELOADOPERATOR_HPP

#include <libfemp/Model.h++>
#include <libfemp/loads/SurfaceLoad.h++>

namespace fem {

/**
 * Abstract base class for an operator which is applied to a surface load
 */
class SurfaceLoadOperator {
	public:
	/**
	 * functor
	 */
	virtual void operator()(fem::SurfaceLoad& surface_load, fem::Model& model) = 0;
};

}  // namespace fem

#endif
