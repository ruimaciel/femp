#ifndef NODE_RESTRICTIONS_HPP
#define NODE_RESTRICTIONS_HPP


namespace fem
{

class NodeRestrictions {
	public:
		enum Type {NR_INVALID, NR_DX, NR_DY, NR_DZ};

	private:
		bool d[3];	// specifies the node displacement restrictions along the XX, YY and ZZ axis

	public:
		NodeRestrictions ();
		NodeRestrictions (const NodeRestrictions &);
		~NodeRestrictions ();

		void setdx()	{d[0] = true;}
		void setdy()	{d[1] = true;}
		void setdz()	{d[2] = true;}
		
		bool dx()	{return d[0];}
		bool dy()	{return d[1];}
		bool dz()	{return d[2];}

		/** small hand-written parser to extract meaning from a small string of text
		  @param buffer a string of text
		  @return NR_DX if buffer is "dx", NR_DY if buffer is "dy", NR_DZ if buffer is "dz", NR_INVALID if otherwise
		 **/
		static enum Type extractType(char * buffer);

		void reset();
};

}

#endif
