#include "histogramm.h"
#include "ui_histogramm.h"
#include <animal.h>
static Animals adata;
static QCPBars *fossil;
Histogramm::Histogramm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Histogramm)
{
    ui->setupUi(this);
    fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    fossil->setName("Кол-во отрядов в классе");
    setWindowIcon(QIcon(":/img/cat.png"));

}

Histogramm::~Histogramm()
{
    delete ui;
}

void Histogramm::on_pushButton_clicked()
{

    this->close();
    emit mainwindow();

}

void Histogramm::recieveData(Animals a){
    adata = a;
    adata.sort();
    int max_cnt = 0;
    if(adata.size() != 0){
        QVector<double> ticks;
        QVector<QString> labels;
        QVector<double> fossilData;
        for(int i = 0; i < adata.size(); i++){
            QString s = adata[i]._class;
            labels.push_back(s);
            QVector<QString> o;
            while(adata[i]._class == s){
                bool is = false;
                for(int j = 0; j < o.size(); j++){
                    if(adata[i].otrad == o[j]) is = true;
                }
                if(!is)o.push_back(adata[i].otrad);
                i++;
                if(i == adata.size()) break;
            }
            i--;
            fossilData.push_back(o.size());
            if(o.size() > max_cnt) max_cnt = o.size();

        }
        for(int i = 1; i <= fossilData.size(); i++) ticks.push_back(i);
        QLinearGradient gradient(0, 0, 0, 400);
            gradient.setColorAt(0, QColor(90, 90, 90));
            gradient.setColorAt(0.38, QColor(105, 105, 105));
            gradient.setColorAt(1, QColor(70, 70, 70));
            ui->customPlot->setBackground(QBrush(gradient));

            // create empty bar chart objects:


            fossil->setAntialiased(false);

            fossil->setStackingGap(1);
            // set names and colors:

            fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
            fossil->setBrush(QColor(111, 9, 176));



            QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
            textTicker->addTicks(ticks, labels);
            ui->customPlot->xAxis->setTicker(textTicker);
            ui->customPlot->xAxis->setTickLabelRotation(60);
             ui->customPlot->xAxis->setSubTicks(false);
             ui->customPlot->xAxis->setTickLength(0, 4);
             ui->customPlot->xAxis->setRange(0, 8);
             ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
             ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
             ui->customPlot->xAxis->grid()->setVisible(true);
             ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
             ui->customPlot->xAxis->setTickLabelColor(Qt::white);
             ui->customPlot->xAxis->setLabelColor(Qt::white);

            // prepare y axis:
             ui->customPlot->yAxis->setRange(0, max_cnt+3);
             ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
             ui->customPlot->yAxis->setLabel("Кол-во отрядов в классе");
             ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
             ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
             ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
             ui->customPlot->yAxis->grid()->setSubGridVisible(true);
             ui->customPlot->yAxis->setTickLabelColor(Qt::white);
             ui->customPlot->yAxis->setLabelColor(Qt::white);
             ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
             ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

            // Add data:

            fossil->setData(ticks, fossilData);
             ui->customPlot->legend->setVisible(true);
            ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
             ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
             ui->customPlot->legend->setBorderPen(Qt::NoPen);
            QFont legendFont = font();
            legendFont.setPointSize(10);
             ui->customPlot->legend->setFont(legendFont);
             ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
             ui->customPlot->replot();
    }
}
