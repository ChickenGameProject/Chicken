#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QString>

class Button :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button(QString);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

public slots:

private:
    QPixmap buttom;
};

#endif // BUTTON_H
