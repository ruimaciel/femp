#ifndef TEST_FEMP_QUADRATURE_RULES_CPP
#define TEST_FEMP_QUADRATURE_RULES_CPP

#include <QtTest/QtTest>


/**
* Unit tests for libla
**/
class TestFempQuadratureRules
	: public QObject
{
	Q_OBJECT

private slots:
	void test_line_rules_GaussLegendre1();
	void test_line_rules_GaussLegendre2();
	void test_line_rules_GaussLegendre3();
	void test_line_rules_Simpson();

	void test_square_rules_SquareCartesianProduct();

	void test_square_rules_CubeCartesianProduct();
};


#endif
