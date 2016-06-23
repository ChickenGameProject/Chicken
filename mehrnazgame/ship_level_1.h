#ifndef SHIP_LEVEL_1_H
#define SHIP_LEVEL_1_H

#include "player.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>


class ship_level_1 : public Player
{
public:
    ship_level_1();
    void keyPressEvent(QKeyEvent * event);
   // void mouseMoveEvent(QMouseEvent *event);
    void fire();
    void soap();

private:
    QPixmap  ship1;
};

#endif // SHIP_LEVEL_1_H
