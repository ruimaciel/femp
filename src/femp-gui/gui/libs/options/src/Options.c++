#include <options/Options.h++>

#include <QSettings>

ViewportColors& Options::getViewportColors() {
	return m_viewportColors;
}

DisplayOptions& Options::getDisplayOptions() {
	return m_displayOptions;
}

QDir Options::getProjectOpenDirectory() {
	QSettings settings;

	QString key = "project.open.default_directory";

	if (settings.contains(key)) {
		QVariant variant = settings.value(key);
		if (variant.isValid()) {
			QString dirPath = variant.toString();
			QDir dir(dirPath);
			if (dir.exists()) {
				return dir;
			}
		}
	}

	return QDir::home();
}

void Options::setProjectOpenDirectory(QDir dir) {
	QSettings settings;

	QString key = "project.open.default_directory";

	if (dir.exists()) {
		settings.setValue(key, dir.absolutePath());
	}
}

QDir Options::getDumpResultsDirectory() {
	QSettings settings;

	const QString key = "project.results.dump.default_directory";

	QDir default_path = QDir::home();

	if (settings.contains(key)) {
		QVariant variant = settings.value(key);
		if (variant.isValid() && variant.canConvert<QString>()) {
			QString path = variant.toString();
			if (QFile::exists(path)) {
				default_path = QDir(path);
			} else {
				settings.setValue(key, QVariant(default_path.absolutePath()));
			}
		}
	}

	return default_path;
}

void Options::setDumpResultsDirectory(QDir dir) {
	QSettings settings;

	const QString key = "project.results.dump.default_directory";

	if (dir.exists()) {
		settings.setValue(key, dir.absolutePath());
	}
}
