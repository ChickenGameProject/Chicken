#ifndef BULLET_GIFT_H
#define BULLET_GIFT_H

#include "gift.h"

class Bullet_gift : public gift{
    Q_OBJECT
public:
    Bullet_gift();
public slots:
    void move();
private:
    QPixmap bulletgift;
};

#endif // BULLET_GIFT_H
