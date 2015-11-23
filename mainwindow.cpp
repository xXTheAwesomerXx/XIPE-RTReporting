#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRect"
#include "QDesktopWidget"
#include "QWidget"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    RestrainWidgetToScreen(this);
}

void MainWindow::RestrainWidgetToScreen(QWidget *w)
{
    QRect screenRect;
    screenRect = QApplication::desktop()->availableGeometry(w);
       if(w->frameGeometry().right() < screenRect.right()) {
           w->move(w->frameGeometry().right() - screenRect.right(), 0);
       } else if(w->frameGeometry().left() > screenRect.left()) {
           w->move(w->frameGeometry().right() - screenRect.right(), 0);
       }
       if(w->frameGeometry().top() < screenRect.top()) {
           w->move(0 + screenRect.right() - w->frameSize().width(), screenRect.top() - w->frameGeometry().top());
       } else if(w->frameGeometry().bottom() < screenRect.bottom()) {
           w->move(0 + screenRect.right() - w->frameSize().width(), screenRect.bottom() - w->frameGeometry().bottom());
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_2_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_toolButton_clicked()
{
    this->close();
}
