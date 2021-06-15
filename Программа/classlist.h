#ifndef CLASSLIST_H
#define CLASSLIST_H

#include <QWidget>
#include <animal.h>

namespace Ui {
class ClassList;
}

class ClassList : public QWidget
{
    Q_OBJECT

public:
    explicit ClassList(QWidget *parent = nullptr);
    ~ClassList();

signals:
    void mainwindow();

private slots:
    void on_pushButton_2_clicked();
    void recieveData(Animals a);


    void on_pushButton_clicked();

private:
    Ui::ClassList *ui;
};

#endif // CLASSLIST_H
