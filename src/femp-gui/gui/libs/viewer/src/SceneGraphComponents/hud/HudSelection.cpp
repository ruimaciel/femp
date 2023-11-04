#include "HudSelection.hpp"

#include <GL/gl.h>

namespace hud {

Selection::Selection() {
	m_on = false;
}

void Selection::paintGL(ViewportData& /*data*/, ViewportColors& /*colors*/) {
	if (m_on) {
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();

		GLfloat vp[4];
		glGetFloatv(GL_VIEWPORT, vp);
		glOrtho(vp[0], vp[2], vp[3], vp[1], -1, 1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glDisable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);

		glColor4f(1, 0, 0, 0.25);  // TODO fix this
		glBegin(GL_QUADS);
		glVertex2f(m_end.x(), m_end.y());
		glVertex2f(m_end.x(), m_start.y());
		glVertex2f(m_start.x(), m_start.y());
		glVertex2f(m_start.x(), m_end.y());
		glVertex2f(m_end.x(), m_end.y());
		glEnd();

		glColor3f(1, 0, 0);	 // TODO fix this
		glBegin(GL_LINE_STRIP);
		glVertex2f(m_end.x(), m_end.y());
		glVertex2f(m_end.x(), m_start.y());
		glVertex2f(m_start.x(), m_start.y());
		glVertex2f(m_start.x(), m_end.y());
		glVertex2f(m_end.x(), m_end.y());
		glEnd();
		glEnable(GL_DEPTH_TEST);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
	}
}

void Selection::setStart(fem::Point3D const& p) {
	m_on = true;
	m_start = p;
	m_end = p;
}

void Selection::setEnd(fem::Point3D const& p) {
	m_end = p;
}

void Selection::off() {
	m_on = false;
}

}  // namespace hud
