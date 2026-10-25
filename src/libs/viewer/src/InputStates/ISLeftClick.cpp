#include "ISLeftClick.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include <QDebug>
#include <QMouseEvent>
#include <viewer/BaseViewport.hpp>

#include "InputStateMachine.hpp"

namespace InputStates {

void LeftClick::press(BaseViewport & /*viewport*/, QMouseEvent *event,
                      InputStateMachine * /*input*/) {
  switch (event->buttons()) {
  default:
    qCritical() << "other";
    break;
  }
}

void LeftClick::release(BaseViewport &viewport, QMouseEvent *event,
                        InputStateMachine *input) {
  // TODO check if left button was released
  this->leftRelease(viewport, event, input);
}

void LeftClick::leftRelease(BaseViewport &viewport, QMouseEvent *event,
                            InputStateMachine *input) {
  input->changeToStart();

  {
    fem::Point3D near, far;
    QPoint pos = event->pos();

    // Ensure the widget's GL context is current before querying matrices
    viewport.makeCurrent();

    GLint vport[4];

    glGetDoublev(GL_MODELVIEW_MATRIX, viewport.viewport_data.modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, viewport.viewport_data.projection);
    glGetIntegerv(GL_VIEWPORT, vport);
    gluUnProject(pos.x(), vport[3] - pos.y(), 0,
                 viewport.viewport_data.modelview,
                 viewport.viewport_data.projection, vport, &near.data[0],
                 &near.data[1], &near.data[2]);
    gluUnProject(pos.x(), vport[3] - pos.y(), 1,
                 viewport.viewport_data.modelview,
                 viewport.viewport_data.projection, vport, &far.data[0],
                 &far.data[1], &far.data[2]);

    // extract pick ray and perform pick selection
    viewport.selectObjectsFromRay(near, far);
  }
}

void LeftClick::move(BaseViewport & /*viewport*/, QMouseEvent * /*event*/,
                     InputStateMachine *input) {
  input->changeToLeftDrag();
}
} // namespace InputStates
