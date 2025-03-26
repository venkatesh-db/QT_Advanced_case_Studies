#include "mainwindow.h"

#include <QApplication>
#include<QDebug>
#include"dashboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // MainWindow w;
    // w.show();

    Dashboard w;
    w.show();

    qDebug()<<"we are smiling";
    return a.exec();
}
