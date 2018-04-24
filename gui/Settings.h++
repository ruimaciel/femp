#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDir>


class Settings
{
public:
	Settings();
	~Settings();

	QDir getProjectOpenDirectory();
	void setProjectOpenDirectory(QDir dir);
};

#endif // SETTINGS_H
