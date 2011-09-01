#include "GradientFieldPolicy.h++"

#include <assert.h>


// Constructors/Destructors
GradientFieldPolicy::GradientFieldPolicy(ViewportColors &colors)
{
	this->m_gradient_value.reserve(27);	// maximum number of values used to render each element
	this->m_viewport_colors = &colors;
}


// Methods

void 
GradientFieldPolicy::setMaximumGradientValue (float new_maximum)
{
	this->m_max_value = new_maximum;
}


void 
GradientFieldPolicy::setMinimumGradientValue (float new_minimum)
{
	this->m_min_value = new_minimum;
}


GLfloat *
GradientFieldPolicy::getColor(float &gradient)
{
	assert(this->m_viewport_colors != NULL);

	if(gradient > this->m_max_value)
	{
		this->m_temp_color[0] = this->m_viewport_colors->field_maximum_positive[0];
		this->m_temp_color[1] = this->m_viewport_colors->field_maximum_positive[1];
		this->m_temp_color[2] = this->m_viewport_colors->field_maximum_positive[2];
	}
	else if(gradient < this->m_min_value)
	{
		this->m_temp_color[0] = this->m_viewport_colors->field_maximum_negative[0];
		this->m_temp_color[1] = this->m_viewport_colors->field_maximum_negative[1];
		this->m_temp_color[2] = this->m_viewport_colors->field_maximum_negative[2];
	}
	else if(gradient > 0)
	{
		// interpolate between neutral and maximum
		float xf = (gradient - 0)/(this->m_max_value);
		float xi = (this->m_max_value - gradient)/this->m_max_value;
		this->m_temp_color[0] = this->m_viewport_colors->field_maximum_positive[0]*xf + this->m_viewport_colors->field_neutral[0]*xi;
		this->m_temp_color[1] = this->m_viewport_colors->field_maximum_positive[1]*xf + this->m_viewport_colors->field_neutral[1]*xi;
		this->m_temp_color[2] = this->m_viewport_colors->field_maximum_positive[2]*xf + this->m_viewport_colors->field_neutral[2]*xi;
	}
	else
	{
		// interpolate between neutral and minimum
		float xf = (gradient - 0)/(this->m_min_value);
		float xi = (this->m_min_value - gradient)/this->m_min_value;
		this->m_temp_color[0] = this->m_viewport_colors->field_maximum_negative[0]*xf + this->m_viewport_colors->field_neutral[0]*xi;
		this->m_temp_color[1] = this->m_viewport_colors->field_maximum_negative[1]*xf + this->m_viewport_colors->field_neutral[1]*xi;
		this->m_temp_color[2] = this->m_viewport_colors->field_maximum_negative[2]*xf + this->m_viewport_colors->field_neutral[2]*xi;
	}

	return this->m_temp_color;
}


GLfloat * 
GradientFieldPolicy::tri3 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3,   fem::point &pos)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	gradient = m_gradient_value[p1]*(1-pos.x() - pos.y()) +  m_gradient_value[p2]*pos.x() + m_gradient_value[p3]*pos.y();

	// return the color
	return this->getColor(gradient);
}


GLfloat * 
GradientFieldPolicy::tri6 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, fem::point &pos)
{
	float gradient = 0;

	// interpolate between the values p1..p6
	//TODO finish this

	// return the color
	return this->getColor(gradient);
}


GLfloat * 
GradientFieldPolicy::quad4 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, fem::point &pos)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	//TODO finish this

	// return the color
	return this->getColor(gradient);
}


GLfloat * 
GradientFieldPolicy::quad8 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, fem::point &pos)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	//TODO finish this

	// return the color
	return this->getColor(gradient);
}


GLfloat * 
GradientFieldPolicy::quad9 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, gradient_index_t p9, fem::point &pos)
{
	float gradient = 0;

	// interpolate between the values p1, p2 and p3
	//TODO finish this

	// return the color
	return this->getColor(gradient);
}


