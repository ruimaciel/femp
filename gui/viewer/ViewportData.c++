#include "ViewportData.h++"


ViewportData::ViewportData()
{
	this->reset();
};


void ViewportData::reset()
{
	zoom = 0; 
	aspect_ratio = 1;
	node_scale = 20;

	selected_node_list.clear();

	//TODO find a better way to set these values
	max_strains.setZero(); 
	min_strains.setZero();
	max_stresses.setZero(); 
	min_stresses.setZero();
	max_von_mises = 0;
	min_von_mises = 0;
}
