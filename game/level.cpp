#include "level.h"
#include <QFont>
#include "game.h"
#include <QDebug>

extern Game * game;
Level::Level(){
    level = 1;

    // draw the text
    setPlainText(QString("Level: ") + QString::number(level));
    setDefaultTextColor(Qt::darkBlue );
    setFont(QFont("times",16));
}

void Level::increase()
{
    level++;
    setPlainText(QString("Score: ") + QString::number(level));
}

int Level::getlevel()
{
    return level;
}
