#ifndef FEMP_UI_LOADPATTERNDIALOG_HPP
#define FEMP_UI_LOADPATTERNDIALOG_HPP

// Qt includes
#include <QDialog>

// std includes
#include <memory>
#include <string>

namespace Ui {
class LoadPatternDialog;
}

/**
 * Prompts the user to specify a name for a load pattern
 */
class LoadPatternDialog : public QDialog {
	Q_OBJECT

	public:
	LoadPatternDialog(QWidget* parent = nullptr);
	~LoadPatternDialog();

	std::string getLabel() const;

	private:
	std::unique_ptr<Ui::LoadPatternDialog> m_ui;
};

#endif
