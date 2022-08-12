#ifndef MOVE_NODES_DIALOG_HPP
#define MOVE_NODES_DIALOG_HPP

#include <QDialog>
#include <libfemp/Point3D.h++>

#include "ui_MoveNodesDialog.h"

/**
 * Dialog used by GLDisplacementsWidget to input a new displacements scale
 */
class MoveNodesDialog : public QDialog, private Ui::MoveNodesDialog {
	Q_OBJECT

   public:
	explicit MoveNodesDialog(QWidget* parent = nullptr);

	fem::Point3D getTranslation();
};

#endif
