#ifndef SELECTION_WIDGET_HPP
#define SELECTION_WIDGET_HPP

#include <Project.h++>
#include <QtWidgets/QWidget>
#include <SelectionManager.h++>
#include <application/interfaces/IElementRepository.h++>
#include <application/interfaces/INodeRepository.h++>
#include <libfemp/Group.h++>
#include <map>

#include "ui_SelectionWidget.h"

/**
Widget developed to select model objects
**/
class SelectionWidget : public QWidget, Ui::SelectionWidget {
	Q_OBJECT

   public:
	SelectionWidget(std::shared_ptr<gui::Model> domain_model, SelectionManager&, QWidget* parent = nullptr);

   signals:
	void selectionChanged(const Selection&);
	void selectionCleared();

   public slots:
	void setSelection(Selection const&);
	void clearSelection();

   protected:
	/**
	initializes the widget by filling all the revevant values
	@param selection_manager
	**/
	void initializeWidget(SelectionManager& selection_manager);

	/**
	Initializes the fem::Group list according to the group definitions stored in a
	given fem::Project object
	**/
	void initializeSelectionGroups(std::shared_ptr<gui::Model> femp_model);

   protected:
	QTreeWidgetItem* m_element_item;
	std::map<fem::element_ref_t, QTreeWidgetItem*> m_element_map;  // list of all element references

	QTreeWidgetItem* m_node_item;
	std::map<fem::node_ref_t, QTreeWidgetItem*> m_node_map;	 // list of all element references

	std::vector<fem::Group> m_selection_groups;
	gui::application::IElementRepositoryPtr m_element_repository;
	gui::application::INodeRepositoryPtr m_node_repository;
};

#endif
