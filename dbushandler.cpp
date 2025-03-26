#include "dbushandler.h"
#include<QDebug>
#include<QtDBus/QtDBus>
#include <unistd.h> // For sleep()

DBusHandler::DBusHandler(QObject *parent)
    : QObject{parent}
{}


/*
int DBusHandler::getAvailableMemory() {
    QFile file("/proc/meminfo");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "ERROR: Could not open /proc/meminfo!";
        return -1;
    }

    QTextStream in(&file);
    int memAvailable = -1;

    qDebug() << "DEBUG: Reading /proc/meminfo...";  // Debug log

    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << "DEBUG: Line Read -> " << line;  // Print each line

        if (line.startsWith("MemAvailable:")) {
            QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            if (values.size() >= 2) {
                memAvailable = values[1].toInt();
            }
            break;
        }
    }

    file.close();

    if (memAvailable == -1) {
        qDebug() << "ERROR: Could not find MemAvailable in /proc/meminfo!";
    } else {
        qDebug() << "SUCCESS: Available Memory -> " << memAvailable << " KB";
    }

    return memAvailable;
}
*/

int DBusHandler::getAvailableMemory() {

    QFile file("/proc/meminfo");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "ERROR: Could not open /proc/meminfo!";
        return -1;
    }

//    QTextStream in(&file);

   int memAvailable = -1;

    QString content =file.readAll();

//    qDebug() << "contentx "<<content;


    QStringList lines =content.split("\n");

    for (const QString &line : lines)
    {
        if (line.startsWith("MemTotal:"))
        {
        qDebug() << "for loop "<<line;


        break;
        }
    }


   //   content.split()

   // QString line = in.readLine().trimmed();  // Remove extra spaces

   //  qDebug() << "line "<<line;







     /*
    while (!in.atEnd()) {

        qDebug() << "while loop";

        QString line = in.readLine().trimmed();  // Remove extra spaces

        qDebug() << "line "<<line;

        if (line.startsWith("MemAvailable")) {  // Find the right line

            QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            if (values.size() >= 2) {
                memAvailable = values[1].toInt();
            }
            break;  // Stop searching after finding it
        }
    }

*/

    file.close();

    memAvailable= 63;

        //16376732;

    qDebug() << "SUCCESS: Available Memory -> " << memAvailable << " KB";


    return memAvailable;
}



/*

int DBusHandler::getAvailableMemory() {
    QFile file("/proc/meminfo");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "ERROR: Could not open /proc/meminfo!";
        return -1;
    }

    QTextStream in(&file);
    int memAvailable = -1;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("MemAvailable:")) {
            QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            if (values.size() >= 2) {
                memAvailable = values[1].toInt();
            }
            break;  // Exit loop once we find MemAvailable
        }
    }

    file.close();

    if (memAvailable == -1) {
        qDebug() << "ERROR: Could not find MemAvailable in /proc/meminfo!";
    } else {
        qDebug() << "Available Memory: " << memAvailable << " KB";
    }

    return memAvailable;
}


*/


/*
int DBusHandler::getAvailableMemory() {
    QFile file("/proc/meminfo");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "ERROR: Could not open /proc/meminfo!";
        return -1;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("MemAvailable:")) {
            QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            if (values.size() < 2) {
                qDebug() << "ERROR: Invalid MemAvailable format!";
                return -1;
            }
            int availableMemory = values[1].toInt();
            qDebug() << "Available Memory: " << availableMemory << "KB";
            return availableMemory;
        }
    }

    qDebug() << "ERROR: Could not find MemAvailable in /proc/meminfo!";
    return -1;
}

*/

/*
int DBusHandler:: getNetworkState()
{


    QDBusInterface nm("org.freedesktop.NetworkManager","/org/freedesktop/NetworkManager",
                      "org.freedesktop.NetworkManager",QDBusConnection::systemBus());

    if (! nm.isValid())
    {
        qDebug()<<"invalid network amnager";
    }


    QDBusReply<uint> reply= nm.call("state");

    qDebug()<<"smiling network manager";

    return reply.isValid()? reply.value():-1;

}
*/

/*
int DBusHandler::getNetworkState() {
    QDBusInterface nm("org.freedesktop.NetworkManager",
                      "/org/freedesktop/NetworkManager",
                      "org.freedesktop.NetworkManager",
                      QDBusConnection::systemBus());

    if (!nm.isValid()) {
        qDebug() << "Could not connect to NetworkManager!";
        return -1;
    }

    QDBusReply<uint> reply = nm.call("state");

    if (!reply.isValid()) {
        qDebug() << "Failed to get network state!";
        return -1;
    }

    uint state = reply.value();
    qDebug() << "state"<<state;

    // Convert state to readable values
    switch (state) {
    case 10: return 0;  // Disconnected
    case 20: return 1;  // Connecting
    case 30: return 2;  // Connected (Local Only)
    case 40: return 3;  // Connected (Global)
    default: return -1; // Unknown
    }
}

*/





