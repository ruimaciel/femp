#ifndef SELECTION_DIALOG_HPP
#define SELECTION_DIALOG_HPP

#include <Project.h++>
#include <QtWidgets/QDialog>
#include <SelectionManager.h++>
#include <ui/widgets/SelectionWidget.h++>

/**
 * Dialog box which uses the selection widget to select objects from a given
 * fem::Project object
 */
class SelectionDialog : public QDialog {
	Q_OBJECT

   protected:
	SelectionWidget* m_selection_widget;

   public:
	SelectionDialog(std::shared_ptr<gui::Model> model, SelectionManager& selection_manager, QWidget* parent = nullptr);
};

#endif
