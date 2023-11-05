#ifndef FEMP_UI_SELECTIONDIALOG_HPP
#define FEMP_UI_SELECTIONDIALOG_HPP

#include <Project.hpp>
#include <SelectionManager.hpp>
#include <ui/widgets/SelectionWidget.hpp>

// Qt includes
#include <QDialog>

/**
 * Dialog box which uses the selection widget to select objects from a given
 * fem::Project object
 */
class SelectionDialog : public QDialog {
	Q_OBJECT

	protected:
	SelectionWidget* m_selection_widget;

	public:
	SelectionDialog(std::shared_ptr<domain::Model> model, SelectionManager& selection_manager, QWidget* parent = nullptr);
};

#endif
