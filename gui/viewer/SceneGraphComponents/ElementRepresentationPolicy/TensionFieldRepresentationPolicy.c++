#include "TensionFieldRepresentationPolicy.h++"

#include <iostream>	// debugging purposes

// Constructors/Destructors
//  

TensionFieldRepresentationPolicy::TensionFieldRepresentationPolicy ( ) 
{
	m_model = nullptr;
	m_result = nullptr;
	m_negative_principal_tension_visible = true;
	m_positive_principal_tension_visible = true;
}

TensionFieldRepresentationPolicy::~TensionFieldRepresentationPolicy ( ) 
{ 
}

//  
// Methods
//  

void 
TensionFieldRepresentationPolicy::renderTensor( fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color)
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
	glBegin(GL_LINES);
	for(int k = 0; k < 3; k++)
	{
		if( ( (m_result->results[ref]->eig_val[k] > 0) && m_positive_principal_tension_visible ) || 
				( (m_result->results[ref]->eig_val[k] < 0) && m_negative_principal_tension_visible ) )
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
	glDisable(GL_BLEND);
}


void
TensionFieldRepresentationPolicy::tetra4 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	assert(m_model != nullptr);
	assert(m_result != nullptr);

	renderTensor(ref,element,color);

}


/**
 */
void
TensionFieldRepresentationPolicy::tetra10 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	renderTensor(ref,element,color);
}
 

/**
 */
void
TensionFieldRepresentationPolicy::hexa8 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	renderTensor(ref, element, color);
}


/**
 */
void
TensionFieldRepresentationPolicy::hexa20 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	renderTensor(ref,element,color);
}


/**
 */
void
TensionFieldRepresentationPolicy::hexa27 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	renderTensor(ref,element,color);
}


/**
 */
void
TensionFieldRepresentationPolicy::prism6 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	renderTensor(ref,element,color);
}


/**
 */
void
TensionFieldRepresentationPolicy::prism15 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	renderTensor(ref,element,color);
}


/**
 */
void
TensionFieldRepresentationPolicy::prism18 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	renderTensor(ref,element,color);
}


void 
TensionFieldRepresentationPolicy::setModel(fem::Model &model)
{
	m_model = &model;
}


void 
TensionFieldRepresentationPolicy::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	m_result = &result;
}


void 
TensionFieldRepresentationPolicy::showNegativePrincipalStressesVisibility(bool state)
{
	m_negative_principal_tension_visible = state;
}


void
TensionFieldRepresentationPolicy::showPositivePrincipalStressesVisibility(bool state)
{
	m_positive_principal_tension_visible = state;
}


GLfloat *
TensionFieldRepresentationPolicy::getColor(double &gradient, ViewportColors &colors)
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

