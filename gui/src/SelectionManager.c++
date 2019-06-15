#include "SelectionManager.h++"

SelectionManager::~SelectionManager()
{
}

void SelectionManager::setSelection(Selection const& selection)
{
    m_selection = selection;

    emit selectionChanged(selection);
}

void SelectionManager::clearSelection()
{
    this->m_selection.clear();

    emit selectionCleared();
}

void SelectionManager::selectElement(const fem::element_ref_t& ref)
{
    m_selection.selectElement(ref);
}

void SelectionManager::deselectElement(const fem::element_ref_t& ref)
{
    m_selection.deselectElement(ref);
}

void SelectionManager::selectNode(const fem::node_ref_t& ref)
{
    m_selection.selectNode(ref);
}

void SelectionManager::deselectNode(const fem::node_ref_t& ref)
{
    m_selection.deselectNode(ref);
}

Selection const&
SelectionManager::getSelection() const
{
    return m_selection;
}
