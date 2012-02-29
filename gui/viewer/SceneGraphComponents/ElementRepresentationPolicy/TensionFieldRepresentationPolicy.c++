#include "TensionFieldRepresentationPolicy.h++"

#include <iostream>	// debugging purposes

// Constructors/Destructors
//  

TensionFieldRepresentationPolicy::TensionFieldRepresentationPolicy ( ) 
{
	m_model = nullptr;
	m_result = nullptr;
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
		float dim = m_result->results[ref]->eig_vec[0][k]*m_result->results[ref]->eig_vec[0][k] + m_result->results[ref]->eig_vec[1][k]*m_result->results[ref]->eig_vec[1][k]+ m_result->results[ref]->eig_vec[2][k]*m_result->results[ref]->eig_vec[2][k];
		p.data[0] = m_result->results[ref]->eig_vec[0][k]*diameter/dim;
		p.data[1] = m_result->results[ref]->eig_vec[1][k]*diameter/dim;
		p.data[2] = m_result->results[ref]->eig_vec[2][k]*diameter/dim;

		glVertex3dv((c-p).data);
		glVertex3dv((c+p).data);
	}
	glEnd();
	glDisable(GL_BLEND);
}


	void
TensionFieldRepresentationPolicy::tetra4 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	assert(m_model != nullptr);
	assert(m_result != nullptr);

	std::cerr << "TensionFieldRepresentationPolicy::tetra4 ()" << std::endl;


	renderTensor(ref,element,color);

}


/**
 */
void
TensionFieldRepresentationPolicy::tetra10 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	std::cerr << "TensionFieldRepresentationPolicy::tetra10 ()" << std::endl;
}
 

/**
 */
void
TensionFieldRepresentationPolicy::hexa8 (fem::element_ref_t const &ref, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	// std::cerr << "TensionFieldRepresentationPolicy::hexa8 ()" << std::endl;

	renderTensor(ref, element, color);
}


/**
 */
void
TensionFieldRepresentationPolicy::hexa20 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	std::cerr << "TensionFieldRepresentationPolicy::hexa20 ()" << std::endl;
}


/**
 */
void
TensionFieldRepresentationPolicy::hexa27 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	std::cerr << "TensionFieldRepresentationPolicy::hexa27 ()" << std::endl;
}


/**
 */
void
TensionFieldRepresentationPolicy::prism6 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	std::cerr << "TensionFieldRepresentationPolicy::prism6 ()" << std::endl;
}


/**
 */
void
TensionFieldRepresentationPolicy::prism15 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	std::cerr << "TensionFieldRepresentationPolicy::prism15 ()" << std::endl;
}


/**
 */
void
TensionFieldRepresentationPolicy::prism18 (fem::element_ref_t const &, fem::Element &element, ViewportColors &color, DisplacementsRepresentationPolicy *displacements)
{
	std::cerr << "TensionFieldRepresentationPolicy::prism18 ()" << std::endl;
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


