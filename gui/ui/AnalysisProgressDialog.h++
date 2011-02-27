#ifndef ANALYSIS_PROGRESS_DIALOG_HPP
#define ANALYSIS_PROGRESS_DIALOG_HPP

#include <QtGui/QDialog>

#include <string>

#include "ui_AnalysisProgressDialog.h"

class AnalysisProgressDialog
	: public QDialog, private Ui_AnalysisProgressDialog
{
	Q_OBJECT

	protected:
		std::string m_section_name;

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


		void setError(std::string);

		/**
		Announces the end of the entire process
		**/
		void finish();

};



#endif
