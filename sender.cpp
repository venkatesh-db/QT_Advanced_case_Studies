#include "sender.h"
#include <QDebug>
Sender::Sender(QObject *parent)
    : QObject{parent}
{}


void Sender::mySlot(int value)
{
    qDebug()<<"hello"<<value;
}
