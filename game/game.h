#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QString>
#include "player.h"
#include <QVector>
#include "life.h"
#include "score.h"
#include "level.h"

class Game : public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL);
    virtual ~Game(){}
    QGraphicsScene* scene;

    void displayMenu();
    void mouseMoveEvent(QMouseEvent *event);
    void setPlayer();
    void decreaseLife();
    void increaseLife();
    void GameOver();

public slots:
    void start();
public:
     Player * ship1;
     QVector<Life*> life;
     Score * score;
     Level * level;
};


#endif // GAME_H
