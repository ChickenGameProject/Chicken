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


