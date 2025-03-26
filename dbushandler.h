#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>

class DBusHandler : public QObject
{
    Q_OBJECT

public:

    explicit DBusHandler(QObject *parent = nullptr);

    int getNetworkState();
    int getAvailableMemory();
    int getCpuUsage();


};

#endif // DBUSHANDLER_H
