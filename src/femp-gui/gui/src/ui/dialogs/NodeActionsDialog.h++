#ifndef NODE_ACTIONS_DIALOG_HPP
#define NODE_ACTIONS_DIALOG_HPP

#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>
#include <libfemp/Point3D.h++>

#include "ui/models/LoadPatternsModel.h++"

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
	class NodeActionsDialog;
}

class NodeActionsDialog : public QDialog{
	Q_OBJECT

	private:
	size_t load_pattern;

	public:
	NodeActionsDialog(LoadPatternsModel& model, QWidget* parent = nullptr);
	~NodeActionsDialog();

	size_t getLoadPattern();
	fem::Point3D getForce();
	fem::Point3D getDisplacement();

	void loadPatternCreated(size_t, fem::LoadPattern const&);

	private:
	std::unique_ptr<Ui::NodeActionsDialog> m_ui;
};

#endif
