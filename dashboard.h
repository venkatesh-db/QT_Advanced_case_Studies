#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include<QtCharts/QtCharts>
#include<QtCharts/QLineSeries>



class Dashboard : public QWidget
{

    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);

private slots:

    void updateChart(int cpu, int memory , int network);

private:

    QChart *chart;
    QLineSeries *cpuSeries;
    QLineSeries *memorySeries;
    QLineSeries *networkSeries;



};

#endif // DASHBOARD_H
