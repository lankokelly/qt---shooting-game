#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bullet.h"
#include <QList>
#include <QDebug>
#include <typeinfo>
#include <QPainter>
#include <QtWidgets>
#include <QtGui/QPalette>

class Character{
public:
    virtual void setPos()=0;}
;
class Player: public Character{
    virtual void setPos(int,int);
    int x;
    int y;
};
void Player::setPos(int x,int y){}
class Enemy: public Character{
    virtual void setPos(int,int);
    int x2;
    int y2;
};
void Enemy::setPos(int x2,int y2){}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 968, 665)),
    timer(new QTimer)//view=971,711
{
    ui->setupUi(this);
    //ui_view
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/pic/background.jpg"));
    //add player and enemy
    player = new QGraphicsPixmapItem(QPixmap(":/pic/dog.png").scaled(100, 100));
    enemy  = new QGraphicsPixmapItem(QPixmap(":/pic/wolf.png").scaled(120, 100));
    scene->addItem(player);
    scene->addItem(enemy);
    //set pos of player and enemy
    player->setPos(100, 450);
    enemy->setPos(80, 10);
    //timer
    timer->start(10);
    myTimer = new QTimer(this);
    myTimer->start(1000);
    connect(myTimer,SIGNAL(timeout()),this,SLOT(enemymove()));
    //QGraphicsRectItem
    QGraphicsRectItem  *RectItem = new QGraphicsRectItem();
    QPen pen = RectItem->pen();
    pen.setWidth(3);
    pen.setColor(Qt::black);
    RectItem->setPen(pen);
    RectItem->setBrush(QBrush(QColor(240,240,240)));
    RectItem->setRect(QRectF(710, -1, 257, 597));
    scene->addItem(RectItem);

    //Score text
    QGraphicsSimpleTextItem *scoretext = new QGraphicsSimpleTextItem("SCORE :              ", RectItem);
    QFont f1 = scoretext->font();
    f1.setPointSize(18);
    f1.setBold(1);
    f1.setUnderline(1);
    scoretext->setFont(f1);
    scoretext->setPos(740,20);
    //player hp
    QGraphicsSimpleTextItem *playerhp = new QGraphicsSimpleTextItem("Courage HP : ", RectItem);
    QFont f3 = playerhp->font();
    f3.setPointSize(16);
    f3.setBold(1);
    playerhp->setFont(f3);
    playerhp->setBrush(QColor(0, 0, 128));
    playerhp->setPos(740,60);
    //enemy hp
    QGraphicsSimpleTextItem *enemyhp = new QGraphicsSimpleTextItem("(ﾉ>ω<)ﾉ(ﾉ>ω<)ﾉ(ﾉ>ω<)ﾉ", RectItem);
    QFont f4 = enemyhp->font();
    f4.setPointSize(14);
    //f4.setBold(1);
    enemyhp->setFont(f4);
    enemyhp->setBrush(QColor(0, 0, 0));
    enemyhp->setPos(740,100);

    //special skill text
    QGraphicsSimpleTextItem *skill = new QGraphicsSimpleTextItem("✿ Special Skill ✿", RectItem);
    QFont f2 = skill->font();
    f2.setPointSize(16);
    f2.setBold(1);
    skill->setFont(f2);
    skill->setBrush(QColor(255, 20, 127));
    skill->setPos(740,160);

    //my hp
    //myhp *myhealth = new myhp;
    //QTextBrowser *textBrowser = new QTextBrowser();
    //int myhealth=10;
    //scene->addItem(myhealth);
    //ui->textBrowser->setText(QString::number(myhealth));
    //ui->textBrowser->setGeometry(860,60,35,35);
    //ui->textBrowser->setFrameShape(QFrame::NoFrame);
    //ui->textBrowser->setFont(QFont(tr("Sans Serif"), 16));
    //ui->textBrowser->setStyleSheet("background-color:rgb(240, 240, 240);");
/*
    QGraphicsRectItem  *skilll = new QGraphicsRectItem(RectItem);
    skilll->setBrush(QBrush(QColor(1,0,0)));
    skilll->setRect(QRectF(740, 200, 20, 20));

    QGraphicsPixmapItem * playerr = new QGraphicsPixmapItem((QPixmap(":/pic/frog.png").scaled(30, 10)),RectItem);
    playerr->setPos(770,260);
*/

    ui->pushButton->setGeometry(760,200,30,30);
    ui->pushButton->setFont(QFont("Times",18));
    ui->pushButton->setStyleSheet(" QPushButton{ background-color: rgb(255, 0, 0) }; color: rgb(255, 255, 255) ");
    connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (handleButton()));

    ui->pushButton2->setGeometry(810,200,30,30);
    ui->pushButton2->setFont(QFont("Times",18));
    ui->pushButton2->setStyleSheet(" QPushButton{ background-color:rgb(255, 0, 0) }; color: rgb(255, 255, 255)");
    connect(ui->pushButton2, SIGNAL (clicked()), this, SLOT (handleButton2()));

    ui->pushButton3->setGeometry(860,200,30,30);
    ui->pushButton3->setFont(QFont("Times",18));
    ui->pushButton3->setStyleSheet(" QPushButton{ background-color:rgb(255, 0, 0) }; color: rgb(255, 255, 255)");
    connect(ui->pushButton3, SIGNAL (clicked()), this, SLOT (handleButton3()));

 /* gameTimer = new QTimer(this);
    gameTimer->start(1000);

    gameTimer = new QTimer(this);
    gameLCDNumber = new QLCDNumber(scene);
    gameLCDNumber->setGeometry(30,30,150,30);
    gameLCDNumber->setDigitCount(5);          //mm:ss=5
    gameTimer->start(1000);
    showTime();
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(showTime()));
*/
    //score LCD display
    ui->lcdNumber->setGeometry(838,17,73,30);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->setStyleSheet("border: 1px solid green; color: green; background: silver;");

    ui->lcdNumber2->setGeometry(880,60,30,30);
    ui->lcdNumber2->setSegmentStyle(QLCDNumber::Flat);

    ui->healthBar->setOrientation(Qt::Horizontal);
    ui->healthBar->setRange(0, 100); //goes from 0 to 100
    //ui->healthBar->setValue(30); // With a current value of 100
    ui->healthBar->setGeometry(0,0,710,15);
    QPalette p =  ui->healthBar->palette();
    p.setColor(QPalette::Highlight, QColor(Qt::darkRed));
    ui->healthBar->setPalette(p);

}
void MainWindow::handleButton(){
    bullet *mini = new bullet;
    mini->setPixmap(QPixmap(":/pic/mimi.png").scaled(160, 100));
    mini->setPos(player->x() + player->pixmap().width() / 2 - mini->pixmap().width() / 2, player->y() - mini->pixmap().height());
    mini->connect(timer, SIGNAL(timeout()), mini, SLOT(fly2()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(mini));
    connect(mini, SIGNAL(scoreChanged(int)),ui->lcdNumber, SLOT(display(int)));
    connect(mini, SIGNAL(healthbarChange(int)),ui->healthBar, SLOT(setValue(int)));
    ui->pushButton->setGeometry(0,0,0,0);
}
void MainWindow::handleButton2(){
    bullet *mini = new bullet;
    mini->setPixmap(QPixmap(":/pic/mimi.png").scaled(160, 100));
    mini->setPos(player->x() + player->pixmap().width() / 2 - mini->pixmap().width() / 2, player->y() - mini->pixmap().height());
    mini->connect(timer, SIGNAL(timeout()), mini, SLOT(fly2()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(mini));
    connect(mini, SIGNAL(scoreChanged(int)),ui->lcdNumber, SLOT(display(int)));
    connect(mini, SIGNAL(healthbarChange(int)),ui->healthBar, SLOT(setValue(int)));
    ui->pushButton2->setGeometry(0,0,0,0);
}
void MainWindow::handleButton3(){
    bullet *mini = new bullet;
    mini->setPixmap(QPixmap(":/pic/mimi.png").scaled(160, 100));
    mini->setPos(player->x() + player->pixmap().width() / 2 - mini->pixmap().width() / 2, player->y() - mini->pixmap().height());
    mini->connect(timer, SIGNAL(timeout()), mini, SLOT(fly2()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(mini));
    connect(mini, SIGNAL(scoreChanged(int)),ui->lcdNumber, SLOT(display(int)));
    connect(mini, SIGNAL(healthbarChange(int)),ui->healthBar, SLOT(setValue(int)));
    ui->pushButton3->setGeometry(0,0,0,0);
}

/*void MainWindow::showTime()
{
    //time = new QTime(0,3,0);
    gameLCDNumber->display(time->toString("mm:ss"));
}*/
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        player->setPos(player->x(), player->y() - 10);
        if (player->y() < 350)
            {player->setPos(player->x(), 350);};
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        player->setPos(player->x(), player->y() + 10);
        if (player->y() > 495)
            {player->setPos(player->x(), 495);};
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if (player->x() < 10)
            {player->setPos(10, player->y());};
        player->setPos(player->x() - 10, player->y());
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if (player->x() > 599)
            {player->setPos(599, player->y());};
        player->setPos(player->x() + 10, player->y());
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    bullet *b = new bullet;

    connect(b, SIGNAL(scoreChanged(int)),ui->lcdNumber, SLOT(display(int)));
    connect(b, SIGNAL(healthbarChange(int)),ui->healthBar, SLOT(setValue(int)));

    b->setPixmap(QPixmap(":/pic/orangeball.png").scaled(15, 15));
    b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2, player->y() - b->pixmap().height());
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));

    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
}

void MainWindow::enemymove(){

    bomb *bombb = new bomb;

    connect(bombb, SIGNAL(hpChanged(int)),ui->lcdNumber2, SLOT(display(int)));

    if(ui->lcdNumber2->value()==0){

        QPushButton *closebtn = new QPushButton("Game over hahaha");
        closebtn->setWindowTitle("Shoot shoot  game");
        connect(closebtn, SIGNAL(clicked()), this, SLOT(close()));
        closebtn->show();
        exit(1);

    }

    bombb->setPixmap(QPixmap(":/pic/redfire.png").scaled(20, 20));

    for(int i=0;i<140;i++){

        if(qrand() % 60 == 0){
            int a=qrand()%577+2;
            enemy->setPos(a,10);
            bombb->setPos(enemy->x() + enemy->pixmap().width() / 2 - bombb->pixmap().width() / 2, enemy->y() + bombb->pixmap().height() +100);
            bombb->connect(timer, SIGNAL(timeout()), bombb, SLOT(bombfly1()));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(bombb));

        }
    }
}
