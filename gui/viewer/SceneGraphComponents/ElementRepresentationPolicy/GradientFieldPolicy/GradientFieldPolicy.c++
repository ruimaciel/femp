#include "GradientFieldPolicy.h++"

#include <assert.h>


// Constructors/Destructors
GradientFieldPolicy::GradientFieldPolicy()
{
	this->m_gradient_value.reserve(27);	// maximum number of values used to render each element
	this->m_model	= NULL;
	this->m_analysis_result = NULL;
	this->m_max_value = this->m_min_value = 0;
}


// Methods

void 
GradientFieldPolicy::setMaximumGradientValue (float new_maximum)
{
	this->m_max_value = new_maximum;
}


void 
GradientFieldPolicy::setModel(fem::Model &model)
{
	this->m_model = &model;
}


void 
GradientFieldPolicy::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	this->m_analysis_result = &result;
}


void 
GradientFieldPolicy::setMinimumGradientValue (float new_minimum)
{
	this->m_min_value = new_minimum;
}


GLfloat *
GradientFieldPolicy::getColor(float &gradient, ViewportColors &colors)
{
	assert(m_model != NULL);
	assert(m_analysis_result != NULL);

	if(gradient > this->m_max_value)
	{
		this->m_temp_color[0] = colors.field_maximum_positive[0];
		this->m_temp_color[1] = colors.field_maximum_positive[1];
		this->m_temp_color[2] = colors.field_maximum_positive[2];
	}
	else if(gradient < this->m_min_value)
	{
		this->m_temp_color[0] = colors.field_maximum_negative[0];
		this->m_temp_color[1] = colors.field_maximum_negative[1];
		this->m_temp_color[2] = colors.field_maximum_negative[2];
	}
	else if(gradient > 0)
	{
		// interpolate between neutral and maximum
		float xf = (gradient - 0)/(this->m_max_value);
		float xi = (this->m_max_value - gradient)/this->m_max_value;
		this->m_temp_color[0] = colors.field_maximum_positive[0]*xf + colors.field_neutral[0]*xi;
		this->m_temp_color[1] = colors.field_maximum_positive[1]*xf + colors.field_neutral[1]*xi;
		this->m_temp_color[2] = colors.field_maximum_positive[2]*xf + colors.field_neutral[2]*xi;
	}
	else
	{
		// interpolate between neutral and minimum
		float xf = (gradient - 0)/(this->m_min_value);
		float xi = (this->m_min_value - gradient)/this->m_min_value;
		this->m_temp_color[0] = colors.field_maximum_negative[0]*xf + colors.field_neutral[0]*xi;
		this->m_temp_color[1] = colors.field_maximum_negative[1]*xf + colors.field_neutral[1]*xi;
		this->m_temp_color[2] = colors.field_maximum_negative[2]*xf + colors.field_neutral[2]*xi;
	}

	return this->m_temp_color;
}


GLfloat * 
GradientFieldPolicy::tri3 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3,   fem::point &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	gradient = m_gradient_value[p1]*(1-pos.x() - pos.y()) +  m_gradient_value[p2]*pos.x() + m_gradient_value[p3]*pos.y();

	// return the color
	return this->getColor(gradient, colors);
}


GLfloat * 
GradientFieldPolicy::tri6 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, fem::point &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1..p6
	float N1 = (2*(1-pos.x() - pos.y()) - 1)*(1- pos.x() - pos.y() ) ;
	float N2 = pos.x()*(2* pos.x() - 1);
	float N3 = pos.y()*(2* pos.y() - 1);
	float N4 = 4*pos.x()*(1-pos.x() - pos.y());
	float N5 = 4*pos.x()*pos.y();
	float N6 = 4*pos.y()*(1-pos.x() - pos.y());
	gradient = m_gradient_value[p1]*N1 + m_gradient_value[p2]*N2 + m_gradient_value[p3]*N3 + m_gradient_value[p4]*N4 + m_gradient_value[p5]*N5 + m_gradient_value[p6]*N6 ;

	// return the color
	return this->getColor(gradient, colors);
}


GLfloat * 
GradientFieldPolicy::quad4 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, fem::point &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	float N1 = (1-pos.x())*(1-pos.y())/4.0;
	float N2 = (1+pos.x())*(1-pos.y())/4.0;
	float N3 = (1+pos.x())*(1+pos.y())/4.0;
	float N4 = (1-pos.x())*(1+pos.y())/4.0;

	gradient = m_gradient_value[p1]*N1 + m_gradient_value[p2]*N2 + m_gradient_value[p3]*N3 + m_gradient_value[p4]*N4;

	// return the color
	return this->getColor(gradient, colors);
}


#define X1 pos.x()
#define X2 pos.y()

GLfloat * 
GradientFieldPolicy::quad8 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, fem::point &pos, ViewportColors &colors)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	float N1 = (pos.x()-1)*(1-pos.y())*(1+pos.x()+pos.y())/4;
	float N2 = (X1 + 1)*(X2-1)*(X2-X1+1)/4.0;
	float N3 = (X1 + 1)*(X2 + 1)*(X2 + X1 - 1)/4.0;
	float N4 = (1 - X1)*(X2 + 1)*(X2 - X1 - 1)/4.0;
	float N5 = (1-X1*X2)*(1-X2)/2.0;
	float N6 = (X1 + 1)*(1 - X2*X2)/2.0;
	float N7 = (1 - X1*X1)*(X2 + 1)/2.0;
	float N8 = (1-X1)*(1-X2*X2)/2.0;

	gradient = m_gradient_value[p1]*N1 + m_gradient_value[p2]*N2 + m_gradient_value[p3]*N3 + m_gradient_value[p4]*N4 + m_gradient_value[p5]*N5 + m_gradient_value[p6]*N6 + m_gradient_value[p7]*N7 + m_gradient_value[p8]*N8;

	// return the color
	return this->getColor(gradient, colors);
}


GLfloat * 
GradientFieldPolicy::quad9 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, gradient_index_t p9, fem::point &pos, ViewportColors &colors)
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

	gradient = m_gradient_value[p1]*N1 + m_gradient_value[p2]*N2 + m_gradient_value[p3]*N3 + m_gradient_value[p4]*N4 + m_gradient_value[p5]*N5 + m_gradient_value[p6]*N6 + m_gradient_value[p7]*N7 + m_gradient_value[p8]*N8 + m_gradient_value[p9]*N9;

	// return the color
	return this->getColor(gradient, colors);
}
#undef X1
#undef X2


