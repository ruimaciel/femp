#include "ISStart.h++"

#include <QDebug>
#include <QMouseEvent>

#include "../BaseViewport.h++"
#include "../ViewportStates/ViewportState.h++"
#include "Input.h++"

namespace InputStates {

void Start::press(BaseViewport* viewport, QMouseEvent* event, Input* input)
{
    switch (event->buttons()) {
    case Qt::LeftButton:
        this->leftClick(viewport, event, input);
        break;

    case Qt::RightButton:
        this->rightClick(viewport, event, input);
        break;

    default:
        qCritical() << "other";
        break;
    }
}

void Start::leftClick(BaseViewport* viewport, QMouseEvent* event, Input* input)
{
    fem::Point3D near;
    near.x((float)event->x());
    near.y((float)event->y());
    viewport->state->setSelectionStart(near);

    // register place where mouse is clicked
    viewport->viewport_data.lastPos = event->pos();

    input->changeState(&input->m_is_left_click);
}

void Start::rightClick(BaseViewport* viewport, QMouseEvent* event, Input* input)
{
    viewport->viewport_data.lastPos = event->pos(); // for the rotate
    input->changeState(&input->m_is_right_click);
}
}
