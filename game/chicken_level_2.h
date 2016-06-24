#ifndef CHICKEN_LEVEL_2_H
#define CHICKEN_LEVEL_2_H

#include "chicken_level_2.h"
#include "chicken.h"

class Chicken_level_2 : public Chicken{
    Q_OBJECT
public:
    Chicken_level_2();
public slots:
    void move();
};

#endif // CHICKEN_LEVEL_2_H
