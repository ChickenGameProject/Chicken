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
    //void newMessage();

    //void on_disconnectClients_clicked();

private:
    //Ui::TcpServer *ui;
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;
    //QHash<QTcpSocket*, QString> m_receivedData;

signals:

public slots:
};

#endif // SERVER_H
