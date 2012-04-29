#include "WindowWithWireframe.h++"

#include <QObject>	// for tr()
#include <QString>


void WindowWithWireframe::createToolbar(QMainWindow *parent)
{
	elementRenderingComboBox = new QComboBox(parent);

	elementRenderingComboBox->insertItem(R_WIREFRAMES, QObject::tr("Wireframe"));
	elementRenderingComboBox->insertItem(R_SURFACES, QObject::tr("Surface"));
	elementRenderingComboBox->insertItem(R_BOTH, QObject::tr("Both"));

	toggleElementRenderingToolBar = parent->addToolBar( QObject::tr("Element rendering"));
	toggleElementRenderingToolBar->addWidget(elementRenderingComboBox);
}


