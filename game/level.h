#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsTextItem>

class Level : public QGraphicsTextItem{
public:
    Level();
    void increase();
    int getlevel();
private:
    int level;
};

#endif // LEVEL_H
