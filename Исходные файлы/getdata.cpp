#include "getdata.h"
#include "ui_getdata.h"

static Animals adata;

GetData::GetData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetData)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/cat.png"));
}

GetData::~GetData()
{
    delete ui;
}

void GetData::on_pushButton_2_clicked()
{
    ui->comboBox->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    this->close();
    emit mainwindow();
}

void GetData::recieveData(Animals a){
    ui->comboBox->clear();
    if(a.size() != 0){
      a.sortVid();
      adata = a;
      for(int i = 0; i < adata.size(); i++){
          ui->comboBox->addItem(adata[i].vid);
      }
    }
}





void GetData::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    animal a = adata[adata.search(ui->comboBox->currentText())];
    ui->lineEdit->setText(a._class);
    ui->lineEdit_2->setText(a.otrad);
    ui->lineEdit_3->setText(a.semestvo);
}
