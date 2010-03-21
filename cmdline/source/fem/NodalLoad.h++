#ifndef NODAL_LOAD_HPP
#define NODAL_LOAD_HPP

#include "point.h++"

namespace fem
{
	class NodalLoad {
		public:
			point force;	// the force being applied in this node

		public:
			NodalLoad ();
			NodalLoad (const NodalLoad &);
			~NodalLoad ();


			double x()	const {return force.x();};
			double y()	const {return force.y();};
			double z()	const {return force.z();};

	};
}

#endif
