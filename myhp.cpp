#include "myhp.h"

myhp::myhp(QGraphicsItem *parent)
{
   myhealth = 5;
}

int myhp::decrease()
{
    myhealth--;
    return myhealth;
}
