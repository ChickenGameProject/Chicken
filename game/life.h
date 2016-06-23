#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsPixmapItem>

class Life : public QGraphicsPixmapItem
{
public:
   Life(QObject *parent = 0);
   int static numberOfLife;
   void decreas();
};

#endif // LIFE_H
