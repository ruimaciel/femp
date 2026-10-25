#ifndef FEMP_UI_SELECTION_WIDGET_HPP
#define FEMP_UI_SELECTION_WIDGET_HPP

#include <Project.hpp>
#include <QtWidgets/QWidget>
#include <SelectionManager.hpp>
#include <application/interfaces/IElementRepository.hpp>
#include <application/interfaces/INodeRepository.hpp>
#include <libfemp/Group.hpp>
#include <map>
#include <selection/Selection.hpp>

#include "ui_SelectionWidget.h"

/**
Widget developed to select model objects
**/
namespace femp::ui {

class SelectionWidget : public QWidget, Ui::SelectionWidget {
  Q_OBJECT

public:
  SelectionWidget(std::shared_ptr<femp::domain::Model> domain_model,
                  femp::SelectionManager &, QWidget *parent = nullptr);

signals:
  void selectionChanged(const Selection &);
  void selectionCleared();

public slots:
  void setSelection(Selection const &);
  void clearSelection();

protected:
  /**
  initializes the widget by filling all the revevant values
  @param selection_manager
  **/
  void initializeWidget(femp::SelectionManager &selection_manager);

  /**
  Initializes the fem::Group list according to the group definitions stored in a
  given femp::Project object
  **/
  void
  initializeSelectionGroups(std::shared_ptr<femp::domain::Model> femp_model);

protected:
  QTreeWidgetItem *m_element_item;
  std::map<fem::element_ref_t, QTreeWidgetItem *>
      m_element_map; // list of all element references

  QTreeWidgetItem *m_node_item;
  std::map<fem::node_ref_t, QTreeWidgetItem *>
      m_node_map; // list of all element references

  std::vector<fem::Group> m_selection_groups;
  femp::application::IElementRepositoryPtr m_element_repository;
  femp::application::INodeRepositoryPtr m_node_repository;
};

} // namespace femp::ui

#endif
