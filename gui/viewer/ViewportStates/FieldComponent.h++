#ifndef FIELD_COMPONENT_HPP
#define FIELD_COMPONENT_HPP

#include <vector>

#include "../../fem/Project.h++"
#include "../../fem/AnalysisResult.h++"
#include "../../fem/Surface.h++"
#include "../../fem/point.h++"
#include "../ViewportColors.h++"


/**
State pattern which defines the color values in each node
**/
class FieldComponent
{
	public:
		/**
		@param color_map	reference to the list of colors 
		@param project		reference to the project
		@param result
		@param surface
		*/
		virtual void Quad4(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color) = 0;
		virtual void Quad8(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color) = 0;
		virtual void Quad9(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color) = 0;
		virtual void Triangle3(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color) = 0;
		virtual void Triangle6(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color) = 0;

	protected:
		/**
		Interpolates a color between the maximum and minimum color
		**/
		void interpolate(fem::point &color, const double &max, const double &min, const double &value, GLfloat color_max[3], GLfloat color_neutral[3], GLfloat color_min[3])
		{
			double x;
			if(value > 0)
			{
				x = value/max;
				color.data[0] = color_max[0]*x - color_neutral[0]*(1-x);
				color.data[1] = color_max[1]*x - color_neutral[1]*(1-x);
				color.data[2] = color_max[2]*x - color_neutral[2]*(1-x);
			}
			else
			{
				x = -value/min;
				color.data[0] = color_min[0]*x - color_neutral[0]*(1-x);
				color.data[1] = color_min[1]*x - color_neutral[1]*(1-x);
				color.data[2] = color_min[2]*x - color_neutral[2]*(1-x);
			}
		}
};




#endif
