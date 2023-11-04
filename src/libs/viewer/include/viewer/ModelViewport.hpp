#ifndef GUI_VIEWER_MODELVIEWPORT_HPP
#define GUI_VIEWER_MODELVIEWPORT_HPP

// viewer includes
#include <viewer/BaseViewport.hpp>

#include "ViewportStates/VPStateModel.hpp"

// gui includes
#include "Project.hpp"

// Qt includes
#include <QWidget>

/**
 * The viewport class which is designed to render the model and enact changes on
 * it
 */
class ModelViewport : public BaseViewport {
	Q_OBJECT

	public:
	ModelViewport(fem::Project& project, QWidget* parent = nullptr);
	~ModelViewport();

	/**
	 * Set the viewport state
	 */
	void showModel();

	protected:
	VPStateModel m_vp_state_model;
};

#endif
