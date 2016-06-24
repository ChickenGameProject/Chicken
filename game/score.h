<<<<<<< HEAD
#ifndef SCORE
#define SCORE
#include<QGraphicsTextItem>
class Score:public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent =0);
    void increase();
    int getScore();
private:
    int score;

};

#endif // SCORE

=======
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
>>>>>>> b5f792f708ec117f5db4839b00ab11d00476a77e
