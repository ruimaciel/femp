#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDir>

#include "options/ViewportColors.h++"

class Settings
{
public:
	Settings();
	~Settings();

	QDir getProjectOpenDirectory();
	void setProjectOpenDirectory(QDir dir);

	ViewportColors getViewportColors();
};

#endif // SETTINGS_H
