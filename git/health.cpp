#include"Health.h"
#include<QFont>
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){
    health=3;
    //drow the text
    setPlainText(QString("Health:")+ QString ::number(health));//Health=3
            setDefaultTextColor(Qt::blue);
    setFont(QFont("timer",16));

}
    void Health::decrease()
    {
        health--;

        setPlainText(QString("Health:")+ QString ::number(health));//score:2

    }

    int Health::getHealth()
    {
        return health;
    }

