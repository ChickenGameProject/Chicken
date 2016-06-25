#include "bullet_level_1.h"
#include <QTimer>
#include "game.h"
#include <qmath.h>

extern Game * game;
Bullet_level_1::Bullet_level_1(){
    setPixmap(QPixmap("E:\\game\\sprites\\bul.png"));

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet_level_1::move(){



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
