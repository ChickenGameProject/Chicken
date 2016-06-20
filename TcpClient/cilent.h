#ifndef CILENT_H
#define CILENT_H

#include <QWidget>
#include<QTcpSocket>
#include<QString>
#include<QAbstractSocket>

class Cilent : public QWidget
{
    Q_OBJECT
public:
    explicit Cilent(QWidget *parent = 0);

private slots:
    //void on_text_returnPressed();
    //void readMessage();
    //void on_connect_clicked();
    void connectedToServer();
    //void on_disconnect_clicked();
    void disconnectByServer();


private:
    //Ui::TcpClient *ui;
    QTcpSocket *m_socket;
    QString m_user;
    //QString m_receivedData;

    //void updateGui(QAbstractSocket::SocketState state);

signals:

public slots:
};

#endif // CILENT_H
