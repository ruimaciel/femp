#ifndef GRADIENT_FIELD_POLICY_H
#define GRADIENT_FIELD_POLICY_H

#include <GL/gl.h>

#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Element.hpp>
#include <libfemp/ElementResults/ResultsRanges.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Point3D.hpp>
#include <options/Options.hpp>
#include <vector>

/**
 * Defines the policy which is employed by GradientFieldRepresentationPolicy to
 *render each field
 **/
class GradientFieldPolicy {
	protected:
	typedef unsigned int gradient_index_t;

	GLfloat m_temp_color[3];  // temporary value used to set a color

	fem::Model* m_model;						   // pointer to the fem::Model structure, in order to
												   // access the materials list
	fem::AnalysisResult* m_analysis_result;		   // pointer to the current analysis result, needed to
												   // access the displacements field
	fem::ResultsRanges<double>* m_results_ranges;  // pointer to the current results ranges

	public:
	GradientFieldPolicy();
	virtual ~GradientFieldPolicy();

	void setModel(fem::Model& model);
	void setAnalysisResult(fem::AnalysisResult& result);
	void setResultsRanges(fem::ResultsRanges<double>& ranges);

	/**
	 * Converts a gradient value into a GLfloat [3]
	 * @param	gradient	the gradient's value
	 * @return	pointer to this->m_temp_color
	 **/
	GLfloat* getColor(float& gradient, ViewportColors& colors);

	/**
	 * Returns the gradient color according to a point in local coordinates
	 * @param p[1-9]	index
	 * @param pos	point in local coordinate system
	 * @param colors	object of type ViewportColors
	 **/
	GLfloat* tri3(fem::element_ref_t const& ref, gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, fem::Point3D& pos, ViewportColors& colors);
	GLfloat* tri6(fem::element_ref_t const& ref, gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5,
				  gradient_index_t p6, fem::Point3D& pos, ViewportColors& colors);
	GLfloat* quad4(fem::element_ref_t const& ref, gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, fem::Point3D& pos,
				   ViewportColors& colors);
	GLfloat* quad8(fem::element_ref_t const& ref, gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5,
				   gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, fem::Point3D& pos, ViewportColors& colors);
	GLfloat* quad9(fem::element_ref_t const& ref, gradient_index_t p1, gradient_index_t p2, gradient_index_t p3, gradient_index_t p4, gradient_index_t p5,
				   gradient_index_t p6, gradient_index_t p7, gradient_index_t p8, gradient_index_t p9, fem::Point3D& pos, ViewportColors& colors);

	protected:
	/**
	 * returns the gradient value for each result
	 **/
	virtual float val(fem::element_ref_t const& ref, gradient_index_t const& p) const = 0;
	virtual float maxVal(fem::ResultsRanges<double> const&) const = 0;
	virtual float minVal(fem::ResultsRanges<double> const&) const = 0;
};

#endif	// GRADIENT_FIELD_POLICY_H
