#include "game.h"
#include "button.h"
#include "player.h"
#include "ship_level_1.h"
#include "ship_level_2.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include<QTimer>//mehrnaz chicken_level_1

extern Game * game;
Game::Game(QWidget *parent){

    // view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1400,800);

    // scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1400,800);
    setScene(scene);

    ship1 = NULL;

    setMouseTracking(true);
    //mehrnaz chicken_level_1
     QTimer *timer=new QTimer();
     QObject::connect(timer,SIGNAL(timeout()),ship_level_1,SLOT(soap()));
     timer->start(2000);

     //mehrnaz for chicken level 2
     QTimer *timer2=new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),ship_level_2,SLOT(soap2()));
    timer->start(1000);

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

void Game::setPlayer(){
    // if player exits
    if (ship1){
        scene->removeItem(ship1);
        delete ship1 ;
    }

    // player does'nt exist
    ship1 = new ship_level_1();
    ship1->setFlag(QGraphicsItem::ItemIsFocusable);
    ship1->setFocus();
    ship1->setPos(width()/2,height()/2);
    scene->addItem(ship1);


}

void Game::start(){

    // clean scene
    scene->clear();

    // set background of game
    game->setBackgroundBrush(QBrush(QImage("E:\\game\\sprites\\back.png")));

    // set player
    setPlayer();



}
