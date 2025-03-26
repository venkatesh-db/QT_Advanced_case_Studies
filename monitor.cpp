#include "monitor.h"
#include<QTimer>

Monitor::Monitor(QObject *parent)
    : QObject{parent}
{}

/*
   void Monitor::startMonitoring()
   {

       QTimer *times = new QTimer(this);
       QObject::connect( times,&QTimer::timeout ,this,[=](){


         int cpu=  dbusHandler.getCpuUsage();
           int memory= dbusHandler.getAvailableMemory();
        int network=   dbusHandler.getNetworkState();

           emit newData(cpu,memory,network);


       });

       times->start(1000);



   }

*/

void Monitor::startMonitoring() {
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, [=]() {
   //    int cpu = dbusHandler.getCpuUsage();
       int memory = dbusHandler.getAvailableMemory();
     //   int network = dbusHandler.getNetworkState();

        emit newData(0, memory, 0);
    });

    timer->setInterval(1000); // ✅ Set interval before start
    timer->start();
}

