#include <QTest>

#include "TestLa.h++"
#include "TestFempQuadratureRules.h++"
#include "TestFemp.h++"


int main(int argc, char *argv[])
{
	TestLa test_la;
	TestFempQuadratureRules test_femp_quadrature_rules;
	TestFemp test_femp;

	QTest::qExec(&test_la, argc, argv);
	QTest::qExec(&test_femp_quadrature_rules, argc, argv);
	QTest::qExec(&test_femp, argc, argv);

	return 0;
}
