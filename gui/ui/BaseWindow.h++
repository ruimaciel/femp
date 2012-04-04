#ifndef BASE_WINDOW_HPP
#define BASE_WINDOW_HPP

#include <QString>

/**
Base class for every MDI window class, 
This class is used to update the MDI window menu.  
This is a crude hack, as this role was intended for 
MdiWindow but adding non-opengl MDI windows made it a 
bit unwielding to rewrite.
**/
class BaseWindow
{
protected:
	QString	m_window_label;	// label that describes this window
	
public:
	/**
	@param label	window label
	@param parent	this widget's parent widget
	**/
	BaseWindow(QString const & label);

	/** 
	Returns this window's label
	**/
	QString label() const;
};

#endif
