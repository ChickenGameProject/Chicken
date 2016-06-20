#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QList>


class Server : public QWidget
{
    Q_OBJECT
public:
    explicit Server(QWidget *parent = 0);

private slots:
    void newConnection();
    void removeConnection();

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;

signals:

public slots:
};

#endif // SERVER_H
