#include "ship_level_1.h"
#include <QDebug>
#include "bullet.h"
#include "bullet_level_1.h"
#include "game.h"

extern Game * game;
ship_level_1::ship_level_1(){
    ship1 = QPixmap("E:\\game\\sprites\\spaceship1_1.png");
    setPixmap(ship1);
    qDebug()<<"ctor ship_level_1";
}

void ship_level_1::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
        fire();
    }
}

void ship_level_1::fire(){
    // creat new bullet
    Bullet * bullet1;
    Bullet * bullet2;
    Bullet * bullet3;
    bullet1 = new Bullet_level_1();
    bullet2 = new Bullet_level_1();
    bullet3 = new Bullet_level_1();
    bullet1->setPos(x()+30,y());
    bullet2->setPos(x()+185,y());
    bullet3->setPos(x()+100,y());

    // set angle
    int angle = -90;

    bullet1->setRotation(angle-15);
    game->scene->addItem(bullet1);


    bullet2->setRotation(angle+15);
    game->scene->addItem(bullet2);

    bullet3->setRotation(angle);
    game->scene->addItem(bullet3);
}

//void ship_level_1::mouseMoveEvent(QMouseEvent *event){}



//mehrnaz chicken level_1
void Player::soap()
{
     chicken_level_1* chicken1;
     chicken_level_1 * chicken2;
     chicken_level_1 * chicken3;
     chicken1 = new chicken_level_1();
     chicken2 = new chicken_level_1();
     chicken3 = new chicken_level_1();
     chicken1->setPos(x(),y()-300);
     chicken2->setPos(x(),y()-400);
     chicken3->setPos(x(),y()-500);
     scene()->addItem(chicken1);
     scene()->addItem(chicken2);
     scene()->addItem(chicken3);
}

