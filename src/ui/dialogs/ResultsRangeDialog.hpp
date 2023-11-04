#ifndef SCALAR_RANGE_DIALOG_HPP
#define SCALAR_RANGE_DIALOG_HPP

#include <libfemp/ElementResults/ResultsRanges.hpp>

// Qt includes
#include <QDialog>

namespace Ui {
class ResultsRangeDialog;
}

/**
 * Dialog intended to be used to specify ranges of a given parameter
 */
class ResultsRangeDialog : public QDialog {
	Q_OBJECT

	public:
	ResultsRangeDialog(QWidget* parent = nullptr);
	~ResultsRangeDialog();

	void setValueRanges(const fem::ResultsRanges<double>&);

	bool getValueRanges(fem::ResultsRanges<double>&) const;

	private:
	std::unique_ptr<Ui::ResultsRangeDialog> m_ui;
};

#endif
