#ifndef CHICKEN_H
#define CHICKEN_H

#include <QGraphicsPixmapItem>

//base class
class Chicken :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     Chicken();
     virtual void move()=0;
     virtual ~Chicken(){}
     int power;
     int& getpower(){ return power; }
signals:

public slots:

};

#endif // CHICKEN_H
