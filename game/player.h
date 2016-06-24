#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QObject>

//base class
class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
     Player();
     virtual ~Player(){}
     virtual void keyPressEvent(QKeyEvent * event)=0;
     virtual void fire()=0;
public slots:
     void spawn();
     void spawn2();

};

#endif // PLAYER_H
