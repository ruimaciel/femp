#include "PostprocessingViewport.h++"

#include "SceneGraph.h++"


PostprocessingViewport::PostprocessingViewport(fem::Project &project, fem::AnalysisResult<double> &result, fem::ResultsRanges<double> &ranges, QWidget *parent)
	: BaseViewport(project, parent)
{
	mylog.setPrefix("PostprocessingViewport::PostprocessingViewport(fem::Model *model, QWidget *parent)");
	mylog.message("constructor");


	//TODO let the user choose which result to represent
	this->project = &project;
	this->m_analysis_result = NULL;
	this->setAnalysisResult(result);
	this->setResultsRanges(ranges);

	//TODO let the user select which analysis case to visualize

	// this->showStrain11(project.result.back());
	this->showDisplacements();

	// set this widget's load pattern pointer
	if(project.model.load_pattern_list.empty())
	{
		display_options.load_pattern = NULL;
	}
	else
	{
		// set the first load pattern
		display_options.load_pattern = &project.model.load_pattern_list.front();
	}
	this->setFocusPolicy(Qt::StrongFocus);
}


PostprocessingViewport::~PostprocessingViewport()
{
}


void 
PostprocessingViewport::paintGL()
{
	assert(project != NULL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	state->paintGL(this);
}


void 
PostprocessingViewport::mousePressEvent(QMouseEvent *event)
{
	state->mousePressEvent(this, event);

	updateGL();
}


void 
PostprocessingViewport::mouseMoveEvent(QMouseEvent *event)
{
	state->mouseMoveEvent(this, event);

	updateGL();
}


void 
PostprocessingViewport::wheelEvent(QWheelEvent *event)
{
	viewport_data.zoom += event->delta()/1000.0f;
	//qWarning("viewport_data.zoom: %f, %f",viewport_data.zoom, pow(2,viewport_data.zoom));

	this->resizeGL(this->width(), this->height());
	this->updateGL();
	event->accept();
}


void 
PostprocessingViewport::keyPressEvent( QKeyEvent *event)
{
	qWarning("blah not keypressed");
	state->keyPressEvent(this, event);
}


void 
PostprocessingViewport::setXRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void 
PostprocessingViewport::setYRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void 
PostprocessingViewport::setZRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void 
PostprocessingViewport::setPosition(int x, int y)
{
	mylog.setPrefix("PostprocessingViewport::setPosition(int x, int y)");
	//TODO implement this
	viewport_data.camera.pos.x(-x);
	viewport_data.camera.pos.y(-y);
	//viewport_data.camera.pos.z(amount/100.0f);
	//qWarning("pos: %f, %f, %f",viewport_data.camera.pos.x(), viewport_data.camera.pos.y(), viewport_data.camera.pos.z());
	QString m;
	mylog.message(m.sprintf("pos: %f, %f, %f",viewport_data.camera.pos.x(), viewport_data.camera.pos.y(), viewport_data.camera.pos.z()));

	updateGL();

	mylog.clearPrefix();
}


void
PostprocessingViewport::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	this->m_analysis_result = &result;
	this->m_vp_state_displacements.setAnalysisResult(result);
	this->m_vp_state_gradients.setAnalysisResult(result);
}


void
PostprocessingViewport::setResultsRanges(fem::ResultsRanges<double> &ranges)
{
	this->m_vp_state_gradients.setResultsRanges(ranges);
}


void 
PostprocessingViewport::showDisplacements()
{
	this->setState(&this->m_vp_state_displacements);
}


void 
PostprocessingViewport::showStrain11()
{
	this->m_vp_state_gradients.renderStrains11();
	this->setState(&this->m_vp_state_gradients);
}



void 
PostprocessingViewport::showStrain22()
{
	this->m_vp_state_gradients.renderStrains22();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStrain33()
{
	this->m_vp_state_gradients.renderStrains33();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStrain12()
{
	this->m_vp_state_gradients.renderStrains12();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStrain23()
{
	this->m_vp_state_gradients.renderStrains23();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStrain13()
{
	this->m_vp_state_gradients.renderStrains13();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStress11()
{
	this->m_vp_state_gradients.renderStresses11();
	this->setState(&this->m_vp_state_gradients);
}



void 
PostprocessingViewport::showStress22()
{
	this->m_vp_state_gradients.renderStresses22();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStress33()
{
	this->m_vp_state_gradients.renderStresses33();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStress12()
{
	this->m_vp_state_gradients.renderStresses12();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStress23()
{
	this->m_vp_state_gradients.renderStresses23();
	this->setState(&this->m_vp_state_gradients);
}


void 
PostprocessingViewport::showStress13()
{
	this->m_vp_state_gradients.renderStresses13();
	this->setState(&this->m_vp_state_gradients);
}



void 
PostprocessingViewport::showVonMises()
{
	this->m_vp_state_gradients.renderVonMises();
	this->setState(&this->m_vp_state_gradients);
}


