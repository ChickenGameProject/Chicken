#include "player.h"
#include "bullet_level_1.h"
#include "game.h"
#include <QDebug>
#include "bomb.h"
#include "chicken.h"
#include "chicken_level_1.h"



extern Game * game;
Player::Player(){
    power = 1;
    setPixmap(QPixmap("E:\\game\\sprites\\bomb.png"));
}

void Player::spawn(){
    Bomb * bomb = new Bomb();
    game->scene->addItem(bomb);
}

void Player::spawn2(){
    if (game->level->getlevel()==1){
        int angle = 180;

        chicken1 = new chicken_level_1();
        chicken2 = new chicken_level_1();
        chicken3 = new chicken_level_1();
        chicken1->setRotation(angle);
        chicken2->setRotation(angle);
        chicken3->setRotation(angle);

        chicken1->setPos(game->width()-10,100);
        chicken2->setPos(game->width()-10,150);
        chicken3->setPos(game->width()-10,200);

        scene()->addItem(chicken1);
        scene()->addItem(chicken2);
        scene()->addItem(chicken3);
    }

    else if(game->level->getlevel()==2){
        // set angle
        int angle = 90;

        Chicken * chicken1 = new chicken_level_1();
        Chicken * chicken2 = new chicken_level_1();

        chicken1->setPos(game->width(),120);
        chicken2->setPos(game->width(),220);

        chicken1->setRotation(angle);
        game->scene->addItem(chicken1);
        chicken2->setRotation(angle);
        game->scene->addItem(chicken2);


        if (chicken1->y()>= 500 ){
            angle = - 45;
            chicken1->setRotation(angle);
            chicken2->setRotation(angle);
        }



    }
    else if (game->level->getlevel() == 3){

    }
}


