#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDir>

#include "options/ViewportColors.h++"

class Settings
{
public:

private:
	Settings();
	Settings(const Settings &) = delete;
	void operator=(const Settings &) = delete;
	~Settings();

public:
	static Settings & getInstance()
	{
		static Settings settings;
		return settings;
	}

	QDir getProjectOpenDirectory();
	void setProjectOpenDirectory(QDir dir);

	QDir getDumpResultsDirectory();
	void setDumpResultsDirectory(QDir dir);

	ViewportColors getViewportColors();
};

#endif // SETTINGS_H
