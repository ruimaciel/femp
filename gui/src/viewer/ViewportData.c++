#include "ViewportData.h++"


ViewportData::ViewportData()
{
	this->reset();
};


void 
ViewportData::reset()
{
	zoom = 0; 
	node_radius = 1.0f;
	aspect_ratio = 1;
	node_scale = 20;

	selected_node_list.clear();

}

