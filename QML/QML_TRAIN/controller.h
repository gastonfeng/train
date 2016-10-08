#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include <worker.h>

class Controller : public QObject
{
    Q_OBJECT
        QThread workerThread;
    public:
        Controller(QObject *parent=0);
        ~Controller() {
            workerThread.quit();
            workerThread.wait();
        }
    public slots:
        void handleResults(const QString & val){
            emit result(val);
        }

    signals:
        void operate(const QString &);
        void result(const QString& result);
};

#endif // CONTROLLER_H
