#include "player.h"
#include "bullet_level_1.h"
#include "game.h"
#include <QDebug>
#include "bomb.h"
#include "chicken.h"
#include "chicken_level_1.h"

extern Game * game;
Player::Player(){
    setPixmap(QPixmap("E:\\game\\sprites\\bomb.png"));
}

void Player::spawn(){
    qDebug()<<"in fucn spawn";
    Bomb * bomb = new Bomb();
    game->scene->addItem(bomb);
}

void Player::spawn2(){
    if (game->level->getlevel()==1){
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

   // else if(game->level->getlevel()==2){

    //}
    //else if (game->level->getlevel() == 3){

    //}
}


