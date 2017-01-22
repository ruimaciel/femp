#include "StressTensor.h++"



namespace StressFieldRepresentation
{


void 
StressTensor::render(float const &diameter, float const &max, float const &min, bool const &render_positive, bool const &render_negative, ViewportColors const &colors)
{
	fem::Point p;	
	std::array<GLfloat, 3> color;

	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	for(int k = 0; k < 3; k++)
	{
		//let color reflect the tension value
		if( (this->m_stress[k] > 0 && render_positive) || (this->m_stress[k] < 0 && render_negative))
		{
			setColor(this->m_stress[k], max, min, color, colors);
			glColor3fv( color.data() );

			glVertex3dv((m_position-m_direction[k]*diameter).data);
			glVertex3dv((m_position+m_direction[k]*diameter).data);
		}
	}
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
}


void 
StressTensor::setColor(float const &gradient, float const &max, float const &min,  std::array<GLfloat, 3> &color, ViewportColors const &colors)
{
	if(gradient > max)
	{
		color[0] = colors.field_maximum_positive[0];
		color[1] = colors.field_maximum_positive[1];
		color[2] = colors.field_maximum_positive[2];
	}
	else if(gradient < min)
	{
		color[0] = colors.field_maximum_negative[0];
		color[1] = colors.field_maximum_negative[1];
		color[2] = colors.field_maximum_negative[2];
	}
	else if(gradient > 0)
	{
		// interpolate between neutral and maximum
		float csi[3] = { 0, max/3, max };
		float N1 = ( (gradient - csi[0])/(csi[2]-csi[0]) )*( (gradient - csi[1])/(csi[2]-csi[1]));
		float N2 = ( (gradient - csi[0])/(csi[1]-csi[0]) )*( (gradient - csi[2])/(csi[1]-csi[2]));
		float N3 = ( (gradient - csi[2])/(csi[0]-csi[2]) )*( (gradient - csi[1])/(csi[0]-csi[1]));
		color[0] = colors.field_maximum_positive[0]*N1 + colors.field_semi_maximum_positive[0]*N2 + colors.field_neutral[0]*N3;
		color[1] = colors.field_maximum_positive[1]*N1 + colors.field_semi_maximum_positive[1]*N2 + colors.field_neutral[1]*N3;
		color[2] = colors.field_maximum_positive[2]*N1 + colors.field_semi_maximum_positive[2]*N2 + colors.field_neutral[2]*N3;
	}
	else
	{
		// interpolate between neutral and minimum
		float csi[3] = { 0, min/3, min };
		float N1 = ( (gradient - csi[0])/(csi[2]-csi[0]) )*( (gradient - csi[1])/(csi[2]-csi[1]));
		float N2 = ( (gradient - csi[0])/(csi[1]-csi[0]) )*( (gradient - csi[2])/(csi[1]-csi[2]));
		float N3 = ( (gradient - csi[2])/(csi[0]-csi[2]) )*( (gradient - csi[1])/(csi[0]-csi[1]));
		color[0] = colors.field_maximum_negative[0]*N1 + colors.field_semi_maximum_negative[0]*N2 + colors.field_neutral[0]*N3;
		color[1] = colors.field_maximum_negative[1]*N1 + colors.field_semi_maximum_negative[1]*N2 + colors.field_neutral[1]*N3;
		color[2] = colors.field_maximum_negative[2]*N1 + colors.field_semi_maximum_negative[2]*N2 + colors.field_neutral[2]*N3;
	}
}


}	// namespace StressFieldRepresentation


