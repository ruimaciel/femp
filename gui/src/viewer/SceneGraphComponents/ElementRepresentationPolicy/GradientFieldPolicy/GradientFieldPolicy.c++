#include "GradientFieldPolicy.h++"

#include <assert.h>
#include <iostream>


// Constructors/Destructors
GradientFieldPolicy::GradientFieldPolicy()
{
	this->m_model	= NULL;
	this->m_analysis_result = NULL;
	this->m_results_ranges = NULL;
}


// Methods

void 
GradientFieldPolicy::setModel(fem::Model &model)
{
	this->m_model = &model;
}


void 
GradientFieldPolicy::setAnalysisResult(fem::AnalysisResult &result)
{
	this->m_analysis_result = &result;
}


void 
GradientFieldPolicy::setResultsRanges(fem::ResultsRanges<double> &ranges)
{
	this->m_results_ranges = &ranges;
}


GLfloat *
GradientFieldPolicy::getColor(float &gradient, ViewportColors &colors)
{
	assert(m_model != NULL);
	assert(m_analysis_result != NULL);
	assert(m_results_ranges != NULL);

	if(gradient > this->maxVal(*m_results_ranges))
	{
		this->m_temp_color[0] = colors.field_maximum_positive[0];
		this->m_temp_color[1] = colors.field_maximum_positive[1];
		this->m_temp_color[2] = colors.field_maximum_positive[2];
	}
	else if(gradient < this->minVal(*m_results_ranges))
	{
		this->m_temp_color[0] = colors.field_maximum_negative[0];
		this->m_temp_color[1] = colors.field_maximum_negative[1];
		this->m_temp_color[2] = colors.field_maximum_negative[2];
	}
	else if(gradient > 0)
	{
		// interpolate between neutral and maximum
		float csi[3] = { 0, maxVal(*m_results_ranges)/3, maxVal(*m_results_ranges) };
		float N1 = ( (gradient - csi[0])/(csi[2]-csi[0]) )*( (gradient - csi[1])/(csi[2]-csi[1]));
		float N2 = ( (gradient - csi[0])/(csi[1]-csi[0]) )*( (gradient - csi[2])/(csi[1]-csi[2]));
		float N3 = ( (gradient - csi[2])/(csi[0]-csi[2]) )*( (gradient - csi[1])/(csi[0]-csi[1]));
		this->m_temp_color[0] = colors.field_maximum_positive[0]*N1 + colors.field_semi_maximum_positive[0]*N2 + colors.field_neutral[0]*N3;
		this->m_temp_color[1] = colors.field_maximum_positive[1]*N1 + colors.field_semi_maximum_positive[1]*N2 + colors.field_neutral[1]*N3;
		this->m_temp_color[2] = colors.field_maximum_positive[2]*N1 + colors.field_semi_maximum_positive[2]*N2 + colors.field_neutral[2]*N3;
	}
	else
	{
		// interpolate between neutral and minimum
		float csi[3] = { 0, minVal(*m_results_ranges)/3, minVal(*m_results_ranges) };
		float N1 = ( (gradient - csi[0])/(csi[2]-csi[0]) )*( (gradient - csi[1])/(csi[2]-csi[1]));
		float N2 = ( (gradient - csi[0])/(csi[1]-csi[0]) )*( (gradient - csi[2])/(csi[1]-csi[2]));
		float N3 = ( (gradient - csi[2])/(csi[0]-csi[2]) )*( (gradient - csi[1])/(csi[0]-csi[1]));
		this->m_temp_color[0] = colors.field_maximum_negative[0]*N1 + colors.field_semi_maximum_negative[0]*N2 + colors.field_neutral[0]*N3;
		this->m_temp_color[1] = colors.field_maximum_negative[1]*N1 + colors.field_semi_maximum_negative[1]*N2 + colors.field_neutral[1]*N3;
		this->m_temp_color[2] = colors.field_maximum_negative[2]*N1 + colors.field_semi_maximum_negative[2]*N2 + colors.field_neutral[2]*N3;
	}


	return this->m_temp_color;
}


