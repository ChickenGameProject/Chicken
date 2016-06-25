#ifndef LEAF_GIFT_H
#define LEAF_GIFT_H

#include "gift.h"


class Leaf_Gift : public gift{
    Q_OBJECT
public:
    Leaf_Gift();
public slots:
    void move();
private:
    QPixmap leafGift;
};

#endif // LEAF_GIFT_H
