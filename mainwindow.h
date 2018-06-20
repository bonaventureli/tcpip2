#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtNetwork>

#include<QtNetwork/QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:

   void init();

   void newTCPConnect();//用于建立服务端与客户之间的连接函数
private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
private slots:

   void revData(); //接收来自服务端的数据

   void displayError(QAbstractSocket::SocketError);
};

#endif // MAINWINDOW_H
