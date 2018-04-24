#include "WindowWithWireframe.h++"

#include <QObject>	// for tr()
#include <QString>


void WindowWithWireframe::createToolbar(QMainWindow *parent)
{
	m_elementRenderingComboBox = new QComboBox(parent);

	m_elementRenderingComboBox->insertItem(R_WIREFRAMES, QObject::tr("Wireframe"));
	m_elementRenderingComboBox->insertItem(R_SURFACES, QObject::tr("Surface"));
	m_elementRenderingComboBox->insertItem(R_BOTH, QObject::tr("Both"));

	m_toggleElementRenderingToolBar = parent->addToolBar( QObject::tr("Element rendering"));
	m_toggleElementRenderingToolBar->addWidget(m_elementRenderingComboBox);
}


