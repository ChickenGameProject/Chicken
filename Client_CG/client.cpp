#include "client.h"
#include<QDebug>
#include<QBrush>
#include<QImage>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QGraphicsView>



Client::Client(QWidget *parent) : QWidget(parent){
      m_socket=new QTcpSocket;
      m_socket->connectToHost("0.0.0.0",52693);
      qDebug()<<"connected to"<<m_socket->localAddress()<<"   port:  "<<52693;
      view=new QGraphicsView();



      connect(m_socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
      //connect(m_socket, SIGNAL(connected()), this, SLOT(connectedToServer()));
      connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnectByServer()));

      view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      setFixedSize(1000,800);
      scene = new QGraphicsScene();
      scene->setSceneRect(0,0,1000,800);
      view->setScene(scene);
      displayMenu();



}

void Client::displayMenu()
{
    // set background for Menu
    view->setBackgroundBrush((QImage(":/image/backgroung.png")));
/*
    // creat Button start
    Button *sstart;
    sstart = new Button("E:\\game\\sprites\\start1.jpg");
    sstart->setPos(game->width()/2 -100 ,game->height()/2 - 110);
    connect(sstart,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(sstart);

    // creat Buttom exit
    Button * exit;
    exit = new Button("E:\\game\\sprites\\start1.jpg");
    exit->setPos(width()/2 - 100,(height()/2));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(exit);
    */
}

void Client::mouseMoveEvent(QMouseEvent *event)
{
    /*
    if(ship1){
        ship1->setPos(event->pos());
    }*/
}

void Client::start()
{
    // clean scene
    scene->clear();

    // set background of game
    view->setBackgroundBrush(QBrush(QImage("E:\\game\\sprites\\back.png"))); //change scene to view
/*
    // add player
    //ship_level_1  ship;
    ship1 = new ship_level_1();
    //ship1 =  &ship;


    ship1->setFlag(QGraphicsItem::ItemIsFocusable);
    ship1->setFocus();

    ship1->setPos(width()/2,height()/2);
    scene->addItem(ship1);

    //scene->addItem(&ship);
//    ship.setPos(200,200);


 */
}

void Client::readMessage(){
    if (m_socket->state() != QAbstractSocket::ConnectedState){
        qDebug()<<"There isnt any connection";
        return;
    }
    qDebug()<<"connected to"<<m_socket->localAddress()<<"   port:  "<<12345;
    m_receivedData.append(m_socket->readAll());
    if (!m_receivedData.contains(QChar(23)))
        return;

    QStringList messages = m_receivedData.split(QChar(23));
    m_receivedData = messages.takeLast();
    foreach (const QString &message, messages) {
        //ui->chat->insertPlainText(message + "\n");

    }
}

void Client::disconnectByServer(){
    m_socket->close();
}
/*Qstring message="1"+QChar(23);

    m_socket->write(message.toLocal8Bit());*/

