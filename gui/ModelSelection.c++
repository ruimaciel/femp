#include "ModelSelection.h++"


ModelSelection::ModelSelection()
{
}


ModelSelection::~ModelSelection()
{
}


void
ModelSelection::selectNode(const size_t &label, bool state )
{
	//TODO add support for node selections
	nodes[label] = state;
	/*
	if(nodes_selection)
	{
		// all selected by default
	}
	else
	{
		// none selected by default
		if(state == false)
		{
			std::map<size_t, bool>::iterator i = nodes.find(label);
			if(i != nodes.end())
				nodes.erase(label);

		}
		nodes[label] = state;
	}
	*/
}


void
ModelSelection::selectElement(const size_t &label, bool state )
{
	//TODO add support for node selections
	elements[label] = state;
}


void
ModelSelection::selectSurface(const size_t &label, bool state )
{
	//TODO add support for node selections
	surfaces[label] = state;
}


void
ModelSelection::selectAll(bool state)
{
	this->selectAllNodes(state);
	this->selectAllElements(state);
	this->selectAllSurfaces(state);
}


void
ModelSelection::selectAllNodes(bool state)
{
	nodes_selection = state;
	this->nodes.clear();
}


void
ModelSelection::selectAllElements(bool state)
{
	elements_selection = state;
	this->elements.clear();
}


void
ModelSelection::selectAllSurfaces(bool state)
{
	surfaces_selection = state;
	this->surfaces.clear();
}


void
ModelSelection::deselectNode(const size_t &label, bool state )
{
	//TODO add support for node selections
	nodes[label] = state;
	/*
	if(nodes_selection)
	{
		// all selected by default
	}
	else
	{
		// none selected by default
		if(state == false)
		{
			std::map<size_t, bool>::iterator i = nodes.find(label);
			if(i != nodes.end())
				nodes.erase(label);

		}
		nodes[label] = state;
	}
	*/
}


void
ModelSelection::deselectElement(const size_t &label, bool state )
{
	//TODO add support for node selections
	elements[label] = state;
}


void
ModelSelection::deselectSurface(const size_t &label, bool state )
{
	//TODO add support for node selections
	surfaces[label] = state;
}


void
ModelSelection::deselectAll(bool state)
{
	this->selectAllNodes(state);
	this->selectAllElements(state);
	this->selectAllSurfaces(state);
}


void
ModelSelection::deselectAllNodes(bool state)
{
	nodes_selection = state;
	this->nodes.clear();
}


void
ModelSelection::deselectAllElements(bool state)
{
	elements_selection = state;
	this->elements.clear();
}


void
ModelSelection::deselectAllSurfaces(bool state)
{
	surfaces_selection = state;
	this->surfaces.clear();
}


bool
ModelSelection::isNodeSelected(size_t &node)
{
	std::map<size_t,bool>::iterator i = nodes.find(node);
	return !(i == nodes.end());
}


bool
ModelSelection::isElementSelected(size_t &element)
{
	std::map<size_t,bool>::iterator i = elements.find(element);
	return !(i == elements.end());
}


