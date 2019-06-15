#ifndef DOMAIN_LOADS_DIALOG_HPP
#define DOMAIN_LOADS_DIALOG_HPP

#include <QDialog>
#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>
#include <libfemp/Point3D.h++>

#include <ui/models/LoadPatternsModel.h++>

#include "ui_DomainLoadsDialog.h"

class DomainLoadsDialog
    : public QDialog,
      private Ui::DomainLoadsDialog {
    Q_OBJECT

public:
    DomainLoadsDialog(LoadPatternsModel& model, QWidget* parent = nullptr);

    size_t getLoadPattern();

    fem::Point3D getForce();

private:
    size_t load_pattern;
    std::vector<std::string> m_newLoadPatterns;
};

#endif
