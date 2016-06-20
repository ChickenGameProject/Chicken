#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include<QTcpSocket>
#include<Qstring>

class Client : public QWidget
{


    Q_OBJECT
public:
    explicit Client(QWidget *parent = 0);

private slots:
    void connectedToServer();
    void disconnectByServer();


private:
    QTcpSocket *m_socket;
    QString m_user;
    QString m_receivedData;


signals:

public slots:
};

#endif // CLIENT_H
