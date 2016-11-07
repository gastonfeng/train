#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <android.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType < androidInfo > ("AndroidInfo", 1, 0, "AndroidInfo");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
