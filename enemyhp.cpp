#include "enemyhp.h"
//#include "mainwindow.h"
enemyhp::enemyhp(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    hp = 0;
        //setPlainText(QString("Score: ") + QString::number(count_hp));
        setDefaultTextColor(Qt::blue);
        //setFont(QFont("times", 16));
}

void enemyhp::increase()
{
    hp ++;
    //myhp ++;
    //setPlainText(QString("Score: ") + QString::number(count_hp));
}
/*
int enemyhp::gethp()
{
   return count_hp;
}*/
