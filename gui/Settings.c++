#include "Settings.h++"

#include <QSettings>
#include <QDir>
#include <QColor>


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

ViewportColors Settings::getViewportColors()
{
	QSettings settings;
	settings.beginGroup("viewport");

	ViewportColors viewportColors;

	// helper lambda function
	auto setColorOption = [&](const QString &label,  std::array<GLfloat,4> &defaultColor)
	{
		if(settings.contains(label))
		{
			const QVariant value = settings.value(label);
			if(value.canConvert<QColor>() == true) {
				const QColor color = value.value<QColor>();
				defaultColor = { (float)color.red(), (float)color.green(), (float)color.blue(), (float)color.alpha() };
			}
		}
	};

	setColorOption("nodes.color", 					viewportColors.node);
	setColorOption("background.color",				viewportColors.background);
	setColorOption("wireframe.color",				viewportColors.wireframe);
	setColorOption("fields.color.maximum_positive",	viewportColors.field_maximum_positive);
	setColorOption("fields.color.maximum_negative",	viewportColors.field_maximum_negative);
	setColorOption("fields.color.neutral",			viewportColors.field_neutral);

	settings.endGroup();

	return viewportColors;
}
