#include "SelectionManager.h++"

SelectionManager::~SelectionManager() {}

void SelectionManager::setSelection(Selection const& selection) {
	m_selection = selection;

	emit selectionChanged(selection);
}

void SelectionManager::clearSelection() {
	this->m_selection = Selection();

	emit selectionCleared();
}

Selection const& SelectionManager::getSelection() const {
	return m_selection;
}
