#ifndef CHICKEN_H
#define CHICKEN_H

#include <QGraphicsPixmapItem>
#include<QObject>

//base class
class Chicken :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     Chicken(QGraphicsItem * parent=0);
    // virtual void move()=0;
    // virtual ~Chicken(){}

signals:

public slots:
     virtual void move()=0;

};

#endif // CHICKEN_H
