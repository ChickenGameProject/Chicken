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
#include <stdlib.h>
#include <windows.h>

extern Game * game;
Bomb::Bomb(){
    // set pixmap
    bomb = (QPixmap("E:\\game\\sprites\\bomb.png"));
    setPixmap(bomb);

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

            //


           // bomb.load("E:\\game\\sprites\\bomb2.png");
          //  bomb = (QPixmap("E:\\game\\sprites\\bomb2.png"));
          //  setPixmap(bomb);

           //   Sleep(500);

            // decreas the life
            game->decreaseLife();

            // remove them from the scene
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

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
