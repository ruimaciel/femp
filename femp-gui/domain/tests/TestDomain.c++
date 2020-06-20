#include <QtTest/QtTest>

#include <domain/Model.h++>


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
