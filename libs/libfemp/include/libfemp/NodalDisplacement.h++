#ifndef FEMP_NODALDISPLACEMENT_HPP
#define FEMP_NODALDISPLACEMENT_HPP

// libfemp includes
#include <libfemp/Point3D.h++>

namespace fem {

class NodalDisplacement {
	public:
	Point3D displacement;

	public:
	NodalDisplacement();
	NodalDisplacement(const NodalDisplacement& copied);
	~NodalDisplacement();
};

}  // namespace fem

#endif
