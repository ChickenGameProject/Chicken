#include "bullet_gift.h"
#include "ship_level_1.h"
#include <typeinfo>
#include <QDebug>
#include "game.h"
#include <QTimer>

extern Game * game;
Bullet_gift::Bullet_gift(){
    bulletgift = QPixmap("E:\\game\\sprites\\bomb33.png");
    setPixmap(bulletgift);

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
            qDebug()<<"colliding";



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
