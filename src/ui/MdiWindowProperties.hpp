#ifndef FEMP_UI_MDIWINDOWPROPERTIES_HPP
#define FEMP_UI_MDIWINDOWPROPERTIES_HPP

/**
 * This class is used by the UI routines in order to provide information
 * regarding the features supported by each MDI window.
 */
class MdiWindowProperties {
	public:
	enum WindowType { MWP_None, MWP_Model, MWP_Displacements } window_type;

	public:
	explicit MdiWindowProperties(enum WindowType type = MWP_None);
};

#endif
