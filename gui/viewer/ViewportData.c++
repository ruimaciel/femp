#include "ViewportData.h++"


ViewportData::ViewportData()
{
	this->reset();
};


void 
ViewportData::reset()
{
	zoom = 0; 
	aspect_ratio = 1;
	node_scale = 20;

	selected_node_list.clear();

}

