#include "WindowWithResults.h++"

#include <QObject>	// for tr()
#include <QString>


void WindowWithResults::createToolbar(QMainWindow *parent, fem::Project &project)
{
	m_resultsComboBox = new QComboBox(parent);
	QString text;

	for(size_t n = 0; n < project.result.size(); n++)
	{
		text.setNum(n);
		m_resultsComboBox->insertItem(n, text);
	}

	m_resultsToolBar = parent->addToolBar(QObject::tr("Results"));
	m_resultsToolBar->addWidget(m_resultsComboBox);
}


