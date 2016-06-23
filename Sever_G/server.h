#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QMediaPlayer>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

private slots:
    void newConnection();
    void removeConnection();
    void newMessage();

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;
    QHash<QTcpSocket*, QString> m_receivedData;

signals:

public slots:
};

#endif // SERVER_H
