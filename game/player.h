#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QMouseEvent>

//base class
class Player:public QGraphicsPixmapItem{
public:
     Player();
     //virtual ~Player(){}
     virtual void keyPressEvent(QKeyEvent * event)=0;
     //virtual void mouseMoveEvent(QMouseEvent *event)=0;
};

#endif // PLAYER_H
