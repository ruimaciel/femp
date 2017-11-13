#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "ViewportColors.h++"

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

private:
	Options() {}

	ViewportColors m_viewportColors;

};

#endif
