#include "SelectionWidget.h++"

#include <QDebug>
#include <QTreeWidgetItem>

#include <Selection.h++>


SelectionWidget::SelectionWidget(fem::Project &project, SelectionManager &selection_manager, QWidget *parent)
    : QWidget(parent)
{
    this->setupUi(this);

    m_element_item = nullptr;
    m_node_item = nullptr;

    initializeSelectionGroups(project);
    initializeWidget(project, selection_manager);

    connect(this->selectPushButton, SIGNAL(clicked()),	this,	SLOT(updateSelection()));
    connect(this->toolButtonSet,	SIGNAL(clicked()),	this,	SLOT(setGroupList()));
    connect(this->toolButtonAdd,	SIGNAL(clicked()),	this,	SLOT(unionGroupList()) );
}


void
SelectionWidget::initializeWidget(fem::Project &project, SelectionManager &selection_manager)
{
    m_element_item = new QTreeWidgetItem(this->objectTreeWidget);
    m_element_item->setText(0, tr("Elements"));

    Selection s = selection_manager.getSelection();
    //TODO test memory allocation

    for( std::vector<fem::Element>::size_type n = 0;  n < project.getModel().numberOfElements(); n++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(m_element_item);
        item->setText(0, QString::number(n));
        item->setSelected( s.getElementReferences().find(n) != s.getElementReferences().end()) ;
        m_element_map[n] = item;
    }

    m_node_item = new QTreeWidgetItem(this->objectTreeWidget);
    m_node_item->setText(0, tr("Nodes") );
    for(auto node_pair: project.getModel().getNodeMap())
    {
        size_t node_id;
        std::tie(node_id, std::ignore) = node_pair;
        QTreeWidgetItem *item = new QTreeWidgetItem(m_node_item);
        item->setText(0, QString::number(node_id));
        item->setSelected( s.getNodeReferences().find(node_id) != s.getNodeReferences().end()) ;
        m_node_map[node_id] = item;
    }

    this->objectTreeWidget->insertTopLevelItem(0, m_element_item);
    this->objectTreeWidget->insertTopLevelItem(1, m_node_item);

    // initialize groups combo box with the list of defined groups
    for(size_t i = 0; i < m_selection_groups.size(); i++)
    {
        this->groupsComboBox->insertItem(i, QString(m_selection_groups[i].getLabel().c_str()) );
    }

    // connects signals to slots
    selection_manager.selection_changed.connect( sigc::mem_fun(this, &SelectionWidget::setSelection));
    this->selection_changed.connect( sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}


void
SelectionWidget::setSelection(Selection const &selection)
{
    assert(m_element_item != nullptr);
    assert(m_node_item != nullptr);

    // clear all selections
    for( std::map<fem::element_ref_t, QTreeWidgetItem *>::iterator i = m_element_map.begin(); i != m_element_map.end(); i++)
    {
        i->second->setSelected(false);
    }

    auto selected_elements = selection.getElementReferences();
    for( std::set<fem::element_ref_t>::iterator i = selected_elements.begin(); i != selected_elements.end(); i++)
    {
        m_element_map[*i]->setSelected(true);
    }

    // clear all selections
    for( std::map<fem::node_ref_t, QTreeWidgetItem *>::iterator i = m_node_map.begin(); i != m_node_map.end(); i++)
    {
        i->second->setSelected(false);
    }

    auto selected_nodes = selection.getNodeReferences();
    for( std::set<fem::node_ref_t>::iterator i = selected_nodes.begin(); i != selected_nodes.end(); i++)
    {
        m_node_map[*i]->setSelected(true);
    }
}


void
SelectionWidget::updateSelection()
{
    Selection new_selection;

    qWarning("SelectionWidget::updateSelection()");

    for(std::map<fem::element_ref_t, QTreeWidgetItem *>::iterator i = m_element_map.begin(); i != m_element_map.end(); i++)
    {
        if(i->second->isSelected())
            new_selection.selectElement(i->first);
    }

    for(std::map<fem::node_ref_t, QTreeWidgetItem *>::iterator i = m_node_map.begin(); i != m_node_map.end(); i++)
    {
        if(i->second->isSelected())
            new_selection.selectNode(i->first);
    }

    this->selection_changed(new_selection);
}


void
SelectionWidget::setGroupList()
{
    // get current index
    int index = groupsComboBox->currentIndex();

    if(index == -1)
    {
        // SelectionWidget::setGroupList(): combo box is empty
        return;
    }

    // set selection group
    Selection new_selection;

    for(auto node_ref: m_selection_groups[index].getNodeReferences())
    {
        new_selection.selectNode(node_ref);
    }

    for(auto element_ref: m_selection_groups[index].getElementReferences())
    {
        new_selection.selectElement(element_ref);
    }

    this->selection_changed(new_selection);
}


void
SelectionWidget::unionGroupList()
{
    qInfo() <<  "SelectionWidget::unionGroupList()";

    // get current index
    int index = groupsComboBox->currentIndex();

    if(index == -1)
    {
        qCritical() <<  "SelectionWidget::unionGroupList(): combo box is empty";
        return;
    }

    fem::Group &group = m_selection_groups[index];

    for(const auto element_ref: group.getElementReferences())
    {
        this->m_element_map[element_ref]->setSelected(true);
    }

    for(const auto node_ref: group.getNodeReferences())
    {
        this->m_node_map[node_ref]->setSelected(true);
    }

    // set selection group
    updateSelection();
}


void
SelectionWidget::initializeSelectionGroups(fem::Project &project)
{
    fem::Model & femp_model = project.getModel();

    for( auto node_group: femp_model.getNodeGroups())
    {
        fem::Group group;
        group.setLabel(node_group.getLabel());

        //TODO migrate to STL algorithms
        for(auto n = node_group.begin(); n != node_group.end(); n++)
        {
            group.pushNode(*n);
        }

        m_selection_groups.push_back(group);
    }

    for( auto element_group: femp_model.getNodeGroups())
    {
        fem::Group group;
        group.setLabel(element_group.getLabel());

        //TODO migrate to STL algorithms
        for(auto n = element_group.begin(); n != element_group.end(); n++)
        {
            group.pushElement(*n);
        }

        m_selection_groups.push_back(group);
    }
}

