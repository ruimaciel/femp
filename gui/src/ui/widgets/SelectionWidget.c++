#include "SelectionWidget.h++"

#include <QDebug>
#include <QTreeWidgetItem>

#include <Selection.h++>

SelectionWidget::SelectionWidget(fem::Project& project, SelectionManager& selection_manager, QWidget* parent)
    : QWidget(parent)
{
    this->setupUi(this);

    m_element_item = nullptr;
    m_node_item = nullptr;

    initializeSelectionGroups(project);
    initializeWidget(project, selection_manager);

    connect(this->selectPushButton, SIGNAL(clicked()), this, SLOT(updateSelection()));
    connect(this->toolButtonSet, SIGNAL(clicked()), this, SLOT(setGroupList()));
    connect(this->toolButtonAdd, SIGNAL(clicked()), this, SLOT(unionGroupList()));
    connect(this, &SelectionWidget::selectionChanged, this, &SelectionWidget::setSelection);
}

void SelectionWidget::initializeWidget(fem::Project& project, SelectionManager& selection_manager)
{
    m_element_item = new QTreeWidgetItem(this->objectTreeWidget);
    m_element_item->setText(0, tr("Elements"));

    Selection s = selection_manager.getSelection();
    //TODO test memory allocation

    std::shared_ptr<gui::Model> domain_model = project.getDomainModel();

    for (std::vector<fem::Element>::size_type n = 0; n < domain_model->getElementSize(); n++) {
        QTreeWidgetItem* item = new QTreeWidgetItem(m_element_item);
        item->setText(0, QString::number(n));
        item->setSelected(s.getElementReferences().find(n) != s.getElementReferences().end());
        m_element_map[n] = item;
    }

    m_node_item = new QTreeWidgetItem(this->objectTreeWidget);
    m_node_item->setText(0, tr("Nodes"));

    for (auto node_id: domain_model->getNodeReferenceList()) {
        QTreeWidgetItem* item = new QTreeWidgetItem(m_node_item);
        item->setText(0, QString::number(node_id));
        item->setSelected(s.getNodeReferences().find(node_id) != s.getNodeReferences().end());
        m_node_map[node_id] = item;
    }

    this->objectTreeWidget->insertTopLevelItem(0, m_element_item);
    this->objectTreeWidget->insertTopLevelItem(1, m_node_item);

    // initialize groups combo box with the list of defined groups
    for (size_t i = 0; i < m_selection_groups.size(); i++) {
        this->groupsComboBox->insertItem(i, QString(m_selection_groups[i].getLabel().c_str()));
    }
}

void SelectionWidget::setSelection(Selection const& selection)
{
    assert(m_element_item != nullptr);
    assert(m_node_item != nullptr);

    // clear all selections
    for (std::map<fem::element_ref_t, QTreeWidgetItem*>::iterator i = m_element_map.begin(); i != m_element_map.end(); i++) {
        i->second->setSelected(false);
    }

    auto selected_elements = selection.getElementReferences();
    for (std::set<fem::element_ref_t>::iterator i = selected_elements.begin(); i != selected_elements.end(); i++) {
        m_element_map[*i]->setSelected(true);
    }

    // clear all selections
    for (std::map<fem::node_ref_t, QTreeWidgetItem*>::iterator i = m_node_map.begin(); i != m_node_map.end(); i++) {
        i->second->setSelected(false);
    }

    auto selected_nodes = selection.getNodeReferences();
    for (std::set<fem::node_ref_t>::iterator i = selected_nodes.begin(); i != selected_nodes.end(); i++) {
        m_node_map[*i]->setSelected(true);
    }
}

void SelectionWidget::clearSelection()
{
}

void SelectionWidget::initializeSelectionGroups(fem::Project& project)
{
    auto femp_model = project.getDomainModel();

    for (auto node_group : femp_model->getNodeGroupList()) {
        fem::Group group;
        group.setLabel(node_group.getLabel());

        //TODO migrate to STL algorithms
        for (auto n = node_group.begin(); n != node_group.end(); n++) {
            group.pushNode(*n);
        }

        m_selection_groups.push_back(group);
    }

    for (auto element_group : femp_model->getElementGroupList()) {
        fem::Group group;
        group.setLabel(element_group.getLabel());

        //TODO migrate to STL algorithms
        for (auto n = element_group.begin(); n != element_group.end(); n++) {
            group.pushElement(*n);
        }

        m_selection_groups.push_back(group);
    }
}
