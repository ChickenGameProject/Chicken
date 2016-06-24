#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsPixmapItem>
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QDebug>
#include<QStringList>

class Life : public QGraphicsPixmapItem
{
public:
   Life(QObject *parent = 0);
   int static numberOfLife;
   int Read();
   void Write(int);
};

#endif // LIFE_H
