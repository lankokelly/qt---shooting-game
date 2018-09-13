#include "bullet.h"
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <typeinfo>
#include <QList>
#include <QFont>
int count=0;
void increment()
{
    count=count+14;
}
void increment2()
{
    count=count+88;
}

int enemyhp=100;
void minus2()
{
    enemyhp=enemyhp-2;
}

void minus8(){
    enemyhp=enemyhp-8;
}

bullet::bullet(){}

//balls
void bullet::fly()
{
    QList<QGraphicsItem *> collide_items = collidingItems();
    int i = 0;
    int n = collide_items.size();
    for ( i=0 ; i<n; ++i )
    {
        //if(collide_items[i]->pos().ry()==0)
        if(typeid(*(collide_items[i]))==typeid(QGraphicsPixmapItem))
        {
            increment ();
            emit scoreChanged(count);

            minus2();
            emit healthbarChange(enemyhp);

            scene()->removeItem(this);
            delete this;
            return;
        }

    }

    setPos(x(), y() - 2);
    if(y() < 0)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}

//minions
void bullet::fly2()
{
    QList<QGraphicsItem *> collide_items = collidingItems();

    int i = 0;
    int n = collide_items.size();
    for ( i=0 ; i<n; ++i )
    {
        //if(collide_items[i]->pos().ry()==0)
        if(typeid(*(collide_items[i]))==typeid(QGraphicsPixmapItem))
        {
            increment2 ();
            emit scoreChanged(count);

            minus8();
            emit healthbarChange(enemyhp);

            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x()+y()*y()/15000-x()/300, y() - x()*x()/30000);
    if (y() < 0)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}


