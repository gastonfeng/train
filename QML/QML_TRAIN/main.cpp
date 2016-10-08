#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Controller.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType < Controller > ("Controller", 1, 0, "Controller");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
