#include "bullet_level_1.h"
#include <QTimer>
#include "game.h"
#include <qmath.h>
#include "chicken_level_1.h"

extern Game * game;
Bullet_level_1::Bullet_level_1(){

    power = 1;

    setPixmap(QPixmap("E:\\game\\sprites\\bul.png"));

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet_level_1::move(){

  /*
    //if bullet collides whth enemy
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(chicken_level_1)){
       // while(1){
           if (this->getpower()<= this->getpower()){
            //inctrese score
            game->score->increase(10);
            qDebug()<<this->getpower();
            qDebug()<<ship1->getpower();
            qDebug()<<power;

           int randomNumber=(rand()%5);
           if(randomNumber==1){
               gift * gift2;
               gift2 =new Leaf_Gift();
               scene()->addItem(gift2);
               gift2->setPos(this->x(),this->y());
            }
           else {
               Bullet_gift * gift1;
               gift1 =new Bullet_gift();
               scene()->addItem(gift1);
               game->scene->addItem(gift1);
               gift1->setPos(this->x(),this->y());
            }
           scene()->removeItem(colliding_items[i]);
           scene()->removeItem(this);

           delete colliding_items[i];
           delete this;
           break;
           }
           else {
               //inctrese score
               game->score->increase(10);
               qDebug()<<this->getpower();
               qDebug()<<ship1->getpower();
               qDebug()<<"else";

               // this->getpower()> ship1->getpower()
               this->power-=ship1->getpower();
               qDebug()<<this->getpower();
               qDebug()<<ship1->getpower();

           }

      //  }
        }
    }

*/

    // if there was no collision with an Enemy, move the bullet forward
   // setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }

    int STEP_SIZE = 30; // sorat !!!
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

}
