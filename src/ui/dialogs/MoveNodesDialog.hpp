#ifndef MOVE_NODES_DIALOG_HPP
#define MOVE_NODES_DIALOG_HPP

#include <libfemp/Point3D.hpp>

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
class MoveNodesDialog;
}

/**
 * Dialog used by GLDisplacementsWidget to input a new displacements scale
 */
class MoveNodesDialog : public QDialog {
	Q_OBJECT

	public:
	explicit MoveNodesDialog(QWidget* parent = nullptr);
	~MoveNodesDialog();

	fem::Point3D getTranslation();

	private:
	std::unique_ptr<Ui::MoveNodesDialog> m_ui;
};

#endif
