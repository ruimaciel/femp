#include "TestFemp.h++"

#include <libfemp/Point.h++>
#include <libfemp/Node.h++>
#include <libfemp/GlobalDof.h++>
#include <libfemp/GlobalDofMap.h++>


void 
TestFemp::test_GlobalDof_order()
{
	using namespace fem;

	Node n( Point(0,0,0) );

	auto px = ParameterType::dx;
	GlobalDof dof1( n, px);

	auto py = ParameterType::dy;
	GlobalDof dof2( n, py);

	QVERIFY( dof1 < dof2 );
}


void 
TestFemp::test_GlobalDofMap_insertion()
{
	using namespace fem;

	Node n( Point(0,0,0) );

	auto px = ParameterType::dx;
	GlobalDof dof1( n, px);

	auto py = ParameterType::dy;
	GlobalDof dof2( n, py);

	GlobalDofMap mapping;

	// push the first GlobalDof
	mapping.pushGlobalDof(dof1);

	size_t index1 = 0;
	index1 = mapping.getIndex(dof1);

	QVERIFY( index1 == 0 );

	// push another GlobalDof
	mapping.pushGlobalDof(dof2);

	size_t index2 = 0;
	index2 = mapping.getIndex(dof2);

	QVERIFY( index2 == 1 );
}

