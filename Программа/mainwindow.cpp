#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animal.h"
#include <QFile>
#include <histogramm.h>

static Animals adata;
static  QFile file("data.txt");
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/cat.png"));


    if(QFile::exists("data.txt")){

       file.open(QIODevice::ReadOnly);
       Animals temp(file);
       adata = temp;
    }
    edit = new Edit;
    comprassion = new Comprassion;
    getdata = new GetData;
    classlist = new ClassList;
    histogramm = new Histogramm;
    connect(edit, &Edit::mainwindow, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(Animals)), edit, SLOT(recieveData(Animals)));
    connect(edit, SIGNAL(sendData(Animals)), this, SLOT(recieveData(Animals)));

    connect(comprassion, &Comprassion::mainwindow, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(Animals)), comprassion, SLOT(recieveData(Animals)));

    connect(getdata, &GetData::mainwindow, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(Animals)), getdata, SLOT(recieveData(Animals)));

    connect(classlist, &ClassList::mainwindow, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(Animals)), classlist, SLOT(recieveData(Animals)));

    connect(histogramm, &Histogramm::mainwindow, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(Animals)), histogramm, SLOT(recieveData(Animals)));







}


MainWindow::~MainWindow()
{

    adata.save(file);
    delete ui;
}


void MainWindow::recieveData(Animals a){
    adata = a;
}

void MainWindow::on_pushButton_7_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit sendData(adata);
    this->hide();
    edit->setGeometry(this->geometry().x(),this->geometry().y(),edit->geometry().width(), edit->geometry().height());
    edit->show();


}

void MainWindow::on_pushButton_4_clicked()
{
    if(adata.size()>1){
    emit sendData(adata);
    comprassion->setGeometry(this->geometry().x(),this->geometry().y(),comprassion->geometry().width(), comprassion->geometry().height());
    this->hide();
    comprassion->show();
    }
}





void MainWindow::on_pushButton_5_clicked()
{
    if(adata.size()!=0){
    emit sendData(adata);
    getdata->setGeometry(this->geometry().x(),this->geometry().y(),getdata->geometry().width(), getdata->geometry().height());
    this->hide();
    getdata->show();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(adata.size()!=0){
    emit sendData(adata);
    classlist->setGeometry(this->geometry().x(),this->geometry().y(),classlist->geometry().width(), classlist->geometry().height());
    this->hide();
    classlist->show();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(adata.size()!=0){
    emit sendData(adata);
    histogramm->setGeometry(this->geometry().x(),this->geometry().y(),histogramm->geometry().width(), histogramm->geometry().height());
    this->hide();
    histogramm->show();
    }
}
