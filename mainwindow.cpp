#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QBuffer>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    socket = new QTcpSocket(this);
    server->listen(QHostAddress::Any,8080);
    connect(server,&QTcpServer::newConnection,this,[=](){
        if(server->hasPendingConnections()){
            socket = server->nextPendingConnection();
            socket->write("connect success");
            connect(socket,&QTcpSocket::readyRead,this,[=](){
                readImage();
            });
        }

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readImage()
{

    QByteArray str = socket->readAll();
    if(str==tr("__start__")){
        array.clear();
    }else if(str==tr("__end__")){
        qDebug()<<"array.size()"<<array.size();
        ui->label->setPixmap(QPixmap::fromImage(QImage::fromData(QByteArray::fromBase64(array))));
    }else{
        array.push_back(str);
    }
}
