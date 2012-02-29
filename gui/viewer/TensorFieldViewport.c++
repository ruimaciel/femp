#include "TensorFieldViewport.h++"

#include "SceneGraph.h++"


TensorFieldViewport::TensorFieldViewport(fem::Project &project, fem::AnalysisResult<double> &result, fem::ResultsRanges<double> &ranges, QWidget *parent)
	: BaseViewport(project, parent)
{
	//TODO let the user choose which result to represent
	this->project = &project;
	this->m_analysis_result = NULL;
	this->setAnalysisResult(result);
	this->setResultsRanges(ranges);

	//TODO let the user select which analysis case to visualize

	this->showTensionField();

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


TensorFieldViewport::~TensorFieldViewport()
{
}


void 
TensorFieldViewport::paintGL()
{
	assert(project != NULL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	state->paintGL(this);
}


void 
TensorFieldViewport::mousePressEvent(QMouseEvent *event)
{
	state->mousePressEvent(this, event);

	updateGL();
}


void 
TensorFieldViewport::mouseMoveEvent(QMouseEvent *event)
{
	state->mouseMoveEvent(this, event);

	updateGL();
}


void 
TensorFieldViewport::wheelEvent(QWheelEvent *event)
{
	viewport_data.zoom += event->delta()/1000.0f;
	//qWarning("viewport_data.zoom: %f, %f",viewport_data.zoom, pow(2,viewport_data.zoom));

	this->resizeGL(this->width(), this->height());
	this->updateGL();
	event->accept();
}


void 
TensorFieldViewport::keyPressEvent( QKeyEvent *event)
{
	state->keyPressEvent(this, event);
}


void 
TensorFieldViewport::setXRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void 
TensorFieldViewport::setYRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void 
TensorFieldViewport::setZRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void 
TensorFieldViewport::setPosition(int x, int y)
{
	//TODO implement this
	viewport_data.camera.pos.x(-x);
	viewport_data.camera.pos.y(-y);
	//viewport_data.camera.pos.z(amount/100.0f);
	QString m;

	updateGL();
}


void
TensorFieldViewport::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	this->m_analysis_result = &result;
	this->m_vp_state_tension_fields.setAnalysisResult(result);
}


void
TensorFieldViewport::setResultsRanges(fem::ResultsRanges<double> &ranges)
{
	this->m_vp_state_tension_fields.setResultsRanges(ranges);
}


void 
TensorFieldViewport::showTensionField()
{
	this->setState(&this->m_vp_state_tension_fields);
}


