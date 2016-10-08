#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(QObject *parent=0);

public slots:
    void doWork(const QString &parameter) {
        QString result;
        result=parameter;
        /* ... here is the expensive or blocking operation ... */
        emit resultReady(result);
    }

signals:
    void resultReady(const QString &result);
};

#endif // WORKER_H
