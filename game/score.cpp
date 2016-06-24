#include "score.h"
#include <QFont>
#include "game.h"

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

    if (game->score->getScore()== 50){
        game->level->increase();
    }
}

int Score::getScore(){
    return score;
}
