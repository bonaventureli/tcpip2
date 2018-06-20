#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}
void MainWindow::init()

{

   this->tcpSocket = new QTcpSocket(this);



   newTCPConnect();

       //这里我是采用程序启动就自访问服务端（也可根据实际情况采用手动连接手动输入服务端ip的方式。）

   connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(revData()));

     //readyRead()表示服务端发送数据过来即发动信号，接着revData()进行处理。



   connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),

           this,SLOT(displayError(QAbstractSocket::SocketError)));

}



void MainWindow::revData()

{

   QString datas = tcpSocket->readAll();

//接收字符串数据。

   ui->lineEdit->setText(datas);

     //显示字符串数据。

}



void MainWindow::newTCPConnect()

{

   tcpSocket->abort();

   tcpSocket->connectToHost("127.0.0.1",6666);

      //这里可以根据实际情况在用户界面上进行输入。

}



void MainWindow::displayError(QAbstractSocket::SocketError)

{

   qDebug()<<tcpSocket->errorString();

   tcpSocket->close();

}
MainWindow::~MainWindow()
{
    delete ui;
}
