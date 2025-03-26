#ifndef MONITOR_H
#define MONITOR_H

#include <QObject>
#include"dbushandler.h"

class Monitor : public QObject
{
    Q_OBJECT

public:

    explicit Monitor(QObject *parent = nullptr);

    void startMonitoring();


signals:

    void newData(int cpu, int memory,int network);

private:

    DBusHandler dbusHandler;


};

#endif // MONITOR_H
