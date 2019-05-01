#ifndef NODE_ACTIONS_DIALOG_HPP
#define NODE_ACTIONS_DIALOG_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDialog>

#include <libfemp/Point3D.h++>
#include <libfemp/Model.h++>
#include <libfemp/LoadPattern.h++>

#include "ui/models/LoadPatternsModel.h++"

#include "ui/ui_NodeActionsDialog.h"


class NodeActionsDialog
        : public QDialog, public sigc::trackable, private Ui::NodeActionsDialog
{
    Q_OBJECT

private:
    size_t load_pattern;

public:
    NodeActionsDialog(LoadPatternsModel &model, QWidget *parent = nullptr);

    size_t	getLoadPattern();
    fem::Point3D getForce();
    fem::Point3D getDisplacement();

    void loadPatternCreated(size_t, fem::LoadPattern const &);
};


#endif
