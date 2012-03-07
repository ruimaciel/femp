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
	glColor3fv( color.field_maximum_positive );
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