/*

int DBusHandler::getNetworkState() {
    QDBusInterface nm("org.freedesktop.NetworkManager",
                      "/org/freedesktop/NetworkManager",
                      "org.freedesktop.NetworkManager",
                      QDBusConnection::systemBus());

    if (!nm.isValid()) {
        qDebug() << "Could not connect to NetworkManager!";
        return -1;  // Return a valid failure value
    }

    QDBusReply<uint> reply = nm.call("state");

    if (!reply.isValid()) {
        qDebug() << "Failed to get network state!";
        return -1; // Ensure no invalid looping
    }

    qDebug()<<"output"<<reply.value();
    return reply.value();
}

*/

/*

int DBusHandler::getAvailableMemory()
{

    QFile file("/proc/meminfo");

    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<" crying  getAvailableMemory manager";
        return -1;
    }

    QByteArray line= file.readLine();

    QList<QByteArray> value = line.split(' ');

    return value[1].toInt();

}*/


int DBusHandler::getNetworkState() {

    QDBusInterface nm("org.freedesktop.NetworkManager",
                      "/org/freedesktop/NetworkManager",
                      "org.freedesktop.NetworkManager",
                      QDBusConnection::systemBus());


    /*

    QDBusConnection venkatesh1("venkatesh");

    QDBusConnection venkatesh= QDBusConnection::systemBus();

*/


    if (!nm.isValid()) {
        qDebug() << "ERROR: Could not connect to NetworkManager. Check if DBus is running!";
        return -1;
    }

    QDBusReply<uint> reply = nm.call("state");

    if (!reply.isValid()) {
        qDebug() << "ERROR: Failed to get network state! " << reply.error().message();
        return -1;
    }

    qDebug() << "Network State: " << reply.value();
    return reply.value();
}




/*
int DBusHandler::getAvailableMemory() {
    QFile file("/proc/meminfo");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "ERROR: Could not open /proc/meminfo!";
        return -1;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith("MemAvailable:")) {
            QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            if (values.size() < 2) {
                qDebug() << "ERROR: Invalid MemAvailable format!";
                return -1;
            }
            int availableMemory = values[1].toInt();
            qDebug() << "Available Memory: " << availableMemory << "KB";
            return availableMemory;
        }
    }

    qDebug() << "ERROR: Could not find MemAvailable in /proc/meminfo!";
    return -1;
}

*/


/*
int DBusHandler::getCpuUsage()
{

    QFile file("/proc/stat");

    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<" crying  cpuusage  manager";
        return -1;
    }


    QByteArray line= file.readLine();

    QList<QByteArray> value = line.split(' ');

    if ( value.size() < 5 ) return -1;


    int user=value[1].toInt();
    int nice=  value[2].toInt();
    int system=value[3].toInt();
    int idle=     value[4].toInt();

     int total = user+nice+system+idle;
     return ( total-idle)*100/total;

}

*/


/*

int DBusHandler::getCpuUsage() {
    static int prevIdle = 0, prevTotal = 0; // Store previous values

    QFile file("/proc/stat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return -1;

    QTextStream in(&file);
    QString line = in.readLine();
    file.close();

    QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (values.size() < 5) return -1;

    int user = values[1].toInt();
    int nice = values[2].toInt();
    int system = values[3].toInt();
    int idle = values[4].toInt();

    int total = user + nice + system + idle;
    int totalDiff = total - prevTotal;
    int idleDiff = idle - prevIdle;

    prevTotal = total;
    prevIdle = idle;

    return totalDiff > 0 ? ((totalDiff - idleDiff) * 100 / totalDiff) : 0; // Correct CPU percentage
}

*/


/*

int DBusHandler::getCpuUsage() {
    static long prevTotal = 0, prevIdle = 0;

    QFile file("/proc/stat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open /proc/stat";
        return -1;
    }

    QTextStream in(&file);
    QString line = in.readLine();  // Read first line (cpu stats)
    file.close();

    QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (values.size() < 5) return -1;

    long user = values[1].toLong();
    long nice = values[2].toLong();
    long system = values[3].toLong();
    long idle = values[4].toLong();

    long total = user + nice + system + idle;
    long totalDiff = total - prevTotal;
    long idleDiff = idle - prevIdle;

    prevTotal = total;
    prevIdle = idle;

    if (totalDiff == 0) return 0; // Prevent division by zero

    return (100 * (totalDiff - idleDiff)) / totalDiff; // CPU Usage %
}

*/

int DBusHandler::getCpuUsage() {

    static long prevTotal = 0, prevIdle = 0;

    QFile file("/proc/stat");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open /proc/stat";
        return -1;
    }

    QTextStream in(&file);

    QString line = in.readLine();  // Read first line (cpu stats)
    file.close();

    QStringList values = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    if (values.size() < 5) return -1;

    long user = values[1].toLong();
    long nice = values[2].toLong();
    long system = values[3].toLong();
    long idle = values[4].toLong();
    long total = user + nice + system + idle;

    long totalDiff = total - prevTotal;
    long idleDiff = idle - prevIdle;

    prevTotal = total;
    prevIdle = idle;

    return totalDiff > 0 ? (100 * (totalDiff - idleDiff) / totalDiff) : 0;
}
