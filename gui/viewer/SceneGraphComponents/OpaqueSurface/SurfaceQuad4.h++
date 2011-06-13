#ifndef SCENE_GRAPH_COMPONENT_QUAD_4_HPP
#define SCENE_GRAPH_COMPONENT_QUAD_4_HPP


#include <map>
#include "../../ViewportData.h++"
#include "../../ViewportColors.h++"
#include "../../../fem/Project.h++"
#include "../../../fem/Node.h++"
#include "../../../fem/Surface.h++"

/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class SurfaceQuad4
{
	public:
		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result,  float &scale, ViewportColors &colors, fem::Surface *surface);
};

#endif
