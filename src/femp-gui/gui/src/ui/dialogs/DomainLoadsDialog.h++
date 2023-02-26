#ifndef DOMAIN_LOADS_DIALOG_HPP
#define DOMAIN_LOADS_DIALOG_HPP

#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>
#include <libfemp/Point3D.h++>

#include <ui/models/LoadPatternsModel.h++>

//Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
	class DomainLoadsDialog;
}

class DomainLoadsDialog : public QDialog {
	Q_OBJECT

	public:
	DomainLoadsDialog(LoadPatternsModel& model, QWidget* parent = nullptr);
	~DomainLoadsDialog();

	size_t getLoadPattern();

	fem::Point3D getForce();

	private:
	size_t load_pattern;
	std::vector<std::string> m_newLoadPatterns;

	std::unique_ptr<Ui::DomainLoadsDialog> m_ui;
};

#endif
