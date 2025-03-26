#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include<QRunnable>
#include <QDebug>

class Sender : public QObject , public QRunnable
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr);

signals:

    void mySignal(int value);



public:

    void run() override{

         emit mySignal(7);
        qDebug()<<"smiles thread2";
    }


public slots:
    void mySlot(int value);
};

#endif // SENDER_H
