#ifndef BULLET_LEVEL_1_H
#define BULLET_LEVEL_1_H

#include "bullet.h"

class Bullet_level_1: public Bullet{
    Q_OBJECT
public:
    Bullet_level_1();
public slots:
    void move();
};

#endif // BULLET_LEVEL_1_H
