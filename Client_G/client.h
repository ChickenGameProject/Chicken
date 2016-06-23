#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include<QTcpSocket>
#include<QString>
#include<QTcpServer>
#include<QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
//#include "player.h"

class Client : /*public QWidget*/ public QGraphicsView
{
    Q_OBJECT
public:
    explicit Client(QWidget *parent = 0);
    QGraphicsScene *scene;
    //QGraphicsView *view;

    void displayMenu();
    void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:
    void start();

private slots:
    //void on_text_returnPressed();
    void readMessage();
    //void connectedToServer();
    void disconnectByServer();

private:
    //Player * ship1;
    QTcpSocket *m_socket;
    QString m_user;
    QString m_receivedData;

    void updateGui(QAbstractSocket::SocketState state);
};

#endif // CLIENT_H
