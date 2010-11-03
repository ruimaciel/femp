#include "SGCSurface.h++"


#include "Logs.h++"	// declare the global message loggers


SGCSurface::SGCSurface()
{
}


SGCSurface::~SGCSurface()
{
}


void SGCSurface::setReferenceSurface(fem::Surface &referenced_surface)
{
	this->surface = &referenced_surface;

	//TODO adjust boundary to this surface
}


void SGCSurface::paintGL()
{
	mylog.setPrefix("SGCSurface::paintGL()");
	
	//TODO must implement this
	mylog.message("yet to be implemented");
}

