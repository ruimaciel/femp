#include "SelectionWidget.h++"

#include <QTreeWidgetItem>

#include "../Selection.h++"


SelectionWidget::SelectionWidget(fem::Project &project, SelectionManager &selection_manager, QWidget *parent)
	: QWidget(parent)
{
	this->setupUi(this);

	m_element_item = NULL;
	m_node_item = NULL;

	initializeWidget(project, selection_manager);

	connect(this->selectPushButton, SIGNAL(clicked()), this, SLOT(updateSelection()));
}


void 
SelectionWidget::initializeWidget(fem::Project &project, SelectionManager &selection_manager)
{
	m_element_item = new QTreeWidgetItem(this->objectTreeWidget);
	m_element_item->setText(0, tr("Elements"));

	Selection s = selection_manager.getSelection();
	//TODO test memory allocation

	//for( std::vector<fem::Element>::iterator i = project.model.element_list.begin(); i != project.model.element_list.end(); i++)
	for( std::vector<fem::Element>::size_type n = 0;  n < project.model.element_list.size(); n++)
	{
		     QTreeWidgetItem *item = new QTreeWidgetItem(m_element_item);
		     item->setText(0, QString::number(n));
		     item->setSelected( s.m_elements_selected.find(n) != s.m_elements_selected.end()) ; 
		     m_element_map[n] = item;
	}

	m_node_item = new QTreeWidgetItem(this->objectTreeWidget);
	m_node_item->setText(0, tr("Nodes") );
	for(std::map<fem::node_ref_t, fem::Node>::iterator i = project.model.node_list.begin(); i != project.model.node_list.end();  i++)
	{
		     QTreeWidgetItem *item = new QTreeWidgetItem(m_node_item);
		     item->setText(0, QString::number(i->first));
		     item->setSelected( s.m_nodes_selected.find(i->first) != s.m_nodes_selected.end()) ; 
		     m_node_map[i->first] = item;
	}

	this->objectTreeWidget->insertTopLevelItem(0, m_element_item);
	this->objectTreeWidget->insertTopLevelItem(1, m_node_item);

	// connects signals to slots
	selection_manager.selection_changed.connect( sigc::mem_fun(this, &SelectionWidget::setSelection));
	this->selection_changed.connect( sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}


void 
SelectionWidget::setSelection(Selection selection)
{
	assert(m_element_item != NULL);
	assert(m_node_item != NULL);

	// clear all selections
	for( std::map<fem::element_ref_t, QTreeWidgetItem *>::iterator i = m_element_map.begin(); i != m_element_map.end(); i++)
	{
		i->second->setSelected(false);
	}

	for( std::set<fem::element_ref_t>::iterator i = selection.m_elements_selected.begin(); i != selection.m_elements_selected.end(); i++)
	{
		m_element_map[*i]->setSelected(true);
	}

	// clear all selections
	for( std::map<fem::node_ref_t, QTreeWidgetItem *>::iterator i = m_node_map.begin(); i != m_node_map.end(); i++)
	{
		i->second->setSelected(false);
	}
	for( std::set<fem::node_ref_t>::iterator i = selection.m_nodes_selected.begin(); i != selection.m_nodes_selected.end(); i++)
	{
		m_node_map[*i]->setSelected(true);
	}
}


void 
SelectionWidget::updateSelection()
{
	Selection new_selection;

	qWarning("SelectionWidget::updateSelection()");
	//TODO fill new_selection with the selected entries
	for(std::map<fem::element_ref_t, QTreeWidgetItem *>::iterator i = m_element_map.begin(); i != m_element_map.end(); i++)
	{
		if(i->second->isSelected())
			new_selection.m_elements_selected.insert(i->first);
	}
	/*
	for(std::map<fem::node_ref_t, QTreeWidgetItem *>::iterator i = m_node_map.begin(); i != m_node_map.end(); i++)
	{
		if(i->second->isSelected())
			new_selection.m_nodes_selected.insert(i->first);
	}
	/ */

	//this->selection_changed.emit(new_selection); // this doesn't work, due to Qt
	this->selection_changed(new_selection);
}


