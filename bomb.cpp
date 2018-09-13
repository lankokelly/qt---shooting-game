#include "bomb.h"
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <typeinfo>
#include <QList>
#include <QFont>
#include<QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QFont>

int hp=4;
void decrease()
{
hp=hp-1;
if(hp==0){ }

}
bomb::bomb(){}
void bomb::bombfly1()
{

    QList<QGraphicsItem *> collide_items = collidingItems();
    int i = 0;
    int n = collide_items.size();
    for ( i=0 ; i<n; ++i )
    {
        //if(collide_items[i]->pos().ry()==0)
        if(typeid(*(collide_items[i]))==typeid(QGraphicsPixmapItem))
        {
            decrease ();
            emit hpChanged(hp);
            scene()->removeItem(this);
            delete this;
            return;
         }
    }

    setPos(x(), y() + 2);
    if(y() > 500) {
        this->scene()->removeItem(this);
        delete this;
    }
}
