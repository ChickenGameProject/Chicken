#include "life.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>

void Write(int num){

    QFile mfile("C:/Users/acer/Documents/Ap_Project/game/heart_num");
    if(!mfile.exists()){
        qDebug()<<"file dosent exist";
    }
    if(!mfile.open(QFile::WriteOnly|QFile::Text)){
        qDebug()<<"Cannot open file for writing";
        return;
    }
    QTextStream out(&mfile);
    out<<num;
    mfile.flush();
    mfile.close();
}
int Read(){
    QFile mfile("C:/Users/acer/Documents/Ap_Project/game/heart_num");
    if(!mfile.exists()){
        qDebug()<<"File dosent exist";
    }
    if(!mfile.open(QFile::ReadOnly|QFile::Text)){
        qDebug()<<"Cannot open file for reading";
        return 0;
    }
    QTextStream in(&mfile);
    QString text=in.readAll();
    int num=text.split(" ")[0].toInt();
    num*=10;
    qDebug()<<num;
    mfile.flush();
    mfile.close();
}

int Life::numberOfLife = 5;
Life::Life(QObject *parent){
    setPixmap(QPixmap("E:\\game\\sprites\\life.png"));
}


