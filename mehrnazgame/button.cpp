#include "button.h"

Button::Button(QString s){
    buttom = QPixmap(s);
    setPixmap(buttom);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    buttom = QPixmap("");
    setPixmap(buttom);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    buttom = QPixmap("");
    setPixmap(buttom);
}
