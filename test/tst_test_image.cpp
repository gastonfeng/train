#include <QtTest>
#include <QCoreApplication>
#include <QLabel>
#include <QMainWindow>

// add necessary includes here
#include"mcu_def.h"

u16 prjversion=10;
mem_dev *retain_dev;
struct {
    retain_t base;
    int v1;
    int v2;
}dat;
retain_t *retain_dat=(retain_t *)&dat;
u16 retainSize=sizeof(dat);
void __init_retain()
{
    dat.v1=1;
    dat.v2=2;
}
int __publish_retain()
{
    return 1;
}

class test_image : public QObject
{
    Q_OBJECT

public:
    test_image();
    ~test_image();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_retain(){
        retain_dev=file_dev_init("retain.dat",0);
        retain_init();
        retain_output();
    }
    void test_case1();
    void test_case_jpg();
    void test_case_bmp();
};

test_image::test_image()
{

}

test_image::~test_image()
{
    QTime dieTime = QTime::currentTime().addMSecs(10000);

    while( QTime::currentTime() < dieTime )

        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void test_image::initTestCase()
{

}

void test_image::cleanupTestCase()
{

}

void test_image::test_case1()
{
    QMainWindow *mainWindow = new QMainWindow;
    QLabel *label=new QLabel(mainWindow);
    QPixmap pix(":/clock.png");
    //label->setStyleSheet("border-image:url(:/clock.png);");
    label->setScaledContents( true );

    label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    label->setPixmap(pix);
    label->resize(200,200);
    label->show();
    mainWindow->resize(400, 400);   //设置主窗体大小
    mainWindow->setWindowTitle("Qt Test");  //设置主窗体标签
    mainWindow->show();
}

void test_image::test_case_jpg()
{
    QMainWindow *mainWindow = new QMainWindow;
    QLabel *label=new QLabel(mainWindow);
    QPixmap pix(":/test.jpg");
    //label->setStyleSheet("border-image:url(:/test.jpg);");
    label->setText("JPG");
    label->resize(200,200);
    label->setPixmap(pix);
    label->show();
    mainWindow->resize(400, 400);   //设置主窗体大小
    mainWindow->setWindowTitle("Qt Test");  //设置主窗体标签
    mainWindow->show();
}

void test_image::test_case_bmp()
{
    QMainWindow *mainWindow = new QMainWindow;
    QLabel *label=new QLabel(mainWindow);
    QPixmap pix(":/test.bmp");
    //label->setStyleSheet("border-image:url(:/test.bmp);");
    label->resize(200,200);
    label->setPixmap(pix);
    label->show();
    mainWindow->resize(400, 400);   //设置主窗体大小
    mainWindow->setWindowTitle("Qt Test");  //设置主窗体标签
    mainWindow->show();
}

QTEST_MAIN(test_image)

#include "tst_test_image.moc"
