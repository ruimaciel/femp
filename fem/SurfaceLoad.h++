#ifndef SURFACE_LOAD_HPP
#define SURFACE_LOAD_HPP


namespace fem
{

class SurfaceLoad
{
	public:
		//short surface;	// speficies the element's surface where this force is applied
		double force[3];	// force acting paralel to XX, YY and ZZ

	public:
		SurfaceLoad();
		SurfaceLoad(const SurfaceLoad &);
		~SurfaceLoad();
};

}
#endif
