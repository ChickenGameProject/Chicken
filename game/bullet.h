#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QObject *parent = 0);
    QPixmap bullet1;
signals:

public slots:
    virtual void move() =0 ;
};

#endif // BULLET_H
