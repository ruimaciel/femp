#ifndef SELECTION_WIDGET_HPP
#define SELECTION_WIDGET_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QtGui/QWidget>

#include <map>
#include "ui_SelectionWidget.h"

#include "../fem/Project.h++"
#include "../SelectionManager.h++"



/**
Widget developed to select model objects
**/
class SelectionWidget
	: public QWidget, Ui::SelectionWidget, public sigc::trackable
{
	Q_OBJECT

protected:
	QTreeWidgetItem *m_element_item;
	std::map<fem::element_ref_t, QTreeWidgetItem *>	m_element_map;	// list of all element references

	QTreeWidgetItem *m_node_item;
	std::map<fem::node_ref_t, QTreeWidgetItem *>	m_node_map;	// list of all element references

public:
	SelectionWidget(fem::Project &project, SelectionManager &, QWidget *parent = 0);

	/*
	void selectElement(fem::element_ref_t, bool state = true);
	void selectNode(fem::node_ref_t, bool state = true);
	*/

	// libsigc++ signals
	sigc::signal<void, Selection>	selection_changed;
	sigc::signal<void>		selection_cleared;

	// libsigc++ slots
	void setSelection(Selection);
	void clearSelection();


protected Q_SLOTS:
	/**
	Updates the selection according to clicks in the tree view
	**/
	void updateSelection();

protected:
	/**
	initializes the widget by filling all the revevant values
	@param	project 
	@param selection_manager
	**/
	void initializeWidget(fem::Project &project, SelectionManager &selection_manager);

};

#endif
