#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>

QT_CHARTS_USE_NAMESPACE

class ChartView : public QChartView
{
public:
    ChartView(QChart *chart, QWidget *parent = 0);
};

#endif // CHARTVIEW_H
