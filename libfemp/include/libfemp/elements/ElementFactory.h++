#ifndef FEMP_ELEMENTS_FACTORY_HPP
#define FEMP_ELEMENTS_FACTORY_HPP

#include <vector>

#include <libfemp/elements/BaseElement.h++>
#include <libfemp/Element.h++>



/**
 * Factory function created to ease the transition to properly polymorphic element definitions
 **/
fem::BaseElement * getElement(fem::Element const &old_element);


#endif
