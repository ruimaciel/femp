#include "WindowWithResults.hpp"

// Qt includes
#include <QComboBox>
#include <QMainWindow>
#include <QObject>	// for tr()
#include <QString>
#include <QToolBar>

void WindowWithResults::createToolbar(QMainWindow* parent, fem::Project& project) {
	m_comboBoxResults = new QComboBox(parent);
	QString text;

	for (size_t n = 0; n < project.getAnalysisResults().size(); n++) {
		text.setNum(n);
		m_comboBoxResults->insertItem(n, text);
	}

	m_toolBarResults = parent->addToolBar(QObject::tr("Results"));
	m_toolBarResults->addWidget(m_comboBoxResults);
}
