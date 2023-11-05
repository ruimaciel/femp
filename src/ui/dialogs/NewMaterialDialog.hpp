#ifndef FEMP_UI_NEWMATERIALDIALOG_HPP
#define FEMP_UI_NEWMATERIALDIALOG_HPP

#include <application/interfaces/IMaterialRepository.hpp>
#include <libfemp/Model.hpp>  // for the materials list

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
class NewMaterialDialog;
}

class NewMaterialDialog : public QDialog {
	Q_OBJECT

	public:
	explicit NewMaterialDialog(gui::application::IMaterialRepositoryPtr material_repository, QWidget* parent = nullptr);
	~NewMaterialDialog();

	private:
	/**
	 * Checks if a given string matches a material label already added to the list
	 */
	bool isDuplicate(QString name);

	private slots:
	void addNewMaterial();	// adds a new material to the list from the data added
							// to the forms

	private:
	gui::application::IMaterialRepositoryPtr m_material_repository;
	std::unique_ptr<Ui::NewMaterialDialog> m_ui;
};

#endif
