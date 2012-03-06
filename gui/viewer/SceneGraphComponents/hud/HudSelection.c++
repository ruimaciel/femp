#include "HudSelection.h++"

#include <iostream>
#include <GL/gl.h>

namespace hud
{


Selection::Selection()
{
	//TODO test only
	m_start.set(1,2);
	m_end.set(2,1);
}


void 
Selection::paintGL(ViewportData &data, ViewportColors &colors)
{
	if(m_on)
	{
		//glDisable(GL_DEPTH_TEST);
		//glClear(GL_COLOR_BUFFER_BIT);

		
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glColor3f(1,0,0);	//TODO fix this

		glTranslatef(0,0,-20);
		glBegin(GL_LINE_STRIP);
		glVertex2f(m_end.x(), m_end.y());
		glVertex2f(m_end.x(), m_start.y());
		glVertex2f(m_start.x(), m_start.y());
		glVertex2f(m_start.x(), m_end.y());
		glVertex2f(m_end.x(), m_end.y());
		glEnd();
		glPopMatrix();
		// */
	}
}


void 
Selection::setStart(float &x, float &y)
{
	m_on = true;
	m_start.set(x,y);
}


void 
Selection::setEnd(float &x, float &y)
{
	m_end.set(x,y);
}


}	// namespace hud
