#include "StressFieldRepresentationPolicy.h++"
#include "StressField/StressFieldFactory.h++"

#include <iostream>	// debugging purposes
#include <limits>	// for infinite

// Constructors/Destructors
//  

StressFieldRepresentationPolicy::StressFieldRepresentationPolicy ( ) 
{
	m_model = nullptr;
	m_result = nullptr;
	m_negative_principal_stress_visible = true;
	m_positive_principal_stress_visible = true;

	m_diameter = std::numeric_limits<float>::infinity();	// initial value
}


//  
// Methods
//  

void 
StressFieldRepresentationPolicy::renderTensor( fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color)
{
	fem::point p;	
	fem::point c;	// center point
	float diameter = 0.40f;

	c.zero();
	for(auto n: element.nodes)
	{
		c += m_model->node_list[n];
	}
	c *= 1.0/element.nodes.size();

	// set element diameter
	diameter = 0.5f*(m_model->node_list[ element.nodes[1]] - m_model->node_list[ element.nodes[0]]).norm();

	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	for(int k = 0; k < 3; k++)
	{
		if( ( (m_result->results[ref]->eig_val[k] > 0) && m_positive_principal_stress_visible ) || 
				( (m_result->results[ref]->eig_val[k] < 0) && m_negative_principal_stress_visible ) )
		{
			float dim = m_result->results[ref]->eig_vec[0][k]*m_result->results[ref]->eig_vec[0][k] + m_result->results[ref]->eig_vec[1][k]*m_result->results[ref]->eig_vec[1][k]+ m_result->results[ref]->eig_vec[2][k]*m_result->results[ref]->eig_vec[2][k];
			p.data[0] = m_result->results[ref]->eig_vec[0][k]*diameter/dim;
			p.data[1] = m_result->results[ref]->eig_vec[1][k]*diameter/dim;
			p.data[2] = m_result->results[ref]->eig_vec[2][k]*diameter/dim;

			//let color reflect the tension value
			getColor(m_result->results[ref]->eig_val[k], color);
			glColor3fv( m_temp_color );

			glVertex3dv((c-p).data);
			glVertex3dv((c+p).data);
		}
	}
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
}


void
StressFieldRepresentationPolicy::tetra4 (fem::element_ref_t const &ref, fem::Element &, ViewportColors &color, DisplacementsRepresentationPolicy *)
{
	assert(m_model != nullptr);
	assert(m_result != nullptr);

	m_representation[ref].render(m_diameter, m_max, m_min, color);
}


/**
 */
void
StressFieldRepresentationPolicy::tetra10 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	assert(m_model != nullptr);
	assert(m_result != nullptr);

	m_representation[ref].render(m_diameter, m_max, m_min, color);
}
 

/**
 */
void
StressFieldRepresentationPolicy::hexa8 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	m_representation[ref].render(m_diameter, m_max, m_min, color);
}


/**
 */
void
StressFieldRepresentationPolicy::hexa20 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	m_representation[ref].render(m_diameter, m_max, m_min, color);	
}


/**
 */
void
StressFieldRepresentationPolicy::hexa27 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	m_representation[ref].render(m_diameter, m_max, m_min, color);
}


/**
 */
void
StressFieldRepresentationPolicy::prism6 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	m_representation[ref].render(m_diameter, m_max, m_min, color);
}


/**
 */
void
StressFieldRepresentationPolicy::prism15 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	m_representation[ref].render(m_diameter, m_max, m_min, color);
}


/**
 */
void
StressFieldRepresentationPolicy::prism18 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	m_representation[ref].render(m_diameter, m_max, m_min, color);
}


void 
StressFieldRepresentationPolicy::setModel(fem::Model &model)
{
	m_model = &model;
}


void 
StressFieldRepresentationPolicy::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	m_result = &result;

	// updates all values needed to represent the stress field
	generateData();
}


void 
StressFieldRepresentationPolicy::showNegativePrincipalStressesVisibility(bool state)
{
	m_negative_principal_stress_visible = state;
}


void
StressFieldRepresentationPolicy::showPositivePrincipalStressesVisibility(bool state)
{
	m_positive_principal_stress_visible = state;
}


GLfloat *
StressFieldRepresentationPolicy::getColor(double &gradient, ViewportColors &colors)
{
	assert(m_model != NULL);
	assert(m_result != NULL);

	if(gradient > m_result->ranges.max_tension)
	{
		this->m_temp_color[0] = colors.field_maximum_positive[0];
		this->m_temp_color[1] = colors.field_maximum_positive[1];
		this->m_temp_color[2] = colors.field_maximum_positive[2];
	}
	else if(gradient < m_result->ranges.max_compression)
	{
		this->m_temp_color[0] = colors.field_maximum_negative[0];
		this->m_temp_color[1] = colors.field_maximum_negative[1];
		this->m_temp_color[2] = colors.field_maximum_negative[2];
	}
	else if(gradient > 0)
	{
		// interpolate between neutral and maximum
		float csi[3] = { 0, (float)m_result->ranges.max_tension/3, (float)m_result->ranges.max_tension };
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
		float csi[3] = { 0, (float)m_result->ranges.max_compression/3, (float)m_result->ranges.max_compression };
		float N1 = ( (gradient - csi[0])/(csi[2]-csi[0]) )*( (gradient - csi[1])/(csi[2]-csi[1]));
		float N2 = ( (gradient - csi[0])/(csi[1]-csi[0]) )*( (gradient - csi[2])/(csi[1]-csi[2]));
		float N3 = ( (gradient - csi[2])/(csi[0]-csi[2]) )*( (gradient - csi[1])/(csi[0]-csi[1]));
		this->m_temp_color[0] = colors.field_maximum_negative[0]*N1 + colors.field_semi_maximum_negative[0]*N2 + colors.field_neutral[0]*N3;
		this->m_temp_color[1] = colors.field_maximum_negative[1]*N1 + colors.field_semi_maximum_negative[1]*N2 + colors.field_neutral[1]*N3;
		this->m_temp_color[2] = colors.field_maximum_negative[2]*N1 + colors.field_semi_maximum_negative[2]*N2 + colors.field_neutral[2]*N3;
	}


	return this->m_temp_color;
}


void 
StressFieldRepresentationPolicy::generateData()
{
	assert(m_model != NULL);

	StressFieldRepresentation::StressFieldFactory factory(m_diameter, *this->m_model, *this->m_result);

	//for(auto element: m_model->element_list)
	for( std::vector<fem::Element>::size_type n = 0; n < m_model->element_list.size(); n++)
	{
		m_representation[n] = factory(m_model->element_list[n]);
	}
}

