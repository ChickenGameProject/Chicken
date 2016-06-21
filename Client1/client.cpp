#include "client.h"
#include<QDebug>

Client::Client(QWidget *parent) : QWidget(parent){
      m_socket=new QTcpSocket(this);
      m_socket->connectToHost("127.0.0.1",52693);
      //ui->setupUi(this);
      //ui->address->setText(QHostAddress(QHostAddress::LocalHost).toString());
      //ui->port->setValue(52693);

      //ui->text->setFocus();

      connect(m_socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
      //connect(m_socket, SIGNAL(connected()), this, SLOT(connectedToServer()));
      connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnectByServer()));

}

void Client::readMessage(){
    if (m_socket->state() != QAbstractSocket::ConnectedState){
        qDebug()<<"There isnt any connection";
        return;
    }

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

}

