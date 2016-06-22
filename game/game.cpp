#include "game.h"
#include "button.h"
#include "player.h"
#include "ship_level_1.h"
#include "ship_level_2.h"
#include <QDebug>
#include <QGraphicsPixmapItem>

extern Game * game;
Game::Game(QWidget *parent){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,800);


    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,800);
    setScene(scene);

}

void Game::displayMenu(){
    // set background for Menu
    game->setBackgroundBrush(QBrush(QImage("E:\\game\\sprites\\back2.png")));

    // creat Button start
    Button *sstart;
    sstart = new Button("E:\\game\\sprites\\start1.jpg");
    sstart->setPos(game->width()/2 -100 ,game->height()/2 - 110);
    connect(sstart,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(sstart);

    // creat Buttom exit
    Button * exit;
    exit = new Button("E:\\game\\sprites\\start1.jpg");
    exit->setPos(width()/2 - 100,(height()/2));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(exit);

}

void Game::mouseMoveEvent(QMouseEvent *event){
    if(ship1){
        ship1->setPos(event->pos());
    }
}

void Game::start(){

    // clean scene
    scene->clear();

    // set background of game
    game->setBackgroundBrush(QBrush(QImage("E:\\game\\sprites\\back.png")));

    // add player
    //ship_level_1  ship;
    ship1 = new ship_level_1();
    //ship1 =  &ship;


    ship1->setFlag(QGraphicsItem::ItemIsFocusable);
    ship1->setFocus();

    ship1->setPos(width()/2,height()/2);
    scene->addItem(ship1);

    //scene->addItem(&ship);
//    ship.setPos(200,200);



}
