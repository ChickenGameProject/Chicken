#ifndef CHICKEN_LEVEL_2_H
#define CHICKEN_LEVEL_2_H
#include<QGraphicsPixmapItem>
#include<QObject>
#include "chicken.h"

class Chicken_level_2 : public Chicken,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Chicken_level_2();
    public slots:
    void move();
};

#endif // CHICKEN_LEVEL_2_H


