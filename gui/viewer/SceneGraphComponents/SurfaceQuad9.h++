#ifndef SCENE_GRAPH_COMPONENT_QUAD_9_HPP
#define SCENE_GRAPH_COMPONENT_QUAD_9_HPP


#include <map>
#include "../ViewportData.h++"
#include "../../fem/Model.h++"
#include "../../fem/Node.h++"
#include "../../fem/Surface.h++"

/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class SurfaceQuad9
{
	public:
		void paintGL(ViewportData &data, fem::Model *model, std::map<size_t, fem::Node> *node_list, fem::Surface *surface);
};

#endif
