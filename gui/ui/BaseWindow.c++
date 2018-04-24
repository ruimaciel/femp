#include "BaseWindow.h++"


BaseWindow::BaseWindow(QString const &label)
{
	this->m_windowLabel = label;
}


QString 
BaseWindow::label() const
{
	return m_windowLabel;
}


