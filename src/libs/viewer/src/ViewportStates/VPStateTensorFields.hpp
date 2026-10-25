#ifndef FEMP_VIEWER_VPSTATETENSORFIELDS_HPP
#define FEMP_VIEWER_VPSTATETENSORFIELDS_HPP

#include <QMouseEvent>
#include <options/Options.hpp>
#include <viewer/ViewportData.hpp>

#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.hpp"
#include "../SceneGraphComponents/ElementRepresentationPolicy/StressFieldRepresentationPolicy.hpp"
#include "../SceneGraphComponents/SceneComponentFactory.hpp"
#include "ViewportState.hpp"

class BaseViewport;

/**
 * A pattern for the State pattern which is used to render the tension fields
 */
class VPStateTensorFields : public ViewportState {
protected:
  StressFieldRepresentationPolicy m_stress_field_representation;
  NoDisplacementsPolicy
      m_displacements; // the displacements view renders displacements
  SGC::SceneComponentFactory m_factory;

public:
  VPStateTensorFields();
  ~VPStateTensorFields();

  void initialize(BaseViewport &viewport) override;
  void populateScenegraph(BaseViewport &viewport) override;

  /**
   * Configures the viewport to render the scene according to new_result
   */
  void setAnalysisResult(fem::AnalysisResult &new_result);
  void setResultsRanges(fem::ResultsRanges<double> &ranges);

  void keyPressEvent(BaseViewport &viewport, QKeyEvent *event) override;

  void showNegativePrincipalStressesVisibility(bool state);
  void showPositivePrincipalStressesVisibility(bool state);
};

#endif
