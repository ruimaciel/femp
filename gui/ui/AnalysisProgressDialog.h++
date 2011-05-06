#ifndef ANALYSIS_PROGRESS_DIALOG_HPP
#define ANALYSIS_PROGRESS_DIALOG_HPP

#include <QtGui/QDialog>
#include <QTime>

#include <string>

#include "ui_AnalysisProgressDialog.h"

class AnalysisProgressDialog
	: public QDialog, private Ui_AnalysisProgressDialog
{
	Q_OBJECT

	protected:
		std::string m_section_name;
		QTime timer;	// to time the run

	public:
		AnalysisProgressDialog(QWidget *parent = NULL);

	public slots:
		void beginSection(std::string);

		/**
		Marks the end of the current progress section
		**/
		void endSection();

		/**
		Sets the current progress
		@param	progress
		**/
		void setProgress(size_t);


		/**
		Sets an informative message
		**/
		void setMessage(std::string);

		void setError(std::string);

		/**
		Announces the end of the entire process
		**/
		void finish();

};



#endif
