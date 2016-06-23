#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem{
public:
     Score(QObject *parent = 0);
     void increas(int);
     int getscore();
private:
     int score;


};

#endif // SCORE_H
