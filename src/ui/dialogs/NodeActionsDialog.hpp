#ifndef FEMP_UI_NODEACTIONSDIALOG_HPP
#define FEMP_UI_NODEACTIONSDIALOG_HPP

#include <libfemp/LoadPattern.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Point3D.hpp>

#include "ui/models/LoadPatternsModel.hpp"

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
class NodeActionsDialog;
}

class NodeActionsDialog : public QDialog {
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
