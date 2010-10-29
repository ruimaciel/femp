#include "VPStateModel.h++"


#include "Logs.h++"	// declare the global message loggers


VPStateModel::VPStateModel()
	: ViewportState()
{
	mylog.setPrefix("VPStateModel::VPStateModel()");
	mylog.message("constructor");
}


VPStateModel::~VPStateModel()
{
	mylog.setPrefix("VPStateModel::~VPStateModel()");
	mylog.message("destructor called");
}


void VPStateModel::paintGL(fem::Model &model)
{
	mylog.setPrefix("VPStateModel::paintGL()");
	
	mylog.message("painting");
	//TODO finish implementing this
}
