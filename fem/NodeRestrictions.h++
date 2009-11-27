#ifndef NODE_RESTRICTIONS_HPP
#define NODE_RESTRICTIONS_HPP


namespace fem
{

class NodeRestrictions {
	public:
		enum Type {NR_INVALID, NR_DX, NR_DY, NR_DZ, NR_RX, NR_RY, NR_RZ};

	private:
		bool d[3];	// specifies the node displacement restrictions along the XX, YY and ZZ axis
		bool r[3];	// and rotation

	public:
		NodeRestrictions ();
		NodeRestrictions (const NodeRestrictions &);
		~NodeRestrictions ();

		void setdx()	{d[0] = true;}
		void setdy()	{d[1] = true;}
		void setdz()	{d[2] = true;}
		void setrx()	{r[0] = true;}
		void setry()	{r[1] = true;}
		void setrz()	{r[2] = true;}
		
		bool dx()	{return d[0];}
		bool dy()	{return d[1];}
		bool dz()	{return d[2];}
		bool rx()	{return r[0];}
		bool ry()	{return r[1];}
		bool rz()	{return r[2];}

		static enum Type extractType(char *);
		void reset();
};

}

#endif
