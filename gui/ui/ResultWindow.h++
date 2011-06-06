#ifndef RESULT_WINDOW_HPP
#define RESULT_WINDOW_HPP

#include "MdiWindow.h++"

#include "../fem/Model.h++"
#include "../fem/AnalysisResult.h++"
#include "../viewer/ViewportColors.h++"
#include "../viewer/BaseViewport.h++"
#include "../viewer/DisplacementsViewport.h++"

/**
MDI window designed to represent any recovered information from any analysis, such as displacements, stress fields, etc...
**/
class ResultWindow 
	: public MdiWindow
{
	Q_OBJECT

	public:
		ResultWindow (fem::Model &model, ViewportColors &colors, fem::AnalysisResult<double> &analysis, QWidget *parent = 0);


	protected:
		void connectSignalsToSlots();

};	

#endif
