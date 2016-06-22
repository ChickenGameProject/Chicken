#include "life.h"

int Life::numberOfLife = 5;
Life::Life(QObject *parent){
    setPixmap(QPixmap("E:\\game\\sprites\\life.png"));
}

