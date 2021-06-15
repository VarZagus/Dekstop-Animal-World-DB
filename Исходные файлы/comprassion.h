#ifndef COMPRASSION_H
#define COMPRASSION_H

#include <QWidget>
#include <animal.h>

namespace Ui {
class Comprassion;
}

class Comprassion : public QWidget
{
    Q_OBJECT

public:
    explicit Comprassion(QWidget *parent = nullptr);
    ~Comprassion();

signals:
    void mainwindow();

private slots:
    void on_pushButton_2_clicked();
    void recieveData(Animals a);

    void on_pushButton_clicked();

private:
    Ui::Comprassion *ui;
};

#endif // COMPRASSION_H
