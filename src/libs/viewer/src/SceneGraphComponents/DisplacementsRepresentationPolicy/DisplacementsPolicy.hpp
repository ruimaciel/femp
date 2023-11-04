
#ifndef DISPLACEMENTSPOLICY_H
#define DISPLACEMENTSPOLICY_H

#include <libfemp/AnalysisResult.hpp>

#include "DisplacementsRepresentationPolicy.hpp"

/**
 * Concrete displacements policy where displacements are represented according
 *to an analysis result
 **/
class DisplacementsPolicy : virtual public DisplacementsRepresentationPolicy {
	protected:
	fem::AnalysisResult* m_result;
	float m_scale;

	public:
	/**
	 * returns the coordinate of a given point by providing the node's reference
	 **/
	fem::Point3D operator[](size_t& node_reference) override;

	void setAnalysisResult(fem::AnalysisResult& result);
	void setDisplacementsScale(float scale);
};

#endif	// DISPLACEMENTSPOLICY_H
