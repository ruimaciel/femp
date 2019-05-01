#include "ISRightDrag.h++"

#include <QDebug>

#include <QMouseEvent>

#include "Input.h++"
#include "../BaseViewport.h++"

namespace InputStates
{

void
RightDrag::press(BaseViewport * /*viewport*/, QMouseEvent *event, Input * /*input*/)
{
    switch(event->buttons() )
    {
        default:
            qDebug() << "other";
            break;
    }
}


void
RightDrag::release(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
    this->rightRelease(viewport, event, input);
}


void
RightDrag::rightRelease(BaseViewport *viewport, QMouseEvent * /*event*/, Input *input)
{
    input->changeState(&viewport->m_is_start);
}


void
RightDrag::move(BaseViewport *viewport, QMouseEvent *event, Input * /*input*/)
{
    ViewportData &viewport_data = viewport->viewport_data;

    int dx = event->x() - viewport_data.lastPos.x();
    int dy = event->y() - viewport_data.lastPos.y();

    viewport_data.camera.rotation.data[0] += dy/pow(2,viewport_data.zoom);
    viewport_data.camera.rotation.data[1] += dx/pow(2,viewport_data.zoom);

    viewport_data.lastPos = event->pos();
}


}

