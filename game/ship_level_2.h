#ifndef SHIP_LEVEL_2_H
#define SHIP_LEVEL_2_H

#include "player.h"

class ship_level_2:public Player{
public:
    ship_level_2();
    void keyPressEvent(QKeyEvent * event);
    void fire();
 private:
    QPixmap ship2;
};

#endif // SHIP_LEVEL_2_H
