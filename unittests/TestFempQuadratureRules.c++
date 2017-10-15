#include "TestFempQuadratureRules.h++"

#include <libfemp/quadrature_rules/Line.h++>
#include <libfemp/quadrature_rules/Quadrangle.h++>
#include <libfemp/quadrature_rules/Cube.h++>
#include <libfemp/quadrature_rules/Triangle.h++>
#include <libfemp/quadrature_rules/Tetrahedron.h++>


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


void 
TestFempQuadratureRules::test_line_rules_Simpson()
{
	using namespace fem;

	// constant function 
	auto f = [](double x)->double {return x*x*x+1;};

	auto quadrature_rule = Simpson();

	double A = 0;
	const double A_exact = 2.0;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0] );
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}

void 
TestFempQuadratureRules::test_quadrangle_rules_QuadrangleCartesianProduct()
{
	using namespace fem;

	// constant function 
	auto f = [](double x, double y)->double {return (x*x*x+1)*(y*y*y+1);};

	auto quadrature_rule = QuadrangleCartesianProduct( new GaussLegendre3(), new GaussLegendre3() );

	double A = 0;
	const double A_exact = 4.0;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1] );
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_square_rules_CubeCartesianProduct()
{
	using namespace fem;

	// cubic function 
	auto f = [](double x, double y, double z)->double {return (x*x*x+1)*(y*y*y+1)*(z*z*z+1);};

	auto quadrature_rule = CubeCartesianProduct( new GaussLegendre3(), new GaussLegendre3(), new GaussLegendre3() );

	double A = 0;
	const double A_exact = 8.0;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1], point.x[2] );
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_triangle_rules_Triangle1()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double )->double {return 1.0; };

	auto quadrature_rule = Triangle1();

	double A = 0;
	const double A_exact = 0.5;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_triangle_rules_Triangle3()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double )->double {return 1.0; };

	auto quadrature_rule = Triangle3();

	double A = 0;
	const double A_exact = 0.5;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_triangle_rules_Triangle6()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double )->double {return 1.0; };

	auto quadrature_rule = Triangle6();

	double A = 0;
	const double A_exact = 0.5;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_triangle_rules_Triangle7()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double )->double {return 1.0; };

	auto quadrature_rule = Triangle7();

	double A = 0;
	const double A_exact = 0.5;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_tetrahedron_rules_Tetrahedron1()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double, double )->double {return 1.0; };

	auto quadrature_rule = Tetrahedron1();

	double A = 0;
	const double A_exact = 1.0/6;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1], point.x[2]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_tetrahedron_rules_Tetrahedron4()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double, double )->double {return 1.0; };

	auto quadrature_rule = Tetrahedron4();

	double A = 0;
	const double A_exact = 1.0/6;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1], point.x[2]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_tetrahedron_rules_Tetrahedron8()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double, double )->double {return 1.0; };

	auto quadrature_rule = Tetrahedron8();

	double A = 0;
	const double A_exact = 1.0/6;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1], point.x[2]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


void
TestFempQuadratureRules::test_tetrahedron_rules_Tetrahedron14()
{
	using namespace fem;

	// cubic function 
	auto f = [](double , double, double )->double {return 1.0; };

	auto quadrature_rule = Tetrahedron14();

	double A = 0;
	const double A_exact = 1.0/6;
	for(auto point: quadrature_rule())
	{
		A += point.weight*f( point.x[0], point.x[1], point.x[2]);
	}

	double delta = 1e-7;
	QVERIFY( abs(A-A_exact) < delta );
}


