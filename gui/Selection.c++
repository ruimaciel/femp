#include "Selection.h++"

#include <assert.h>


Selection::Selection()
{
	m_project = NULL;
}

void 
Selection::setProject(fem::Project &project)
{
	this->m_project = &project;
}

void 
Selection::clear()
{
	this->m_elements_selected.clear();
	this->m_nodes_selected.clear();
}


void 
Selection::setSelection(Selection selection)
{
	this->m_project = selection.m_project;
	this->m_elements_selected = selection.m_elements_selected;
	this->m_nodes_selected = selection.m_nodes_selected;
}


