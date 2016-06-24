#include "ship_level_2.h"
#include"chicken_level_2.h"
ship_level_2::ship_level_2(){

}

void ship_level_2::keyPressEvent(QKeyEvent *event){}

void ship_level_2::fire()
{

}
//mehrnaz for sang
void ship_level_2::soap2()
{
   chicken_level_2 * chicken2=new chicken_level_2();
   scene()->addItem(chicken2);
}//????chera ghabool nmikone?

//void ship_level_2::mouseMoveEvent(QMouseEvent *event){}
