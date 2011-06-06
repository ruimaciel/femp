#ifndef MODEL_WINDOW_HPP
#define MODEL_WINDOW_HPP

#include "MdiWindow.h++"

#include "../fem/Model.h++"
#include "../viewer/ViewportColors.h++"
#include "../viewer/ModelViewport.h++"

/**
MDI window designed to represent the model
**/
class ModelWindow 
	: public MdiWindow
{
	Q_OBJECT

	public:
		ModelWindow (fem::Model &model, ViewportColors &colors, QWidget *parent = 0);


	protected:
		void connectSignalsToSlots();
};	

#endif
