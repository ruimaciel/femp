#ifndef NODAL_DISPLACEMENT_HPP
#define NODAL_DISPLACEMENT_HPP

#include "point.h++"

namespace fem
{
	class NodalDisplacement {
		public:
			point displacement;

		public:
			NodalDisplacement ();
			NodalDisplacement (const NodalDisplacement &copied);
			~NodalDisplacement ();

	};
}

#endif
