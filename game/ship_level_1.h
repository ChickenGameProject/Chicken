#ifndef SHIP_LEVEL_1_H
#define SHIP_LEVEL_1_H

#include "player.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMediaPlayer>

class ship_level_1 : public Player{
    Q_OBJECT
public:
    ship_level_1();
    void keyPressEvent(QKeyEvent * event);
   // void mouseMoveEvent(QMouseEvent *event);
    void fire();
    int& getpower(){ return power; }
       QMediaPlayer * bulletsound;
public slots:

private:
    QPixmap  ship1;
public:
    int power;
};

#endif // SHIP_LEVEL_1_H
