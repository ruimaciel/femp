#include "WindowWithWireframe.h++"

#include <QString>


WindowWithWireframe::WindowWithWireframe( QWidget *parent)
	: MdiWindow(parent)
{
}


void WindowWithWireframe::createToolbar()
{
	elementRenderingComboBox = new QComboBox(this);

	elementRenderingComboBox->insertItem(R_WIREFRAMES, "Wireframe");
	elementRenderingComboBox->insertItem(R_SURFACES, "Surface");
	elementRenderingComboBox->insertItem(R_BOTH, "Both");

	toggleElementRenderingToolBar = addToolBar(tr("Element rendering"));
	toggleElementRenderingToolBar->addWidget(elementRenderingComboBox);
}


