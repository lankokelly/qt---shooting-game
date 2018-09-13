#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
class QLCDNumber;
class bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
signals:
    void hpChanged(int hp2);
public:
    bomb();
    int hp2;
    QLCDNumber *lcdNumber2;
public slots:
    void bombfly1();
private:
    QGraphicsPixmapItem *player;
    QGraphicsRectItem  *RectItem ;
};

#endif // BOMB_H
