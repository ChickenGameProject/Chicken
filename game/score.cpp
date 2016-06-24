<<<<<<< HEAD
#include"score.h"
#include<QFont>
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    score=0;
    //drow the text
    setPlainText(QString("score:")+ QString ::number(score));//score:0
            setDefaultTextColor(Qt::red);
    setFont(QFont("timer",16));
}
    void Score::increase()
    {
        score++;
        setPlainText(QString("score:")+ QString ::number(score));//score:0

    }

    int Score::getScore()
    {
        return score;
    }

=======
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
>>>>>>> b5f792f708ec117f5db4839b00ab11d00476a77e
