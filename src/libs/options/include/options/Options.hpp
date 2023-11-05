#ifndef GUI_OPTIONS_HPP
#define GUI_OPTIONS_HPP

#include <QDir>
#include <options/DisplayOptions.hpp>
#include <options/ViewportColors.hpp>

class Options {
	public:
	static Options& getInstance() {
		static Options instance;

		return instance;
	}

	public:
	Options(Options const&) = delete;
	void operator=(Options const&) = delete;

	/**
	 * returns the viewport colors
	 */
	ViewportColors& getViewportColors();

	/**
	 * returns the display options
	 */
	DisplayOptions& getDisplayOptions();

	QDir getProjectOpenDirectory();
	void setProjectOpenDirectory(QDir dir);

	QDir getDumpResultsDirectory();
	void setDumpResultsDirectory(QDir dir);

	private:
	Options() {}

	ViewportColors m_viewportColors;
	DisplayOptions m_displayOptions;
};

#endif
