#ifndef BULLET_LEVEL_1_H
#define BULLET_LEVEL_1_H

#include "bullet.h"

class Bullet_level_1: public Bullet{
    Q_OBJECT
public:
    Bullet_level_1();
    int getpower(){ return power; }
public slots:
    void move();
public:
    int power;
    QPixmap bullet1;
};

#endif // BULLET_LEVEL_1_H
