#include "SelectionManager.h++"


SelectionManager::SelectionManager(fem::Project &project)
{
	this->m_project = &project;
}


void 
SelectionManager::selectElement(fem::element_ref_t ref, bool state)
{
	if(state)
	{
		this->m_elements_selected.insert(ref);
		element_selected.emit(ref, true);
	}
	else
	{
		m_elements_selected.erase(ref);
		element_selected.emit(ref, true);
	}

}


void 
SelectionManager::selectNode(fem::node_ref_t ref, bool state)
{
	if(state)
	{
		this->m_nodes_selected.insert(ref);
		node_selected.emit(ref, true);
	}
	else
	{
		m_nodes_selected.erase(ref);
		node_selected.emit(ref, true);
	}
}


void 
SelectionManager::clearSelection()
{
	this->m_elements_selected.clear();
	this->m_nodes_selected.clear();

	selection_cleared.emit();
}


Selection *
SelectionManager::getSelection()
{
	Selection *selection;
	selection = new Selection(this->m_project);

	for(std::set<fem::node_ref_t>::iterator i = m_nodes_selected.begin(); i != m_nodes_selected.end(); i++)
	{
		selection->addNode(*i);
	}

	for(std::set<fem::element_ref_t>::iterator i = m_elements_selected.begin(); i != m_elements_selected.end(); i++)
	{
		selection->addElement(*i);
	}

	return selection;
}

