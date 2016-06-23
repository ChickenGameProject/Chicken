#include "player.h"
#include "bullet_level_1.h"
#include "game.h"
#include <QDebug>
#include "bomb.h"

extern Game * game;
Player::Player(){
    setPixmap(QPixmap("E:\\game\\sprites\\bomb.png"));
}

void Player::spawn(){
    qDebug()<<"in fucn spawn";
    Bomb * bomb = new Bomb();
    game->scene->addItem(bomb);
}

