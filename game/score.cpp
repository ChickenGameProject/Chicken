#include "score.h"
#include <QFont>
#include "game.h"
#include <windows.h>

extern Game * game;
Score::Score(QGraphicsItem *parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::darkBlue );
    setFont(QFont("times",16));

}

void Score::increase(int change){
    score+=change;
    setPlainText(QString("Score: ") + QString::number(score));

    if (score>=game->level->getlevel()*50 ){
        //Sleep(500);
        game->level->increase();// level 2
        game->increaseLife();
    }
    else if (score>=game->level->getlevel()*100){
        //Sleep(500);
        game->level->increase(); // level 3
    }
    else if (score>=game->level->getlevel()*200){
        //Sleep(500);
        game->level->increase(); // level 4
    }
    else if (score>=game->level->getlevel()*400){
        game->level->increase(); // level 5
    }

}

int Score::getScore(){
    return score;
}
