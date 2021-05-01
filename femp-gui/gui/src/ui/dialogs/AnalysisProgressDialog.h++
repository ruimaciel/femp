#ifndef ANALYSIS_PROGRESS_DIALOG_HPP
#define ANALYSIS_PROGRESS_DIALOG_HPP

#include <QElapsedTimer>
#include <QTime>
#include <QtWidgets/QDialog>
#include <string>

#include "ui_AnalysisProgressDialog.h"

class AnalysisProgressDialog
    : public QDialog,
      private Ui::AnalysisProgressDialog {
    Q_OBJECT

protected:
    std::string m_section_name;
    QElapsedTimer timer; // to time the run

public:
    AnalysisProgressDialog(QWidget* parent = nullptr);

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
};

#endif
