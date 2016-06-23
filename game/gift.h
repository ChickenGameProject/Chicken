#ifndef GIFT_H
#define GIFT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class gift :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit gift(QObject *parent = 0);
signals:

public slots:
    virtual void move()=0;
};

#endif // GIFT_H
