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

	void test_triangle_rules_Triangle1();
	void test_triangle_rules_Triangle3();
	void test_triangle_rules_Triangle6();
	void test_triangle_rules_Triangle7();

	void test_tetrahedron_rules_Tetrahedron1();
	void test_tetrahedron_rules_Tetrahedron4();
	void test_tetrahedron_rules_Tetrahedron8();
	void test_tetrahedron_rules_Tetrahedron14();
};


#endif
