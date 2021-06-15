#include "edit.h"
#include "ui_edit.h"
#include "animal.h"

static Animals adata;

Edit::Edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/cat.png"));
    }

Edit::~Edit()
{
    emit sendData(adata);
    delete ui;
}



void Edit::on_pushButton_clicked()
{
    this->close();
    emit sendData(adata);
    emit mainwindow();
}

void Edit::recieveData(Animals a){
    adata = a;
    ui->comboBox->clear();
    Animals temp;
    temp = adata;
    temp.sortVid();
    for(int i = 0; i < temp.size(); i++){
        ui->comboBox->addItem(temp[i].vid);
    }
}

void Edit::on_pushButton_3_clicked()
{
    if(adata.size()!=0){
    Animals sorted = adata;
    sorted.sortVid();

    adata.erase(adata.search(sorted[(ui->comboBox->currentIndex())].vid));
    ui->comboBox->clear();
    if(adata.size()!=0){
    Animals temp;
    temp = adata;
    temp.sortVid();
    for(int i = 0; i < temp.size(); i++){
        ui->comboBox->addItem(temp[i].vid);
    }
    }
    }
}

void Edit::on_pushButton_2_clicked()
{
    if(ui->lineClass->text() != "" && ui->lineOtrad->text() != "" && ui->lineSemestvo->text() != "" && ui->lineVid->text() != ""){
        if(adata.search(ui->lineVid->text()) == -1){
            animal a{ui->lineClass->text(),ui->lineOtrad->text(),ui->lineSemestvo->text(),ui->lineVid->text()};
            adata.add(a);
            ui->comboBox->clear();
            Animals temp;
            temp = adata;
            temp.sortVid();
            for(int i = 0; i < temp.size(); i++){
                ui->comboBox->addItem(temp[i].vid);
            }
        }
        ui->lineClass->clear();
        ui->lineOtrad->clear();
        ui->lineSemestvo->clear();
        ui->lineVid->clear();

    }
}
