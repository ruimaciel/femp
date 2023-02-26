#ifndef LOADPATTERN_DIALOG_HPP
#define LOADPATTERN_DIALOG_HPP

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
