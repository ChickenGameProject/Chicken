#ifndef SERVER_H
#define SERVER_H

#include<QObject>
#include<QTcpServer>
#include<QTcpSocket>

class Server:public QObject{
    Q_OBJECT
public:
    Server();

private slots:
    void newConnection();
    void removeConnection();
    void newMessage();

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;
    QHash<QTcpSocket*, QString> m_receivedData;
};

#endif // SERVER_H

