#ifndef SELECTION_WIDGET_HPP
#define SELECTION_WIDGET_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QtWidgets/QWidget>

#include <map>
#include "ui_SelectionWidget.h"

#include <Project.h++>
#include <libfemp/Group.h++>

#include <Selection.h++>
#include <SelectionManager.h++>



/**
Widget developed to select model objects
**/
class SelectionWidget
        : public QWidget, Ui::SelectionWidget, public sigc::trackable
{
    Q_OBJECT

public:
    SelectionWidget(fem::Project &project, SelectionManager &, QWidget *parent = nullptr);

    /*
    void selectElement(fem::element_ref_t, bool state = true);
    void selectNode(fem::node_ref_t, bool state = true);
    */

    // libsigc++ signals
    sigc::signal<void, Selection>	selection_changed;
    sigc::signal<void>		selection_cleared;

    // libsigc++ slots
    void setSelection(Selection const&);
    void clearSelection();


protected:
    /**
    initializes the widget by filling all the revevant values
    @param	project
    @param selection_manager
    **/
    void initializeWidget(fem::Project &project, SelectionManager &selection_manager);

    /**
    Initializes the fem::Group list according to the group definitions stored in a given fem::Project object
    **/
    void initializeSelectionGroups(fem::Project &project);

protected:
    QTreeWidgetItem *m_element_item;
    std::map<fem::element_ref_t, QTreeWidgetItem *>	m_element_map;	// list of all element references

    QTreeWidgetItem *m_node_item;
    std::map<fem::node_ref_t, QTreeWidgetItem *>	m_node_map;	// list of all element references

    std::vector<fem::Group>	m_selection_groups;

};

#endif
