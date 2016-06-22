#ifndef CHICKEN_LEVEL_1_H
#define CHICKEN_LEVEL_1_H

#include "chicken.h"

class chicken_level_1 : public Chicken{
    Q_OBJECT
public:
    chicken_level_1();
    void move();
};

#endif // CHICKEN_LEVEL_1_H
