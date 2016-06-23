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
private:
    QPixmap bomb;
};

#endif // BOMB_GIFT_H
