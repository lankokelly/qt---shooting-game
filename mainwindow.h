#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
//#include <QGraphicsView>
//#include <QTime>
//#include <QLCDNumber>

#include "bullet.h"
#include "bomb.h"

#include <QKeyEvent>
class QLCDNumber;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void scoreChanged(int score);
    void healthbarChange(int enemyhp);
public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

public:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *player;
    QGraphicsPixmapItem *enemy;
    QTimer *timer;
    //QGraphicsRectItem  *RectItem ;
     //myhp* myhealth;
    void setenemyhp(int);
    int  getenemyhp();

public slots:
    void enemymove();
    void handleButton();
    void handleButton2();
    void handleButton3();
//time
private:
   QTime *gametime;
  //int  score;
   //QTimer *gameTimer;
    QTimer *myTimer;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber2;
    //QLCDNumber *gameNumber;
//private slots:
    //void showTime();

};

#endif // MAINWINDOW_H


