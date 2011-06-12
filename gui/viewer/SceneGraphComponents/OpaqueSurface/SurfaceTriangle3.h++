#ifndef SCENE_GRAPH_COMPONENT_TRIANGLE_3_HPP
#define SCENE_GRAPH_COMPONENT_TRIANGLE_3_HPP


#include <map>
#include "../../ViewportData.h++"
#include "../../ViewportColors.h++"
#include "../../../fem/Project.h++"
#include "../../../fem/Node.h++"
#include "../../../fem/Surface.h++"

/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class SurfaceTriangle3
{
	public:
		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result,  ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface);
};

#endif
