#ifndef FEMP_SETTINGS_H
#define FEMP_SETTINGS_H

#include <QDir>

#include "options/ViewportColors.h++"

class FempSettings
{
public:

private:
	FempSettings();
	FempSettings(const FempSettings &) = delete;
	void operator=(const FempSettings &) = delete;
	~FempSettings();

public:
	static FempSettings & getInstance()
	{
		static FempSettings settings;
		return settings;
	}

	QDir getProjectOpenDirectory();
	void setProjectOpenDirectory(QDir dir);

	QDir getDumpResultsDirectory();
	void setDumpResultsDirectory(QDir dir);

	ViewportColors getViewportColors();
};

#endif // FEMP_SETTINGS_H
