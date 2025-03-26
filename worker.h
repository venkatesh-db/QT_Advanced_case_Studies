#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

    void finished();

public slots:

    void Processtask()
    {
        qDebug()<<"helloooo process task";
        emit finished();
    }

};

#endif // WORKER_H
