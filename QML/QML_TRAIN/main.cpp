#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <android.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("AndroidInfo", new androidInfo()); //将object挂到QML
//    qmlRegisterType < androidInfo > ("AndroidInfo", 1, 0, "AndroidInfo");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
