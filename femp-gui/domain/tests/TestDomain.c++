#include <QtTest/QtTest>

#include <Model.h++>


class TestDomain: public QObject
{
    Q_OBJECT

private slots:
    void toUpper()
    {

    }
};

QTEST_MAIN(TestDomain)
#include "TestDomain.moc"
