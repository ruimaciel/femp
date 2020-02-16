#include "ISLeftDrag.h++"

#include <QDebug>

#include <QMouseEvent>

#include <GL/gl.h>
#include <GL/glu.h>

#include "../BaseViewport.h++"
#include "../ViewportStates/ViewportState.h++"
#include "Input.h++"

namespace InputStates {

void LeftDrag::press(BaseViewport* /*viewport*/, QMouseEvent* event, Input* /*input*/)
{
    switch (event->buttons()) {
    default:
        qCritical() << "other";
        break;
    }
}

void LeftDrag::release(BaseViewport* viewport, QMouseEvent* event, Input* input)
{
    this->leftRelease(viewport, event, input);
}

void LeftDrag::leftRelease(BaseViewport* viewport, QMouseEvent* event, Input* input)
{
    viewport->state->setSelectionOff();
    input->changeState(&input->m_is_start);
    {
        std::array<fem::Point3D, 4> near; // near plane vertices
        std::array<fem::Point3D, 4> far; // far plane vertices
        QPoint pos = event->pos();

        GLint vport[4];

        glGetDoublev(GL_MODELVIEW_MATRIX, viewport->viewport_data.modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, viewport->viewport_data.projection);
        glGetIntegerv(GL_VIEWPORT, vport);

        // calculate frustum corner nodes
        auto add = [&near, &far, &vport, &viewport](fem::Point3D& pos, int const i) {
            gluUnProject(pos.x(), vport[3] - pos.y(), 0, viewport->viewport_data.modelview, viewport->viewport_data.projection, vport, &near[i].data[0], &near[i].data[1], &near[i].data[2]);
            gluUnProject(pos.x(), vport[3] - pos.y(), 1, viewport->viewport_data.modelview, viewport->viewport_data.projection, vport, &far[i].data[0], &far[i].data[1], &far[i].data[2]);
        };

        fem::Point3D p[4]; // 4 corners of the picking viewport
        if (viewport->viewport_data.lastPos.x() < pos.x()) {
            p[0].data[0] = p[1].data[0] = viewport->viewport_data.lastPos.x();
            p[2].data[0] = p[3].data[0] = pos.x();
        } else {
            p[0].data[0] = p[1].data[0] = pos.x();
            p[2].data[0] = p[3].data[0] = viewport->viewport_data.lastPos.x();
        }

        if (viewport->viewport_data.lastPos.y() < pos.y()) {
            p[0].data[1] = p[3].data[1] = viewport->viewport_data.lastPos.y();
            p[1].data[1] = p[2].data[1] = pos.y();
        } else {
            p[0].data[1] = p[3].data[1] = pos.y();
            p[1].data[1] = p[2].data[1] = viewport->viewport_data.lastPos.y();
        }

        for (int i = 0; i < 4; i++)
            add(p[i], i);

        // extract selection frustum and perform pick selection
        viewport->selectObjectsFromFrustum(near, far);
    }
}

void LeftDrag::move(BaseViewport* viewport, QMouseEvent* event, Input* /*input*/)
{
    fem::Point3D near(event->x(), event->y());

    viewport->state->setSelectionEnd(near);
}

}
