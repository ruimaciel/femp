#ifndef GRADIENT_FIELD_POLICY_H
#define GRADIENT_FIELD_POLICY_H

#include <vector>
#include <GL/gl.h>

#include "../../../../fem/point.h++"
#include "../../../../fem/Element.h++"
#include "../../../../fem/Model.h++"
#include "../../../../fem/AnalysisResult.h++"
#include "../../../ViewportColors.h++"



/**
Defines the policy which is employed by GradientFieldRepresentationPolicy to render each field
**/
class GradientFieldPolicy 
{
protected:
	float m_max_value;	// the maximum gradient value which 
	float m_min_value;	
	std::vector<float>	m_gradient_value;	// gradient value on each node

	//typedef std::vector<float>::size_type gradient_index_t;
	typedef unsigned int gradient_index_t;

	GLfloat m_temp_color[3];	// temporary value used to set a color

	fem::Model	*m_model;	// pointer to the fem::Model structure, in order to access the materials list
	fem::AnalysisResult<double>	*m_analysis_result;	// pointer to the current analysis result, needed to access the displacements field
		
public:
	GradientFieldPolicy();

	// Fields
	// Accessor Methods
	// Operations
	
	/**
	Fills m_gradient_value with the gradients that are attributted to each node
	**/
	virtual void calculateGradientValues (fem::Element &element) = 0;
		
	void setModel(fem::Model &model);
	void setAnalysisResult(fem::AnalysisResult<double> &result);

	void setMaximumGradientValue (float new_maximum);
	void setMinimumGradientValue (float new_minimum);

	/**
	Converts a gradient value into a GLfloat [3]
	@param	gradient	the gradient's value
	@return	pointer to this->m_temp_color
	**/
	GLfloat * getColor(float &gradient, ViewportColors &colors);
	
	/**
	Returns the gradient color according to a point in local coordinates
	**/
	GLfloat * tri3 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3,   fem::point &pos, ViewportColors &colors);
	GLfloat * tri6 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, fem::point &pos, ViewportColors &colors);
	GLfloat * quad4 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, fem::point &pos, ViewportColors &colors);
	GLfloat * quad8 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, fem::point &pos, ViewportColors &colors);
	GLfloat * quad9 (gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5, gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, gradient_index_t p9, fem::point &pos, ViewportColors &colors);

};

#endif //GRADIENT_FIELD_POLICY_H

