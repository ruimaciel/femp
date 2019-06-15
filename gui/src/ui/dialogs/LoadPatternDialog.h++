#ifndef LOADPATTERNDIALOG_HPP
#define LOADPATTERNDIALOG_HPP

#include <QtWidgets/QDialog>
#include <string>

#include "ui_LoadPatternDialog.h"
/**
USAGE EXPLANATION
**/
class LoadPatternDialog
    : public QDialog,
      private Ui::LoadPatternDialog {
    Q_OBJECT

public:
    LoadPatternDialog(QWidget* parent = nullptr);

    std::string getLabel() const;
};

#endif
