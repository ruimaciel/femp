#ifndef FIELD_SURFACE_HPP
#define FIELD_SURFACE_HPP

#include "../../ViewportData.h++"
#include "../../../fem/Project.h++"
#include "../../ViewportColors.h++"
#include "../../../fem/Surface.h++"

#include <vector>
#include "../../../fem/point.h++"


/**
Base class for all FieldSurface classes
**/
class FieldSurface
{
	protected:
		std::vector<fem::point> color_value;	// stores the color value for each node
		
	public:
		FieldSurface();
		virtual void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface) = 0;
};



FieldSurface::FieldSurface()
{
	this->color_value.clear();
}

#endif
