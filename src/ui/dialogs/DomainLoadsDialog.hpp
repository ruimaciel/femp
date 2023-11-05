#ifndef FEMP_UI_DOMAINLOADSDIALOG_HPP
#define FEMP_UI_DOMAINLOADSDIALOG_HPP

#include <libfemp/LoadPattern.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Point3D.hpp>
#include <ui/models/LoadPatternsModel.hpp>

// Qt includes
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
