
/*
#include "dashboard.h"
#include<QVBoxLayout>
#include <QtCharts/QChart>
#include "monitor.h"

Dashboard::Dashboard(QWidget *parent)
    : QWidget{parent}
{

    QVBoxLayout * layout = new QVBoxLayout(this);

    chart = new QChart();

    cpuSeries = new QLineSeries();
     memorySeries  = new QLineSeries();
     networkSeries = new QLineSeries();

     chart->addSeries(cpuSeries);
     chart->addSeries(memorySeries);
     chart->addSeries(networkSeries);

     QChartView *chartView = new QChartView(chart);
     layout->addWidget(chartView);

     Monitor *mointor = new Monitor(this);

     QObject::connect(mointor,&Monitor::newData,this,&Dashboard::updateChart);

     mointor->startMonitoring();
}


 void Dashboard::updateChart(int cpu, int memory , int network)
{

     static int x=0;

    cpuSeries->append(x,cpu);
     memorySeries->append(x,memory);
    networkSeries->append(x,network);
     x++;

 }
*/


#include "dashboard.h"
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include "monitor.h"
#include<QDebug>


Dashboard::Dashboard(QWidget *parent) : QWidget(parent) {

    QVBoxLayout *layout = new QVBoxLayout(this);

    chart = new QChart();
    chart->setTitle("System Monitor - CPU, Memory & Network Usage");
    chart->legend()->setVisible(true);

    cpuSeries = new QLineSeries();
    memorySeries = new QLineSeries();
    networkSeries = new QLineSeries();

    cpuSeries->setName("CPU Usage (%)");
    memorySeries->setName("Memory Available (MB)");
    networkSeries->setName("Network State");

    chart->addSeries(cpuSeries);
    chart->addSeries(memorySeries);
    chart->addSeries(networkSeries);

    // **Create Axes**
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Time (seconds)");
    axisX->setLabelFormat("%d");
    axisX->setRange(0, 60); // Show last 60 seconds
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Usage");
    axisY->setLabelFormat("%d");
    axisY->setRange(0, 100);  // Adjust range based on your needs
    chart->addAxis(axisY, Qt::AlignLeft);

    cpuSeries->attachAxis(axisX);
    cpuSeries->attachAxis(axisY);
    memorySeries->attachAxis(axisX);
    memorySeries->attachAxis(axisY);
    networkSeries->attachAxis(axisX);
    networkSeries->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    Monitor *monitor = new Monitor(this);
    QObject::connect(monitor, &Monitor::newData, this, &Dashboard::updateChart);
    monitor->startMonitoring();

}



/*
 * void Dashboard::updateChart(int cpu, int memory, int network) {
    static int x = 0;

    // Append data
    cpuSeries->append(x, cpu);
    memorySeries->append(x, memory);
    networkSeries->append(x, network);

    // Move X axis range as data grows
    if (x > 60) {
        cpuSeries->remove(0);
        memorySeries->remove(0);
        networkSeries->remove(0);
    }

    x++;

    // **Ensure the chart updates**
    chart->update();
}

*/


void Dashboard::updateChart(int cpu, int memory, int network) {

    static int x = 0;

    cpuSeries->append(x, cpu);
    memorySeries->append(x, memory);

    qDebug()<<"smiling friday"<<  memory;
    networkSeries->append(x, network);

    if (x > 60) {
        cpuSeries->remove(0);
        memorySeries->remove(0);
        networkSeries->remove(0);
    }

    // ✅ Fix: Set X-axis range dynamically
    QValueAxis *axisX = static_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    if (axisX) {
        axisX->setRange(qMax(0, x - 60), x);
    }

    chart->update();
    x++;
}


/*

void Dashboard::updateChart(int cpu, int memory, int network) {
    static int x = 0;

    cpuSeries->append(x, cpu);
    memorySeries->append(x, memory);
    networkSeries->append(x, network);

    // Remove old data to keep it clean
    if (x > 60) {
        cpuSeries->remove(0);
        memorySeries->remove(0);
        networkSeries->remove(0);
    }

    // **Fix for Qt 5 - Explicitly Set Axis Range**
    QValueAxis *axisX = static_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first());
    if (axisX) {
        axisX->setRange(qMax(0, x - 60), x); // Move X-axis dynamically
    }

    chart->update(); // Refresh chart display
    x++;
}

*/

/*
void Dashboard::updateChart(int cpu, int memory, int network) {
    static int x = 0;

    cpuSeries->append(x, cpu);
    memorySeries->append(x, memory);
    networkSeries->append(x, network);

    if (x > 60) {
        cpuSeries->remove(0);
        memorySeries->remove(0);
        networkSeries->remove(0);
    }

    chart->axisX()->setRange(qMax(0, x - 60), x); // Move X-axis dynamically
    chart->update();

    x++;
}
*/
