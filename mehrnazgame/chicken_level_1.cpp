#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
#include<QMediaPlayer>
#include"Game.h"
#include"Player.h"
#include "chicken_level_1.h"
extern Game *game;
chicken_level_1::chicken_level_1()
{
    //set random positin
    int random_number=rand()%700;
    //int random_number=rand()%700;
    setPos(random_number,100);
     //draw a enemy
    setPixmap(QPixmap(":/images/E:/monsterSpriteSheet.png"));
    setTransformOriginPoint(220,70);
    setRotation(180);
     //connect
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void chicken_level_1::move()
{
    setPos(x()-5,y());
        if(pos().y()>300){
         //decrease score
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
       }
}
