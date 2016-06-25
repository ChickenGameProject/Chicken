#ifndef BULLET_LEVEL_2_H
#define BULLET_LEVEL_2_H

#include "bullet.h"

class bullet_level_2 : public Bullet{
    Q_OBJECT
public:
    bullet_level_2();
     int getpower(){ return power; }
public slots:
    void move();
private:
    int power;
};

#endif // BULLET_LEVEL_2_H
