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

    QPixmap pix(300,300);
    pix.fill(QColor(255,200,200));
    QPainter p(&pix);
    p.setPen(QPen(Qt::green, 10));
    p.drawRect(10,10,280,280);
    p.drawEllipse(100,100,50,50);
    pix.save("D:\\test.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}
