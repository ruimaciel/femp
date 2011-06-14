#ifndef STRAIN_11
#define STRAIN_11

#include "FieldComponent.h++"


/**
State of the FieldComponent state pattern which sets the color scheme to render strains11
**/
class Strain11
	: public FieldComponent
{
	public:
		 void Quad4(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color);
		 void Quad8(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color);
		 void Quad9(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color);
		 void Triangle3(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color);
		 void Triangle6(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color);
};


void Strain11::Quad4(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color)
{
	for(size_t n = 0; n < 4; n++)
	{
		// gets the element which is referenced
		size_t element_reference = surface.elements[0].reference;

		RecoveredValues<double> recovered_values;	// the values for this element
		recovered_values = result.recovered_values[element_reference];

		double value;
		value = recovered_values.node[surface.elements[0].element_local_reference[n]].e11;

		// Strain11: e_11 = du_1/d_x1
		this->interpolate(color_map[n], result.maximum.e11, result.minimum.e11, value, color.field_maximum_positive, color.field_neutral, color.field_maximum_negative);
	}
}


void Strain11::Quad8(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color)
{
	for(size_t n = 0; n < 8; n++)
	{
		// gets the element which is referenced
		size_t element_reference = surface.elements[0].reference;

		RecoveredValues<double> recovered_values;	// the values for this element
		recovered_values = result.recovered_values[element_reference];

		double value;
		value = recovered_values.node[n].e11;

		// Strain11: e_11 = du_1/d_x1
		this->interpolate(color_map[n], result.maximum.e11, result.minimum.e11, value, color.field_maximum_positive, color.field_neutral, color.field_maximum_negative);
	}
}


void Strain11::Quad9(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color)
{
	for(size_t n = 0; n < 9; n++)
	{
		// gets the element which is referenced
		size_t element_reference = surface.elements[0].reference;

		RecoveredValues<double> recovered_values;	// the values for this element
		recovered_values = result.recovered_values[element_reference];

		double value;
		value = recovered_values.node[n].e11;

		// Strain11: e_11 = du_1/d_x1
		this->interpolate(color_map[n], result.maximum.e11, result.minimum.e11, value, color.field_maximum_positive, color.field_neutral, color.field_maximum_negative);
	}
}


void Strain11::Triangle3(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color)
{
	for(size_t n = 0; n < 3; n++)
	{
		// gets the element which is referenced
		size_t element_reference = surface.elements[0].reference;

		RecoveredValues<double> recovered_values;	// the values for this element
		recovered_values = result.recovered_values[element_reference];

		double value;
		value = recovered_values.node[n].e11;

		// Strain11: e_11 = du_1/d_x1
		this->interpolate(color_map[n], result.maximum.e11, result.minimum.e11, value, color.field_maximum_positive, color.field_neutral, color.field_maximum_negative);
	}
}


void Strain11::Triangle6(std::vector<fem::point> &color_map, fem::Project &project, fem::AnalysisResult<double> &result, fem::Surface &surface, ViewportColors &color)
{
	for(size_t n = 0; n < 6; n++)
	{
		// gets the element which is referenced
		size_t element_reference = surface.elements[0].reference;

		RecoveredValues<double> recovered_values;	// the values for this element
		recovered_values = result.recovered_values[element_reference];

		double value;
		value = recovered_values.node[n].e11;

		// Strain11: e_11 = du_1/d_x1
		this->interpolate(color_map[n], result.maximum.e11, result.minimum.e11, value, color.field_maximum_positive, color.field_neutral, color.field_maximum_negative);
	}
}


#endif
