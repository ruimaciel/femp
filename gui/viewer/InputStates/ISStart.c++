#include "ISStart.h++"

#include <iostream>

namespace InputStates
{

void 
Start::leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input)
{
	std::cerr << "Start::leftClick(BaseViewport *viewport, QMouseEvent *event, Input *input)" << std::endl;
}


}

