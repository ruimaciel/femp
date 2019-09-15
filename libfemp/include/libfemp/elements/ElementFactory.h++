#ifndef FEMP_ELEMENTS_FACTORY_HPP
#define FEMP_ELEMENTS_FACTORY_HPP

#include <vector>

#include <libfemp/Element.h++>
#include <libfemp/elements/BaseElement.h++>

/**
 * Factory function created to ease the transition to properly polymorphic
 * element definitions.
 **/
fem::BaseElement* getElement(fem::Element const& old_element);

#endif
