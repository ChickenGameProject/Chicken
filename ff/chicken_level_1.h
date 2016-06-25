#ifndef CHICKEN_LEVEL_1_H
#define CHICKEN_LEVEL_1_H

#include "chicken.h"
#include "chicken_level_1.h"

class chicken_level_1 : public Chicken{
    Q_OBJECT
public:
    chicken_level_1();
    int power;
    int getpower(){ return power; }
public slots:
    void move();
};

#endif // CHICKEN_LEVEL_1_H
