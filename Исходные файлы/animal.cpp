#include <animal.h>
#include <QTextCodec>

Animals::Animals(QFile &in){
    int i = 0;
    while(!in.atEnd()){
        QString class_, otrad, semestvo, vid, t;
        t = in.readLine();
        t = t.trimmed();
        QStringList temp = t.split(' ');
        for(int i = 0; i < temp.size(); i+=4){
            class_ = temp[0+i];
            otrad = temp[1+i];
            semestvo = temp[2+i];
            vid = temp[3+i];
            animal a{class_,otrad, semestvo, vid};
            data.push_back(a);
        }

    }
    this->setSpace();
}

void Animals::add(animal a){
    data.push_back(a);
    sort();
}

int Animals::size(){return data.size();}

void Animals::save(QFile &file){
    if(data.size()!=0){
    this->set_();
    file.remove();
    file.close();
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextStream out(&file);
    out.setCodec(codec);
    for(int i = 0; i < data.size(); i++){
        QString s;
        if(i!=data.size()-1) s = data[i]._class + " " + data[i].otrad + " " + data[i].semestvo +" " + data[i].vid + " " ;
        else s = data[i]._class + " " + data[i].otrad + " " + data[i].semestvo +" " + data[i].vid;
        out << s;

    }
    file.close();
    }

}

void Animals::sort(){
    if(data.size() > 1){
    for (int i = 0; i < data.size() - 1; i++) {
            for (int j = 0; j < data.size() - i - 1; j++) {
                if (data[j]._class > data[j+1]._class) {
                    animal temp;
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
                else if(data[j]._class == data[j+1]._class){
                    if(data[j].otrad > data[j+1].otrad){
                        animal temp;
                        temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    }
                    else if(data[j].otrad == data[j+1].otrad){
                        if(data[j].semestvo > data[j+1].semestvo){
                            animal temp;
                            temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }
                        else if(data[j].semestvo == data[j+1].semestvo){
                            if(data[j].vid > data[j+1].vid){
                                animal temp;
                                temp = data[j];
                                data[j] = data[j+1];
                                data[j+1] = temp;
                            }
                        }
                    }
                }


            }
        }
    }
}


void Animals::sortVid(){
    if(data.size()>1){
    animal temp;
    for (int i = 0; i < data.size() - 1; i++) {
           for (int j = 0; j < data.size() - i - 1; j++) {
               if (data[j].vid > data[j + 1].vid) {

                   temp = data[j];
                   data[j] = data[j + 1];
                   data[j + 1] = temp;
               }
           }
       }
    }
}

animal& Animals::operator[](int index){
    return data[index];
}

void Animals::erase(int n){
        vector<animal> temp;
        if(data.size() == 1 && n == 0){data = temp;}
        else{
        for(int i = 0; i < data.size(); i++){
            if(i!=n) temp.push_back(data[i]);
        }
        data = temp;
        }
}

int Animals::search(QString v){
    int pos = -1;
    for(int i = 0; i < data.size();i++){
        if(data[i].vid == v){
            pos = i;
            break;
        }
    }
    return pos;
}

void Animals::sortSemestvo(){
    if(data.size() > 1){
    animal temp;
    for (int i = 0; i < data.size() - 1; i++) {
           for (int j = 0; j < data.size() - i - 1; j++) {
               if (data[j].semestvo > data[j + 1].semestvo) {

                   temp = data[j];
                   data[j] = data[j + 1];
                   data[j + 1] = temp;
               }
           }
       }
    }
}
void Animals::setSpace(){
    QString s = " ";
    for(int i = 0; i < data.size(); i++){
       QStringList l = data[i].vid.split('_');
       if(l.size() > 1) data[i].vid = (l[0] + s + l[1]);
       l = data[i].semestvo.split('_');
       if(l.size() > 1)data[i].semestvo = l[0] + s + l[1];
       l = data[i].otrad.split('_');
       if(l.size() > 1)data[i].otrad = l[0] + s + l[1];
       l = data[i]._class.split('_');
       if(l.size() > 1)data[i]._class = l[0] + s + l[1];

    }
}

void Animals::set_(){
    QString s = "_";
    for(int i = 0; i < data.size(); i++){
       QStringList l = data[i].vid.split(' ');
       if(l.size() > 1) data[i].vid = (l[0] + s + l[1]);
       l = data[i].semestvo.split(' ');
       if(l.size() > 1)data[i].semestvo = l[0] + s + l[1];
       l = data[i].otrad.split(' ');
       if(l.size() > 1)data[i].otrad = l[0] + s + l[1];
       l = data[i]._class.split(' ');
       if(l.size() > 1)data[i]._class = l[0] + s + l[1];

    }
}
