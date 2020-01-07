#include "TensorFieldViewport.h++"

#include "SceneGraph.h++"
#include <options/Options.h++>

TensorFieldViewport::TensorFieldViewport(fem::Project& project, fem::AnalysisResult& result, fem::ResultsRanges<double>& ranges, QWidget* parent)
    : BaseViewport(project, parent)
{
    this->m_analysis_result = nullptr;


    this->setState(&m_vp_state_tensor_fields);
    this->setAnalysisResult(result);
    this->setResultsRanges(ranges);

    this->showTensionField();

    this->setFocusPolicy(Qt::StrongFocus);
}

TensorFieldViewport::~TensorFieldViewport()
{
}

void TensorFieldViewport::setAnalysisResult(fem::AnalysisResult& result)
{
    this->m_analysis_result = &result;
    this->m_vp_state_tensor_fields.setAnalysisResult(result);
}

void TensorFieldViewport::setResultsRanges(fem::ResultsRanges<double>& ranges)
{
    this->m_vp_state_tensor_fields.setResultsRanges(ranges);
}

void TensorFieldViewport::showTensionField()
{
    this->setState(&this->m_vp_state_tensor_fields);
}

void TensorFieldViewport::showNegativePrincipalStressesVisibility(bool state)
{
    m_vp_state_tensor_fields.showNegativePrincipalStressesVisibility(state);
}

void TensorFieldViewport::showPositivePrincipalStressesVisibility(bool state)
{
    m_vp_state_tensor_fields.showPositivePrincipalStressesVisibility(state);
}
