#ifndef MODEL_SELECTION_HPP
#define MODEL_SELECTION_HPP

#include <map>

/*
Data structure that holds the lists of all selected model objects
*/
struct ModelSelection
{
	/* 
	true if default is all selected, false if it's all deselected
	it transforms all selection values
	*/
	bool nodes_selection;		// true if all selected, false if all deselected
	bool elements_selection;	// true if all selected, false if all deselected
	bool surfaces_selection;	// true if all selected, false if all deselected

	std::map<size_t,bool> nodes;
	std::map<size_t,bool> elements;
	std::map<size_t,bool> surfaces;

	ModelSelection();
	~ModelSelection();


	void selectNode(const size_t &, bool state = true);
	void selectElement(const size_t &, bool state = true);
	void selectSurface(const size_t &, bool state = true);

	void selectAll(bool state = true);
	void selectAllNodes(bool state = true);
	void selectAllElements(bool state = true);
	void selectAllSurfaces(bool state = true);

	// routines to deselect
	void deselectNode(const size_t &, bool state = false);
	void deselectElement(const size_t &, bool state = false);
	void deselectSurface(const size_t &, bool state = false);

	void deselectAll(bool state = false);
	void deselectAllNodes(bool state = false);
	void deselectAllElements(bool state = false);
	void deselectAllSurfaces(bool state = false);

	bool isNodeSelected(size_t &);
	bool isElementSelected(size_t &);
};

#endif

