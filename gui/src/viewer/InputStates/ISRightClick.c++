#include "ISRightClick.h++"

#include <QDebug>

#include <QMouseEvent>

#include "../BaseViewport.h++"
#include "Input.h++"

namespace InputStates {

void RightClick::press(BaseViewport* /*viewport*/, QMouseEvent* event, Input* /*input*/)
{
    switch (event->buttons()) {
    default:
        qCritical() << "other";
        break;
    }
}

void RightClick::release(BaseViewport* viewport, QMouseEvent* event, Input* input)
{
    //TODO check if left button was released
    this->rightRelease(viewport, event, input);
}

void RightClick::rightRelease(BaseViewport* viewport, QMouseEvent* /*event*/, Input* input)
{
    input->changeState(&viewport->m_is_start);
}

void RightClick::move(BaseViewport* viewport, QMouseEvent* /*event*/, Input* input)
{
    input->changeState(&viewport->m_is_right_drag);
}

}
