#ifndef LOADPATTERN_DIALOG_HPP
#define LOADPATTERN_DIALOG_HPP

#include <QtWidgets/QDialog>
#include <string>

#include "ui_LoadPatternDialog.h"

/**
 * Prompts the user to specify a name for a load pattern
 */
class LoadPatternDialog : public QDialog, private Ui::LoadPatternDialog {
	Q_OBJECT

   public:
	LoadPatternDialog(QWidget* parent = nullptr);

	std::string getLabel() const;
};

#endif
