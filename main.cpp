#include <QCoreApplication>
#include "sender.h"
#include "worker.h"
#include<QThreadPool>
#include<QRunnable>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sender *sender=new Sender();
    Sender receiver;

    // signal & slot should be same class  objects in one threads
    QObject::connect(sender,&Sender::mySignal,sender ,&Sender::mySlot);

   // emit sender.mySignal(7);

    QThreadPool *p= QThreadPool ::globalInstance();

    p->setMaxThreadCount(1);

    p->start(sender );

     //  p->start(new Sender );

    Worker obj;

    return a.exec();
}
