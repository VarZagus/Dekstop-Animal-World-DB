#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <edit.h>
#include <animal.h>
#include <comprassion.h>
#include <getdata.h>
#include <classlist.h>
#include <histogramm.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
  void sendData(Animals data);


private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_2_clicked();
    void recieveData(Animals a);
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
     Edit *edit;
     Comprassion *comprassion;
     GetData *getdata;
     ClassList *classlist;
     Histogramm *histogramm;
};


#endif // MAINWINDOW_H
