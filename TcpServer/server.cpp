#include "server.h"
#include<QDebug>

Server::Server(QWidget *parent) : QWidget(parent){
    m_server=new QTcpServer(this);

    if (!m_server->listen(QHostAddress::LocalHost, 52693)) {
        qDebug()<<"Connection failed";
        return;
    }
    connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection()));

}

void Server::newConnection(){
    while (m_server->hasPendingConnections()) {
          QTcpSocket *con = m_server->nextPendingConnection();
          m_clients << con;
          connect(con, SIGNAL(disconnected()), this, SLOT(removeConnection()));
}

}

void Server::removeConnection(){
    if (QTcpSocket *con = qobject_cast<QTcpSocket*>(sender())){
        /*ui->log->insertPlainText(QString("* Connection removed: %1, port %2\n")
                                 .arg(con->peerAddress().toString())
                                 .arg(QString::number(con->peerPort())));*/
        m_clients.removeOne(con);
        con->deleteLater();
        //ui->disconnectClients->setEnabled(!m_clients.isEmpty());
        qDebug()<<"Connection removed";
    }


}

