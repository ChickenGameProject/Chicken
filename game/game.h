#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QString>
#include "player.h"

class Game : public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL);
    virtual ~Game(){}
    QGraphicsScene* scene;

    void displayMenu();
    void mouseMoveEvent(QMouseEvent *event);
    void setPlayer();

public slots:
    void start();

private:
     Player * ship1;
};


#endif // GAME_H
