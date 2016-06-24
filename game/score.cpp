#include "score.h"
#include <QFont>

Score::Score(QObject *parent){
    // initialize the score to 0
    score =0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("times",16));
}

void Score::increas(int num){
    score += num;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getscore(){
    return score;
}
