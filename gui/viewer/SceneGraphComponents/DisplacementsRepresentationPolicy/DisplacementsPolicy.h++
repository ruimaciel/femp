
#ifndef DISPLACEMENTSPOLICY_H
#define DISPLACEMENTSPOLICY_H

#include "DisplacementsRepresentationPolicy.h++"

#include <libfemp/AnalysisResult.h++>

/**
Concrete displacements policy where displacements are represented according to an analysis result
**/
class DisplacementsPolicy 
	: virtual public DisplacementsRepresentationPolicy
{
protected:
	fem::AnalysisResult * m_result;
	float m_scale;
	
public:
	DisplacementsPolicy ( );
	virtual ~DisplacementsPolicy ( );


protected:

public:
	/**
	returns the coordinate of a given point by providing the node's reference
	**/
	fem::Point3D operator[](size_t &node_reference);


	void setAnalysisResult(fem::AnalysisResult &result);
	void setDisplacementsScale(float scale);

};

#endif // DISPLACEMENTSPOLICY_H
