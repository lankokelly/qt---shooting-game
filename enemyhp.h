#ifndef ENEMYHP_H
#define ENEMYHP_H
#include <QGraphicsTextItem>
#include <QObject>

class enemyhp: public QGraphicsTextItem
{
public:
    enemyhp(QGraphicsItem * parent =0);
    void increase();
    int getScore();
    int hp;
};

#endif // ENEMYHP_H
