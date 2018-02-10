#include <QtCore>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include "testrunner.h"
#include <QTest>
#include <QQmlApplicationEngine>
#include "automator.h"
#include <main.h>

QmlTests::QmlTests(QObject *parent):QObject(parent){}

void QmlTests::interactive(){
    QQmlApplicationEngine engine;
    engine.load("qrc:/main.qml");

    Automator automator(&engine);


    Automator::wait(5000);
}
void QmlTests::errorWarning(){
    QQmlApplicationEngine engine;
    Automator automator(&engine);

    //engine.load(QUrl::fromLocalFile(QString(SRCDIR) + "/ItemWithError.qml"));

    QVERIFY(!automator.anyError());
}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);

    TestRunner runner;

   // runner.add<QmlTests>();

    // Run Qt Quick Test in SRCDIR. It will scan all qml file begin with tst_
    runner.add(QString(SRCDIR));

    runner.addImportPath("qrc:///");
    runner.setEngineHook([](QQmlEngine* engine) {

        // You may register image provider / context property here for QtTest

        QVariantMap property;
        property["value1"] = 1;
        engine->rootContext()->setContextProperty("CustomProperty", property);
    });

    bool error = runner.exec(app.arguments());

    if (!error) {
        qWarning() << "All test cases passed!";
    }

    return error;
}
