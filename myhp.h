#ifndef MYHP_H
#define MYHP_H
#include "bomb.h"
#include "mainwindow.h"

class myhp: public QObject, public QGraphicsPixmapItem
{
public:
    myhp();
    int decrease();
     int myhealth;
};

#endif // MYHP_H
