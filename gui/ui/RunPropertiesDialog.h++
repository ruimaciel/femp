#ifndef RUN_PROPERTIES_DIALOG_HPP
#define RUN_PROPERTIES_DIALOG_HPP


/**
Dialog box designed to present the user with a set of useful information taken from the
model's analysis, such as time spent analyzing it and the model's energy
**/
class RunPropertiesDialog
	: public QDialog, private Ui_RunPropertiesDialog
{
	Q_OBJECT

	public:
		RunPropertiesDialog(fem::AnalysisResult<double> &result, QWidget *parent = NULL);

	protected:
		void setValues(fem::AnalysisResult<double> &result);
};

#endif