GLfloat * 
GradientFieldPolicy::tri3 (fem::element_ref_t const &ref,gradient_index_t p1, gradient_index_t p2, gradient_index_t p3,   fem::Point3D &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	gradient = val(ref, p1)*(1-pos.x() - pos.y()) +  val(ref, p2)*pos.x() + val(ref, p3)*pos.y();

	// return the color
	return this->getColor(gradient, colors);
}


GLfloat * 
GradientFieldPolicy::tri6 (fem::element_ref_t const &ref,gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, fem::Point3D &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1..p6
	float N1 = (2*(1-pos.x() - pos.y()) - 1)*(1- pos.x() - pos.y() ) ;
	float N2 = pos.x()*(2* pos.x() - 1);
	float N3 = pos.y()*(2* pos.y() - 1);
	float N4 = 4*pos.x()*(1-pos.x() - pos.y());
	float N5 = 4*pos.x()*pos.y();
	float N6 = 4*pos.y()*(1-pos.x() - pos.y());

	gradient = val(ref, p1)*N1 + val(ref, p2)*N2 + val(ref, p3)*N3 + val(ref, p4)*N4 + val(ref, p5)*N5 + val(ref, p6)*N6 ;

	// return the color
	return this->getColor(gradient, colors);
}


GLfloat * 
GradientFieldPolicy::quad4 (fem::element_ref_t const &ref,gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, fem::Point3D &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	float N1 = (1-pos.x())*(1-pos.y())/4.0;
	float N2 = (1+pos.x())*(1-pos.y())/4.0;
	float N3 = (1+pos.x())*(1+pos.y())/4.0;
	float N4 = (1-pos.x())*(1+pos.y())/4.0;

	gradient = val(ref, p1)*N1 + val(ref, p2)*N2 + val(ref, p3)*N3 + val(ref, p4)*N4;

	// return the color
	return this->getColor(gradient, colors);
}


#define X1 pos.x()
#define X2 pos.y()

GLfloat * 
GradientFieldPolicy::quad8 (fem::element_ref_t const &ref,gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, fem::Point3D &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	float N1 = (X1-1)*(1-X2)*(1+X1+X2)/4;
	float N2 = (X1 + 1)*(X2-1)*(X2-X1+1)/4.0;
	float N3 = (X1 + 1)*(X2 + 1)*(X2 + X1 - 1)/4.0;
	float N4 = (1 - X1)*(X2 + 1)*(X2 - X1 - 1)/4.0;
	float N5 = (1-X1*X1)*(1-X2)/2.0;
	float N6 = (X1 + 1)*(1 - X2*X2)/2.0;
	float N7 = (1 - X1*X1)*(X2 + 1)/2.0;
	float N8 = (1-X1)*(1-X2*X2)/2.0;

	gradient = val(ref, p1)*N1 + val(ref, p2)*N2 + val(ref, p3)*N3 + val(ref, p4)*N4 + val(ref, p5)*N5 + val(ref, p6)*N6 + val(ref, p7)*N7 + val(ref, p8)*N8;

	// return the color
	return this->getColor(gradient, colors);
}


GLfloat * 
GradientFieldPolicy::quad9 (fem::element_ref_t const &ref,gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, gradient_index_t p9, fem::Point3D &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	float N1 = (X1-1)*X1*(X2-1)*X2/4;
	float N2 = X1*(X1+1)*(X2-1)*X2/4;
	float N3 = X1*(X1+1)*X2*(X2+1)/4;
	float N4 = (X1-1)*X1*X2*(X2+1)/4;
	float N5 = (1-X1)*(X1+1)*(X2-1)*X2/2;
	float N6 = X1*(X1+1)*(1-X2)*(X2+1)/2;
	float N7 = (1-X1)*(X1+1)*X2*(X2+1)/2;
	float N8 = (X1-1)*X1*(1-X2)*(X2+1)/2;
	float N9 = (1-X1)*(X1+1)*(1-X2)*(X2+1);

	gradient = val(ref, p1)*N1 + val(ref, p2)*N2 + val(ref, p3)*N3 + val(ref, p4)*N4 + val(ref, p5)*N5 + val(ref, p6)*N6 + val(ref, p7)*N7 + val(ref, p8)*N8 + val(ref, p9)*N9;

	// return the color
	return this->getColor(gradient, colors);
}
#undef X1
#undef X2


