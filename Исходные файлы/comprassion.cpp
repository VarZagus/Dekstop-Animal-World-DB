#include "comprassion.h"
#include "ui_comprassion.h"
static Animals adata;

Comprassion::Comprassion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Comprassion)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/cat.png"));
}

Comprassion::~Comprassion()
{
    delete ui;
}

void Comprassion::on_pushButton_2_clicked()
{
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    this->close();
    emit mainwindow();
}
void Comprassion::recieveData(Animals a){
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    a.sortSemestvo();
    if(a.size()!=0){
    QString s;
    adata = a;
    for(int i = 0; i < adata.size(); i++){
        if(adata.size() == 1){
            ui->comboBox->addItem(adata[i].semestvo);
            ui->comboBox_2->addItem(adata[i].semestvo);
            break;
        }
        else{
        ui->comboBox->addItem(adata[i].semestvo);
        ui->comboBox_2->addItem(adata[i].semestvo);
        s = adata[i].semestvo;
        int k;
        for(k = i; k < adata.size();k++){
            if(adata[k].semestvo != s) break;
        }
        k--;
        i = k;
        }
    }
    }


}

void Comprassion::on_pushButton_clicked()
{
    if(adata.size()>1){
    ui->textEdit->clear();
    int c1 = 0, c2 = 0;
    QString s1;
    QString s2;
    s1 = ui->comboBox->currentText();
    s2 = ui->comboBox_2->currentText();
    if(s1!=s2){
    for(int i = 0; i < adata.size(); i++){
        if(adata[i].semestvo == s1) c1++;
        if(adata[i].semestvo == s2) c2++;
    }
    if(c1 == c2){
        QString res1 = "В данных семействах одинаковое количество видов\n";
        ui->textEdit->append(res1);
        res1="Список животных первого семейства:";
        ui->textEdit->append(res1);
        for(int i = 0; i < adata.size();i++){
            if(adata[i].semestvo == s1) ui->textEdit->append(adata[i].vid);
        }
        res1="\nСписок животных второго семейства:";
        ui->textEdit->append(res1);
        for(int i = 0; i < adata.size(); i++){
            if(adata[i].semestvo == s2) ui->textEdit->append(adata[i].vid);
        }
    }
    if(c1 > c2){
        QString res1 = "В первом семействе видов больше чем во втором\n";
        ui->textEdit->append(res1);
        res1="Список животных первого семейства:";
        ui->textEdit->append(res1);
        for(int i = 0; i < adata.size();i++){
            if(adata[i].semestvo == s1) ui->textEdit->append(adata[i].vid);
        }
    }

    if(c1 < c2){
        QString res1 = "Во втором семействе видов больше чем в первом\n";
        ui->textEdit->append(res1);
        res1="Список животных второго семейства:";
        ui->textEdit->append(res1);
        for(int i = 0; i < adata.size();i++){
            if(adata[i].semestvo == s2) ui->textEdit->append(adata[i].vid);
        }
    }
    }
    }
}
