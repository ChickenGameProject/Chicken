#include "bullet_gift.h"
#include "ship_level_1.h"
#include <typeinfo>
#include <QDebug>
#include "game.h"
#include <QTimer>
#include "bullet.h"
#include "bullet_level_1.h"
#include "bullet_level_2.h"
#include "player.h"

extern Player * ship1;
extern Game * game;
extern int Fire;
Bullet_gift::Bullet_gift(){

    int randomNumber=(rand()%3);
    if(randomNumber==1){
        Bullet_level_1 * b1 = new Bullet_level_1();
        setPixmap(b1->bullet1);
        state = 1;
    }
    else {
        bullet_level_2 * b2 = new bullet_level_2();
        setPixmap(b2->bullet1);
        state = 0;
    }


    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

void Bullet_gift::move(){

    // get a list of all the items currently colliding with this bullet gift
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an player, destroy gift and level up the bullet
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(ship_level_1)){
            //qDebug()<<"colliding";

            // if bullet is level 1
            if (state == 1){
                qDebug()<<"bullet level 1";
                Fire = 1;
            }

            // if bullet is level 2
            if (state == 0 ){
                qDebug()<<"bullet level 2";
                Fire = 0;
                qDebug()<<Fire;
            }

            // remove them from the scene
            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    setPos(x(),y()+10);
    // if the bomb is out of the screen
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
