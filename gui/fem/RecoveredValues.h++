#ifndef RECOVERED_VALUES_HPP
#define RECOVERED_VALUES_HPP



/**
Class intended to store all recovered values from an element.
The values are recovered in the element's nodes
**/
template<typename Scalar>
struct RecoveredValues
{
	// struct intended to store deformation values measured in a node 
	struct Values
	{
		Scalar e11, e22, e33, e12, e13, e23;
	};

	// the map between an element's node and it's recovered values
	std::map<size_t, Values> node;

};



#endif
