#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "ViewportColors.h++"
#include "DisplayOptions.h++"

class Options
{
public:
	static Options & getInstance()
	{
		static Options instance;

		return instance;
	}

public:
	Options(Options const &) = delete;
	void operator= (Options const &) = delete;


	/**
	 * returns the viewport colors
	 **/
	ViewportColors &getViewportColors();

	/**
	 * returns the display options
	 **/
	DisplayOptions &getDisplayOptions();

private:
	Options() {}

	ViewportColors m_viewportColors;
	DisplayOptions m_displayOptions;

};

#endif
