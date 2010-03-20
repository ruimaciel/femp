#include "NodalDisplacement.h++"

namespace fem
{
	NodalDisplacement::NodalDisplacement ()
	{
	}


	NodalDisplacement::NodalDisplacement (const NodalDisplacement &copied)
	{
		this->displacement = copied.displacement;
	}

	NodalDisplacement::~NodalDisplacement ()
	{
	}
}

