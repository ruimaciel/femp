#ifndef FEMP_UI_ANALYSISPROGRESSDIALOG_HPP
#define FEMP_UI_ANALYSISPROGRESSDIALOG_HPP

// Qt includes
#include <QDialog>
#include <QElapsedTimer>
#include <QTime>

// std includes
#include <memory>
#include <string>

namespace Ui {
class AnalysisProgressDialog;
}

class AnalysisProgressDialog : public QDialog {
	Q_OBJECT

	protected:
	std::string m_section_name;
	QElapsedTimer timer;  // to time the run

	public:
	AnalysisProgressDialog(QWidget* parent = nullptr);
	~AnalysisProgressDialog();

	public slots:
	void beginSection(std::string);

	/**
	 * Marks the end of the current progress section
	 */
	void endSection();

	/**
	 * Sets the current progress
	 * @param	progress
	 */
	void setProgress(size_t);

	/**
	 * Sets an informative message
	 */
	void setMessage(const std::string&);

	void setError(std::string);

	/**
	 * Announces the end of the entire process
	 */
	void finish();

	private:
	std::unique_ptr<Ui::AnalysisProgressDialog> m_ui;
};

#endif
