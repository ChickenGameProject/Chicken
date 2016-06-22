#include "client.h"
#include<QDebug>

Client::Client(QWidget *parent) : QWidget(parent){
      m_socket=new QTcpSocket;
      m_socket->connectToHost("0.0.0.0",52693);
      qDebug()<<"connected to"<<m_socket->localAddress()<<"   port:  "<<12345;

      connect(m_socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
      //connect(m_socket, SIGNAL(connected()), this, SLOT(connectedToServer()));
      connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnectByServer()));

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

