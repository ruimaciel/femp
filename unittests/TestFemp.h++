#ifndef TEST_FEMP_CPP
#define TEST_FEMP_CPP

#include <QtTest/QtTest>


/**
* Unit tests for libla
**/
class TestFemp
	: public QObject
{
	Q_OBJECT

private slots:
	void test_GlobalDof_order();

	void test_GlobalDofMap_insertion();
};


#endif
