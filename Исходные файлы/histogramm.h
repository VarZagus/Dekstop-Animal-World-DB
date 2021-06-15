#ifndef HISTOGRAMM_H
#define HISTOGRAMM_H

#include <QWidget>
#include <animal.h>
#include <qcustomplot.h>

namespace Ui {
class Histogramm;
}

class Histogramm : public QWidget
{
    Q_OBJECT

public:
    explicit Histogramm(QWidget *parent = nullptr);
    ~Histogramm();

signals:
    void mainwindow();

private slots:
    void on_pushButton_clicked();
    void recieveData(Animals a);

private:
    Ui::Histogramm *ui;
};

#endif // HISTOGRAMM_H
