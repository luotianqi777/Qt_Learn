#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QFont>
#include <QBitmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mouse_pos = QPoint(50,50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    mouse_pos = event->pos();
    // 刷新窗口
    update();
}


void MainWindow::paintEvent(QPaintEvent *event)
{

#if 0
    QPainter p(this);

    QPen pen(QColor(120,243,123));
    pen.setWidth(5);
    pen.setStyle(Qt::DotLine);
    p.setPen(pen);
    p.drawEllipse(200,200,400,400);

    QBrush brush(QPixmap(":/image/dog.jpg"));
    p.setBrush(brush);

    QFont font("微软雅黑",38,75,true);
    p.setFont(font);
    p.drawText(120,130,"test");
#endif
    QPainter p(this);
    QPen pen(QColor(123,35,231));
    p.setPen(pen);

    QBrush brush(QBitmap(":/image/dog.jpg"));
    p.setBrush(brush);
    const int R = 80;
    p.drawEllipse(mouse_pos,R,R);


}
