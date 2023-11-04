#include "QuadratureRulesOptionsDialog.hpp"

#include "ui_QuadratureRulesOptionsDialog.h"

QuadratureRulesOptionsDialog::QuadratureRulesOptionsDialog(fem::Analysis<double>& analysis, QWidget* parent)
	: QDialog(parent), m_ui(std::make_unique<Ui::QuadratureRulesOptionsDialog>()) {
	m_ui->setupUi(this);

	this->analysis = &analysis;

	connect(m_ui->buttonBox, SIGNAL(accepted()), this, SLOT(setQuadratureRule()));

	this->setSpinBoxValues();
}

QuadratureRulesOptionsDialog::~QuadratureRulesOptionsDialog() = default;

void QuadratureRulesOptionsDialog::setSpinBoxValues() {
	// STIFFNESS
	m_ui->spinBox_sh8->setValue(analysis->hexa8.stiffness_degree);
	m_ui->spinBox_sh20->setValue(analysis->hexa20.stiffness_degree);
	m_ui->spinBox_sh27->setValue(analysis->hexa27.stiffness_degree);

	m_ui->spinBox_st4->setValue(analysis->tetra4.stiffness_degree);
	m_ui->spinBox_st10->setValue(analysis->tetra10.stiffness_degree);

	m_ui->spinBox_sp6->setValue(analysis->prism6.stiffness_degree);
	m_ui->spinBox_sp15->setValue(analysis->prism15.stiffness_degree);
	m_ui->spinBox_sp18->setValue(analysis->prism18.stiffness_degree);

	// DOMAIN
	m_ui->spinBox_dh8->setValue(analysis->hexa8.domain_degree);
	m_ui->spinBox_dh20->setValue(analysis->hexa20.domain_degree);
	m_ui->spinBox_dh27->setValue(analysis->hexa27.domain_degree);

	m_ui->spinBox_dt4->setValue(analysis->tetra4.domain_degree);
	m_ui->spinBox_dt10->setValue(analysis->tetra10.domain_degree);

	m_ui->spinBox_dp6->setValue(analysis->prism6.domain_degree);
	m_ui->spinBox_dp15->setValue(analysis->prism15.domain_degree);
	m_ui->spinBox_dp18->setValue(analysis->prism18.domain_degree);

	// SURFACE loads
	m_ui->spinBox_Su_tri3->setValue(analysis->tri3.domain_degree);
	m_ui->spinBox_Su_tri6->setValue(analysis->tri6.domain_degree);

	m_ui->spinBox_Su_quad4->setValue(analysis->quad4.domain_degree);
	m_ui->spinBox_Su_quad8->setValue(analysis->quad8.domain_degree);
	m_ui->spinBox_Su_quad9->setValue(analysis->quad9.domain_degree);
}

void QuadratureRulesOptionsDialog::setQuadratureRule() {
	// STIFFNESS
	analysis->hexa8.stiffness_degree = m_ui->spinBox_sh8->value();
	analysis->hexa20.stiffness_degree = m_ui->spinBox_sh20->value();
	analysis->hexa27.stiffness_degree = m_ui->spinBox_sh27->value();

	analysis->tetra4.stiffness_degree = m_ui->spinBox_st4->value();
	analysis->tetra10.stiffness_degree = m_ui->spinBox_st10->value();

	analysis->prism6.stiffness_degree = m_ui->spinBox_sp6->value();
	analysis->prism15.stiffness_degree = m_ui->spinBox_sp15->value();
	analysis->prism18.stiffness_degree = m_ui->spinBox_sp18->value();

	// DOMAIN
	analysis->hexa8.domain_degree = m_ui->spinBox_dh8->value();
	analysis->hexa20.domain_degree = m_ui->spinBox_dh20->value();
	analysis->hexa27.domain_degree = m_ui->spinBox_dh27->value();

	analysis->tetra4.domain_degree = m_ui->spinBox_dt4->value();
	analysis->tetra10.domain_degree = m_ui->spinBox_dt10->value();

	analysis->prism6.domain_degree = m_ui->spinBox_dp6->value();
	analysis->prism15.domain_degree = m_ui->spinBox_dp15->value();

	// SURFACE
	analysis->tri3.domain_degree = m_ui->spinBox_Su_tri3->value();
	analysis->tri6.domain_degree = m_ui->spinBox_Su_tri6->value();

	analysis->quad4.domain_degree = m_ui->spinBox_Su_quad4->value();
	analysis->quad8.domain_degree = m_ui->spinBox_Su_quad8->value();
	analysis->quad9.domain_degree = m_ui->spinBox_Su_quad9->value();
	// TODO finish this
}
