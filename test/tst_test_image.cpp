#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class test_image : public QObject
{
    Q_OBJECT

public:
    test_image();
    ~test_image();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test_image::test_image()
{

}

test_image::~test_image()
{

}

void test_image::initTestCase()
{

}

void test_image::cleanupTestCase()
{

}

void test_image::test_case1()
{
QLable lable;
lable.setIcon();
}

QTEST_MAIN(test_image)

#include "tst_test_image.moc"
