#include "ship_level_2.h"
#include "bullet_level_1.h"

ship_level_2::ship_level_2(){
    ship2 = QPixmap("E:\\game\\sprites\\spaceship1_1.png");
    setPixmap(ship2);
}

void ship_level_2::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
        fire();
    }
}

void ship_level_2::fire(){
    // creat new bullet
    Bullet * bullet1;
    Bullet * bullet2;
    Bullet * bullet3;
    bullet1 = new Bullet_level_1();
    bullet2 = new Bullet_level_1();
    bullet3 = new Bullet_level_1();
    bullet1->setPos(x()+30,y());
    bullet2->setPos(x()+185,y());
    bullet3->setPos(x()+100,y());

    // set angle
    int angle = -90;

    bullet1->setRotation(angle-15);
    game->scene->addItem(bullet1);


    bullet2->setRotation(angle+15);
    game->scene->addItem(bullet2);

    bullet3->setRotation(angle);
    game->scene->addItem(bullet3);
}
