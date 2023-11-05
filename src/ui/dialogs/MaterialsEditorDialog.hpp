#ifndef FEMP_UI_MATERIALSEDITORDIALOG_HPP
#define FEMP_UI_MATERIALSEDITORDIALOG_HPP

#include <libfemp/Model.hpp>

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
class MaterialsEditorDialog;
}

class MaterialsEditorDialog : public QDialog {
	Q_OBJECT

	private:
	fem::Model& model;

	public:
	explicit MaterialsEditorDialog(fem::Model& model, QWidget* parent = nullptr);
	~MaterialsEditorDialog();

	public slots:
	void loadMaterials();

	private slots:

	/**
	 * Resets the UI according to the selection state
	 */
	void resetSelectionUI();

	private:
	std::unique_ptr<Ui::MaterialsEditorDialog> m_ui;
};

#endif
