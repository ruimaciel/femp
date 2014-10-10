#include <QTest>

#include "TestLa.h++"
#include "TestFemp.h++"


int main(int argc, char *argv[])
{
	TestLa test_la;
	TestFemp test_femp;

	QTest::qExec(&test_la, argc, argv);
	QTest::qExec(&test_femp, argc, argv);

	return 0;
}
