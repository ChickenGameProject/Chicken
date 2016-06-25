#include "ship_level_1.h"
#include <QDebug>
#include "bullet.h"
#include "bullet_level_1.h"
#include "bullet_level_2.h"
#include "game.h"
#include "chicken.h"
#include "chicken_level_1.h"

extern int Fire;
extern Game * game;
ship_level_1::ship_level_1(){

    power = 1;

    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet1.mp3"));
    bulletsound->play();

    ship1 = QPixmap(":/image/ship.png");
    setPixmap(ship1);
}

void ship_level_1::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
     /*   // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }     */
        fire();
    }
}

void ship_level_1::fire(){

    if (game->level->getlevel()==1){
        // creat new bullet
        Bullet * bullet3;
        //qDebug()<<Fire;
        if (Fire == 1){
            bullet3 = new Bullet_level_1();
        }
        else {
            bullet3 = new bullet_level_2();
        }

         bullet3->setPos(x()+29,y());

        // set angle
        int angle = -90;

        bullet3->setRotation(angle);
        game->scene->addItem(bullet3);
    }
    else if (game->level->getlevel()==2){
        // creat new bullet
        Bullet * bullet1;
        Bullet * bullet2;
        if (Fire == 1){
        bullet1 = new Bullet_level_1();
        bullet2 = new Bullet_level_1();
        }
        else{
            bullet1 = new bullet_level_2();
            bullet2 = new bullet_level_2();
        }
        bullet1->setPos(x()+30,y());
        bullet2->setPos(x()+29,y());

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
        if (Fire == 1){
        bullet1 = new Bullet_level_1();
        bullet2 = new Bullet_level_1();
        bullet3 = new Bullet_level_1();
        }else{
            bullet1 = new bullet_level_2();
            bullet2 = new bullet_level_2();
            bullet3 = new bullet_level_2();
        }

        bullet1->setPos(x()+30,y());
        bullet2->setPos(x()+28,y());
        bullet3->setPos(x()+29,y());

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

