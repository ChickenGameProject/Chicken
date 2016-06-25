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
   setPixmap(QPixmap("E:\\game\\sprites\\a.png"));
    //set random positin
        //int random_number=rand()%1400;
        //int random_number=rand()%700;
        //setPos(random_number,100);

        //setTransformOriginPoint(220,70);
        //setRotation(180);
         //connect
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(50);

}

void chicken_level_1::move(){

/*
    //if bullet collides whth enemy
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Bullet_level_1)){
           if (this->getpower()<= ship1->getpower()){
                //inctrese score
                game->score->increase(10);

                int randomNumber=(rand()%5);
                if(randomNumber==1){
                    Bullet_gift * gift1;
                    gift1 =new Bullet_gift();
                    scene()->addItem(gift1);
                    gift1->setPos(this->x(),this->y());

                }
                else {
                    gift * gift2;
                    gift2 =new Leaf_Gift();
                    scene()->addItem(gift2);
                    gift2->setPos(this->x(),this->y());
                }
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                delete colliding_items[i];
                delete this;

           }
           else {
                // this->getpower()> ship1->getpower()
                this->power-=ship1->getpower();
                qDebug()<<this->getpower();
                qDebug()<<ship1->getpower();
                // remove bullet
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                }

            }
    }
*/


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
