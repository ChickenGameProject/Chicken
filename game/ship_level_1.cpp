#include "ship_level_1.h"
#include <QDebug>
#include "bullet.h"
#include "bullet_level_1.h"
#include "game.h"
#include "chicken.h"
#include "chicken_level_1.h"

extern Game * game;
ship_level_1::ship_level_1(){

    power = 1;

    ship1 = QPixmap("E:\\game\\sprites\\spaceship1_1.png");
    setPixmap(ship1);
}

void ship_level_1::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
        fire();
    }
}

void ship_level_1::fire(){

    if (game->level->getlevel()==1){
        // creat new bullet
        Bullet * bullet3;
        bullet3 = new Bullet_level_1();

        bullet3->setPos(x()+100,y());

        // set angle
        int angle = -90;

        bullet3->setRotation(angle);
        game->scene->addItem(bullet3);
    }
    else if (game->level->getlevel()==2){
        // creat new bullet
        Bullet * bullet1;
        Bullet * bullet2;
        bullet1 = new Bullet_level_1();
        bullet2 = new Bullet_level_1();

        bullet1->setPos(x()+30,y());
        bullet2->setPos(x()+185,y());

        // set angle
        int angle = -90;

        bullet1->setRotation(angle-15);
        game->scene->addItem(bullet1);


        bullet2->setRotation(angle+15);
        game->scene->addItem(bullet2);
    }
    else if (game->level->getlevel() >= 3 ){
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
}

    //mehrnaz chicken level_1
    void ship_level_1::soap()
    {
         Chicken * chicken1;
         Chicken * chicken2;
         Chicken * chicken3;
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

