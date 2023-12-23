#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton(tr("Test"), this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
