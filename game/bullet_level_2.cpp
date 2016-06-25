#include "bullet_level_2.h"
#include <QTimer>
#include "game.h"
#include <qmath.h>
#include "chicken_level_1.h"
#include "chicken_level_2.h"
#include <typeinfo>
#include "player.h"
#include "bullet_gift.h"
#include "leaf_gift.h"

extern Game * game;
extern Player * ship1;
bullet_level_2::bullet_level_2(){
    bullet1 = (QPixmap(":/image/bullet2.png"));
    setPixmap(bullet1);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void bullet_level_2::move(){

    //if bullet collides whth enemy
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(chicken_level_1)){
          // if (this->getpower()>= ship1->getpower()){
                game->score->increase(2);
                int randomNumber=(rand()%5);
                if(randomNumber==1){
                    Bullet_gift * gift1;
                    gift1 =new Bullet_gift();
                    scene()->addItem(gift1);
                    gift1->setPos(this->x(),this->y());

                }
                else if (randomNumber == 3){} // no gift
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

          // }
          /* else {
                // this->getpower()< ship1->getpower()
                this->power-=ship1->getpower();
                ship1->getpower()-= this->power;
                qDebug()<<this->getpower();
                qDebug()<<ship1->getpower();
                // remove bullet
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                } */

            }
    }


    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }

    int STEP_SIZE = 50; // sorat !!!
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
