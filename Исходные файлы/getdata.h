#ifndef GETDATA_H
#define GETDATA_H
#include <animal.h>
#include <QWidget>

namespace Ui {
class GetData;
}

class GetData : public QWidget
{
    Q_OBJECT

public:
    explicit GetData(QWidget *parent = nullptr);
    ~GetData();
signals:
    void mainwindow();
private slots:
    void on_pushButton_2_clicked();
    void recieveData(Animals a);

    void on_pushButton_clicked();

private:
    Ui::GetData *ui;
};

#endif // GETDATA_H
