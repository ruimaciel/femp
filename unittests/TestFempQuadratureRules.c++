#include "TestFempQuadratureRules.h++"

#include <libfemp/quadrature_rules/Line.h++>


void 
TestFempQuadratureRules::test_line_rules_GaussLegendre1()
{
	using namespace fem;

	// constant function 
	auto f = [](double)->double {return 1.0f;};

	auto gauss1 = GaussLegendre1();

	double A = 0;
	const double A_exact = 2.0;
	for(auto point: gauss1())
	{
		A += point.weight*f( point.x[0] );
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void 
TestFempQuadratureRules::test_line_rules_GaussLegendre2()
{
	using namespace fem;

	// constant function 
	auto f = [](double x)->double {return x*x;};

	auto quadrature_rule = GaussLegendre2();

	double A = 0;
	const double A_exact = 2.0/3.0;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0] );
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}



void 
TestFempQuadratureRules::test_line_rules_GaussLegendre3()
{
	using namespace fem;

	// constant function 
	auto f = [](double x)->double {return x*x*x+1;};

	auto quadrature_rule = GaussLegendre3();

	double A = 0;
	const double A_exact = 2.0;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0] );
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


