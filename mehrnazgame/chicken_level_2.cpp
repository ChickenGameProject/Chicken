#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
#include"Game.h"
#include"chicken_level_2.h"
#include"ship_level_2.h"
#include<QMediaPlayer>
extern Game *game;
chicken_level_2::chicken_level_2()
{

   // set random position
    int random_number=rand()%700;
    //setPos(random_number,100);
   setPos(random_number,0);
    //draw a chicken level2:)
   setPixmap(QPixmap(":/images/E:/monsterSpriteSheet.png"));
   setTransformOriginPoint(200,200);
   setRotation(180);
    //connect
   QTimer *timer=new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));
   timer->start(50);
}

void chicken_level_2::move()
{
    setPos(x()-5,y());
   setPos(x(),y()-5);
       // if(pos().y()>300){
       //     //decrease score
         //   game->health->decrease();
          //  scene()->removeItem(this);
          //  delete this;
      // }
}
