#ifndef VIEWPORT_STATE_STRAIN11_HPP
#define VIEWPORT_STATE_STRAIN11_HPP


#include <QMouseEvent>

#include "../../fem/Node.h++"
#include "ViewportState.h++"
#include "../BaseViewport.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../../fem/AnalysisResult.h++"


class BaseViewport;

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateStrain11
	:public ViewportState<BaseViewport>
{
	protected:
		std::map<size_t, fem::Node> 	displaced_nodes;
		std::map<size_t, fem::Node> 	displacements;
		std::map<size_t, fem::Node>	*original_nodes;

	public:
		VPStateStrain11();
		~VPStateStrain11();

		void initialize(BaseViewport *mv);
		void populateScenegraph(BaseViewport *mv);
		void paintGL(BaseViewport *mv);
		void mousePressEvent(BaseViewport *mv, QMouseEvent *event);
		// void mouseMoveEvent(QMouseEvent *event);
		void keyPressEvent ( BaseViewport *mv, QKeyEvent * event );
};


#endif
