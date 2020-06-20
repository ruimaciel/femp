#include <QtTest/QtTest>

class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void toUpper()
    {

    }
};

QTEST_MAIN( TestGui )
#include "TestGui.moc"
