#include "game.h"
#include "button.h"
#include "player.h"
#include "ship_level_1.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
//#include "score.h"
#include <QTimer>
#include <QPoint>

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
        QPoint a = event->pos();
        if (a.y()<200){
            ship1->setPos(a.x(),200);
        }else{
        ship1->setPos(a);}
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
    //
    ship1->setFlag(QGraphicsItem::ItemIsFocusable);
    ship1->setFocus();
    //
    ship1->setPos(width()/2,height()/2);
    scene->addItem(ship1);

}

void Game::decreaseLife(){
    // remove from scene
    scene->removeItem( life[Life::numberOfLife-1]);
    // delete the pointer
    delete life[Life::numberOfLife-1];
    life.pop_back();
    // decrease the static numberOfLife
    Life::numberOfLife--;
    Life*life_num;
    int num=Life::numberOfLife;
    life_num->Write(num);

}

void Game::start(){

    // clean scene
    scene->clear();

    // set background of game
    game->setBackgroundBrush(QBrush(QImage("E:\\game\\sprites\\backg.jpg")));

    // set player
    setPlayer();

    // add life
    life.resize(Life::numberOfLife);

    for (int i=0;i<Life::numberOfLife;i++){
        life[i] = new Life();
        scene->addItem(life[i]);
        life[i]->setPos(i*20,0);
    }

    // add score
    //score = new Score();
    //scene->addItem(score);
    //score->setPos(width()-250,0);

    // add bomb every 4 second
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),ship1,SLOT(spawn()));
    timer->start(4000);

    // add chicken


}
