#include "ship_level_1.h"
#include <QDebug>
#include "bullet.h"
#include "bullet_level_1.h"

//extern Game * game;
ship_level_1::ship_level_1(){
    ship1 = QPixmap("E:\\game\\sprites\\spaceship1_1.png");
    setPixmap(ship1);
    qDebug()<<"ctor ship_level_1";

    //buttom = QPixmap(s);
    //setPixmap(buttom);

    //game->scene->addItem(&ship1);
  //  setPixmap(QPixmap(":/ship1.png"));
}

void ship_level_1::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
       Bullet * bullet;
       Bullet_level_1 bullet1;
       bullet = &bullet1;
       bullet->setPos(x(),y());

    }

}

//void ship_level_1::keyPressEvent(QKeyEvent *event){}
void ship_level_1::mouseMoveEvent(QMouseEvent *event){
    //if(ship1){
        setPos(event->pos());
   // }
}
