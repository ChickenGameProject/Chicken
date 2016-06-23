#ifndef BOMB_GIFT_H
#define BOMB_GIFT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bomb :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb();
public slots:
    void move();
};

#endif // BOMB_GIFT_H
