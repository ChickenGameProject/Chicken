#include "leaf_gift.h"
#include "ship_level_1.h"
#include "game.h"
#include <typeinfo>
#include <QDebug>
#include <QTimer>

extern Game * game;
Leaf_Gift::Leaf_Gift(){
    leafGift = QPixmap("E:\\game\\sprites\\bomb2.png");
    setPixmap(leafGift);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

void Leaf_Gift::move(){

    // get a list of all the items currently colliding with this leaf gift
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an player, destroy gift and increase the score
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(ship_level_1)){
            qDebug()<<"colliding";

            // increase score
            game->score->increase(2);


            // remove them from the scene
            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    setPos(x(),y()+10);
    // if the leaf is out of the screen
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
