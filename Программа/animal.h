#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <vector>
#include <fstream>
#include <QFile>
#include <QTextStream>
using namespace std;
struct animal{
    QString _class;
    QString otrad;
    QString semestvo;
    QString vid;
};

class Animals{
private:
   vector<animal> data;
public:
    Animals(QFile &f);
    Animals(){};
    void sort();
    void add(animal a);
    void erase(int i);
    int search(QString v);
    void save(QFile &f);
    animal& operator[](int index);
    int size();
    void sortVid();
    void sortSemestvo();
    void setSpace();
    void set_();


};



#endif // ANIMAL_H
