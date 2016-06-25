#ifndef BULLET_GIFT_H
#define BULLET_GIFT_H

#include "gift.h"
#include "bullet.h"
#include "bullet_level_1.h"
#include "bullet_level_2.h"

class Bullet_gift : public gift{
    Q_OBJECT
public:
    Bullet_gift();
public slots:
    void move();
private:
    QPixmap bulletgift;
    int state;

};

#endif // BULLET_GIFT_H
