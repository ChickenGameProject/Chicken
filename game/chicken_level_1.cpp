#include "chicken_level_1.h"
#include <QTimer>
#include "bullet.h"
#include "bullet_level_1.h"
#include "game.h"
#include <typeinfo>
#include "bullet_gift.h"
#include "leaf_gift.h"
#include "gift.h"
#include <QDebug>

extern Game * game;
chicken_level_1::chicken_level_1(){

    //set random positin
        int random_number=rand()%700;
        //int random_number=rand()%700;
        setPos(random_number,100);
         //draw a enemy
        setPixmap(QPixmap("E:\\game\\sprites\\a.png"));
        setTransformOriginPoint(250,70);
        //setRotation(180);
         //connect
        QTimer *timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(50);

}

void chicken_level_1::move(){


    //if bullet collides whth enemy
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Bullet_level_1)){
            //inctrese score
            game->score->increase(10);


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

        }
    }
     setPos(x()-5,y());
}
