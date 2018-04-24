#include "Settings.h++"

#include <QSettings>
#include <QDir>


Settings::Settings()
{

}

Settings::~Settings()
{
	QSettings settings;
	settings.sync();
}

QDir Settings::getProjectOpenDirectory()
{
	QSettings settings;

	QString key = "project.open.default_directory";

	if(settings.contains(key)) {
		QVariant variant = settings.value(key);
		if(variant.isValid())
		{
			QString dirPath = variant.toString();
			QDir dir(dirPath);
			if( dir.exists() )
			{
				return dir;
			}
		}
	}

	return QDir::home();
}

void Settings::setProjectOpenDirectory(QDir dir)
{
	QSettings settings;

	QString key = "project.open.default_directory";

	if(dir.exists()) {
		settings.setValue(key, dir.absolutePath());
	}
}
