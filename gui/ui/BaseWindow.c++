#include "BaseWindow.h++"


BaseWindow::BaseWindow(QString const &label)
{
	this->m_window_label = label;
}


QString 
BaseWindow::label() const
{
	return m_window_label;
}


