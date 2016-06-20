#include "cilent.h"

Cilent::Cilent(QWidget *parent) : QWidget(parent){
    m_socket=new QTcpSocket(this);
    //ui->setupUi(this);
    //ui->address->setText(QHostAddress(QHostAddress::LocalHost).toString());
    //ui->port->setValue(52693);

    //ui->text->setFocus();

    //connect(m_socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(m_socket, SIGNAL(connected()), this, SLOT(connectedToServer()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnectByServer()));

}

void Cilent::connectedToServer(){
     //ui->chat->insertPlainText("== Connected to server.\n");
     QAbstractSocket::ConnectedState;
}

void Cilent::disconnectByServer(){
    //ui->chat->insertPlainText("== Disconnected by server.\n");
    QAbstractSocket::UnconnectedState;
}

/*void Cilent::updateGui(QAbstractSocket::SocketState state)
{

}*/

