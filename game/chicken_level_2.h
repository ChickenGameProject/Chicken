#ifndef CHICKEN_LEVEL_2
#define CHICKEN_LEVEL_2

#include "chicken.h"
#include "chicken_level_2.h"

class chicken_level_2 : public Chicken{
    Q_OBJECT
public:
    chicken_level_2();
public slots:
    void move();
};

#endif // CHICKEN_LEVEL_2

