#include "bomb.h"
#include <QTimer>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include <QList>
#include "player.h"
#include "ship_level_1.h"
#include <typeinfo>
#include "game.h"
#include "life.h"

extern Game * game;
Bomb::Bomb(){
    qDebug()<<"ctor bomb";
    // set pixmap
    setPixmap(QPixmap("E:\\game\\sprites\\bomb.png"));

    // set the random position
    int random_number = rand() % 1500;
    setPos(random_number,0);

    // connect signal timer to move
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start
    timer->start(100);

}

void Bomb::move(){

    // get a list of all the items currently colliding with this Bomb
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an player, destroy Bomb and increase life
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(ship_level_1)){
            qDebug()<<"colliding";
            // decreas the life
           // Life::decreas();

            // remove them from the scene (still on the heap)
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
          //  delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    setPos(x(),y()+25);
    // if the bomb is out of the screen
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
