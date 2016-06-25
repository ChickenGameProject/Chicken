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
        /*
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
        scene()->addItem(chicken3);*/
        int angle = 0;
        chicken1 = new chicken_level_1();
        chicken2 = new chicken_level_1();
        chicken3 = new chicken_level_1();
        chicken1->setRotation(angle);
        chicken2->setRotation(angle);
        chicken3->setRotation(angle);

        chicken1->setPos(0,100);
        chicken2->setPos(0,180);
        chicken3->setPos(0,260);
        scene()->addItem(chicken1);
        scene()->addItem(chicken2);
        scene()->addItem(chicken3);
    }

    else if(game->level->getlevel()==2){
        // set angle
         int angle = 180;

          Chicken * chicken1 = new chicken_level_1();
          Chicken * chicken2 = new chicken_level_1();
          Chicken * chicken3 = new chicken_level_1();
          Chicken * chicken4 = new chicken_level_1();
          chicken1->setPos(0,100);
          chicken2->setPos(70,150);
          chicken3->setPos(0,200);
          chicken4->setPos(70,250);

          chicken1->setRotation(angle);
          game->scene->addItem(chicken1);
          chicken2->setRotation(angle);
          game->scene->addItem(chicken2);





    }
    else if (game->level->getlevel() == 3){

        int angle=180;
        Chicken * chicken4=new chicken_level_1();
        Chicken * chicken5=new chicken_level_1();
        Chicken * chicken6=new chicken_level_1();
        chicken1 = new chicken_level_1();
        chicken2 = new chicken_level_1();
        chicken3 = new chicken_level_1();
        chicken4 = new chicken_level_1();
        chicken5 = new chicken_level_1();
        chicken6 = new chicken_level_1();
        chicken1->setRotation(angle);
        chicken2->setRotation(angle);
        chicken3->setRotation(angle);
        chicken4->setRotation(angle);
        chicken5->setRotation(angle);
        chicken6->setRotation(angle);
        //chicken1->setPos(game->width()-10,100);
        chicken1->setPos(0,100);
        chicken2->setPos(0,150);
        chicken3->setPos(0,200);
        chicken4->setPos(0,250);
        chicken5->setPos(0,300);
        chicken6->setPos(0,350);
        scene()->addItem(chicken1);
        scene()->addItem(chicken2);
        scene()->addItem(chicken3);
        scene()->addItem(chicken4);
        scene()->addItem(chicken5);
        scene()->addItem(chicken6);

    }
}


