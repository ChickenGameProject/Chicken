#include "chicken_level_1.h"
#include <QTimer>
#include "bullet.h"
#include "bullet_level_1.h"
#include "game.h"
#include <typeinfo>
#include "bullet_gift.h"
#include "leaf_gift.h"
#include "gift.h"
#include <QDebug>
#include <qmath.h>
#include "ship_level_1.h"

extern Player * ship1;
extern Game * game;
chicken_level_1::chicken_level_1(){

    power = 2;

    //draw a enemy
   setPixmap(QPixmap(":/image/chicken.png"));

   QMediaPlayer * music=new QMediaPlayer();
   music->setMedia(QUrl("qrc:/sound/chickensound.mp3"));
   music->play();

         //connect
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(50);

}

void chicken_level_1::move(){


    //if bullet collides whth enemy
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(ship_level_1)){

                //
                game->decreaseLife();
                scene()->removeItem(this);

                //
                delete this;

         }


    }



    // if the chicken is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }

    int STEP_SIZE = 10; // sorat !!!

    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    // ----------------------------------------------------
    int angle;

    //-----------------------------------------------------
    if (game->level->getlevel()==1){
         setPos(x()+dx, y()+dy);
    }
    // ----------------------------------------------------
    else if(game->level->getlevel()==2){

        STEP_SIZE+=10;
        if (this->y()>= 400 ){
            angle = -90;
            this->setRotation(angle);
        }

        setPos(x()+dx, y()+dy);
    }
    // ----------------------------------------------------
    else if (game->level->getlevel()==3){
        STEP_SIZE = 25;
        setPos(x()+dx, y()+dy);
    }
    // ----------------------------------------------------
    else if(game->level->getlevel()==4){
        STEP_SIZE = 30;
        setPos(x()+dx, y()+dy);
    }
    // ----------------------------------------------------
    else if (game->level->getlevel()==5){
        setPos(x()+dx, y()+dy);
    }
}
