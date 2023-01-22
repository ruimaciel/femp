#include "WindowWithWireframe.h++"

// Qt includes
#include <QObject>	// for tr()
#include <QString>

void WindowWithWireframe::createToolbar(QMainWindow* parent) {
	m_comboBoxElementRendering = new QComboBox(parent);

	m_comboBoxElementRendering->insertItem(R_WIREFRAMES, QObject::tr("Wireframe"));
	m_comboBoxElementRendering->insertItem(R_SURFACES, QObject::tr("Surface"));
	m_comboBoxElementRendering->insertItem(R_BOTH, QObject::tr("Both"));

	m_toolBarToggleElementRendering = parent->addToolBar(QObject::tr("Element rendering"));
	m_toolBarToggleElementRendering->addWidget(m_comboBoxElementRendering);
}
