#ifndef FEMP_ELEMENTS_FACTORY_HPP
#define FEMP_ELEMENTS_FACTORY_HPP

#include <libfemp/Element.hpp>
#include <libfemp/elements/BaseElement.hpp>
#include <vector>

/**
 * Factory function created to ease the transition to properly polymorphic
 * element definitions.
 **/
fem::BaseElement* getElement(fem::Element const& old_element);

#endif
