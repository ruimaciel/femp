#include "WindowWithResults.h++"

#include <QObject>	// for tr()
#include <QMainWindow>
#include <QComboBox>
#include <QToolBar>
#include <QString>


void WindowWithResults::createToolbar(QMainWindow *parent, fem::Project &project)
{
	m_comboBoxResults = new QComboBox(parent);
	QString text;

	for(size_t n = 0; n < project.result.size(); n++)
	{
		text.setNum(n);
		m_comboBoxResults->insertItem(n, text);
	}

	m_toolBarResults = parent->addToolBar(QObject::tr("Results"));
	m_toolBarResults->addWidget(m_comboBoxResults);
}


