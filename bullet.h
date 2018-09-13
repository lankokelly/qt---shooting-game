#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
class QLCDNumber;
class bullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
signals:
    void scoreChanged(int score);
    void healthbarChange(int enemyhpp);
public:
    bullet();
    int score;
    int enemyhpp;
    QLCDNumber *lcdNumber;
     ;

  //void set(QGraphicsPixmapItem *e);
  //QGraphicsPixmapItem * get();
public slots:
    void fly();
    void fly2();
 private:
     QGraphicsPixmapItem *enemy;
     QGraphicsRectItem  *RectItem ;
};

#endif // BULLET_H
