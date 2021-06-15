#ifndef EDIT_H
#define EDIT_H

#include <QWidget>
#include <animal.h>
namespace Ui {
class Edit;
}

class Edit : public QWidget
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();

signals:
 void mainwindow();
 void sendData(Animals data);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void recieveData(Animals a);

private:
    Ui::Edit *ui;
};

#endif // EDIT_H
