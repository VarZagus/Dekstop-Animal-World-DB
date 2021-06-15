#include "classlist.h"
#include "ui_classlist.h"
static Animals adata;
ClassList::ClassList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassList)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/cat.png"));
}

ClassList::~ClassList()
{
    delete ui;
}

void ClassList::on_pushButton_2_clicked()
{
    ui->comboBox->clear();
    ui->textEdit->clear();
    this->close();
    emit mainwindow();
}

void ClassList::recieveData(Animals a){
    adata = a;
    QString s;
    if(adata.size() != 0){
        for(int i = 0; i < adata.size(); i++){
            if(adata.size() == 1){
                ui->comboBox->addItem(adata[i]._class);
                break;
            }
            else{
            ui->comboBox->addItem(adata[i]._class);
            s = adata[i]._class;
            int k;
            for(k = i; k < adata.size();k++){
                if(adata[k]._class != s) break;
            }
            k--;
            i = k;
            }
        }
    }
}
void ClassList::on_pushButton_clicked()
{
    ui->textEdit->clear();
    QString s = ui->comboBox->currentText();
    if(adata.size() != 0){ui->textEdit->append("Список животных данного класса:");}
    for(int i = 0; i < adata.size(); i++){
        if(adata[i]._class == s){
            QString temp;
            temp =adata[i].vid + " - отряд " + adata[i].otrad + ", семейство " + adata[i].semestvo;
            ui->textEdit->append(temp);
        }
    }
}
