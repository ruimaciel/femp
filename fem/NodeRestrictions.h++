#ifndef NODE_RESTRICTIONS_HPP
#define NODE_RESTRICTIONS_HPP


namespace fem
{

class NodeRestrictions {
	public:
		bool dx, dy, dz;	// specifies the node displacement restrictions along the XX, YY and ZZ axis
		bool rx, ry, rz;	// and rotation

	public:
		NodeRestrictions ();
		NodeRestrictions (const NodeRestrictions &);
		~NodeRestrictions ();
};

}

#endif
