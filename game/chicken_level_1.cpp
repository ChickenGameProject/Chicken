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

extern Game * game;
chicken_level_1::chicken_level_1(){


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


    //if bullet collides whth enemy
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Bullet_level_1)){
            //inctrese score
            game->score->increase(10);


           int randomNumber=(rand()%5);
           if(randomNumber==1){
               gift * gift2;
               gift2 =new Leaf_Gift();
               scene()->addItem(gift2);
               gift2->setPos(this->x(),this->y());
            }
           else {
               Bullet_gift * gift1;
               gift1 =new Bullet_gift();
               scene()->addItem(gift1);
               game->scene->addItem(gift1);
               gift1->setPos(this->x(),this->y());
            }
           scene()->removeItem(colliding_items[i]);
           scene()->removeItem(this);

           delete colliding_items[i];
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
    else if(game->level->getlevel()==2){

        STEP_SIZE+=10;
        if (this->y()>= 400 ){
            qDebug()<<"bigger ";
            angle = -90;
            this->setRotation(angle);
        }

        setPos(x()+dx, y()+dy);
    }
    else if (game->level->getlevel()==3){
        setPos(x()+dx, y()+dy);
    }
    else if(game->level->getlevel()==4){
        setPos(x()+dx, y()+dy);
    }
    else if (game->level->getlevel()==5){
        setPos(x()+dx, y()+dy);
    }


    // set angle
    //int angle = -90;

    //bullet3->setRotation(angle);
    //game->scene->addItem(bullet3);


    //setPos(x()+dx, y()+dy);
}
