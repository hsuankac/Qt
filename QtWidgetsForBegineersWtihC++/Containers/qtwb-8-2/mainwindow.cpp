#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->scrollArea);

    ui->actionOpen->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionZoom_in->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp));
    ui->actionZoom_out->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));

    m_lblImage = new QLabel(this);
    ui->scrollArea->setWidget(m_lblImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    m_path = QFileDialog::getOpenFileName(this, "Open", QString(), "All Files(*.*);;JPG (*.jpg);;PNG (*.png)");
    if(m_path.isEmpty()) return;
    if(!m_img.load(m_path))
    {
        QMessageBox::critical(this, "Error", "Could not load the image!");
        return;
    }

    m_lblImage->setPixmap(m_img);
}


void MainWindow::on_actionZoom_in_triggered()
{
    int w = m_lblImage->width();
    int h = m_lblImage->height();

    w += 10;
    h += 10;

    m_lblImage->resize(w, h);
    m_lblImage->setPixmap(m_img.scaled(w, h));
}


void MainWindow::on_actionZoom_out_triggered()
{
    int w = m_lblImage->width();
    int h = m_lblImage->height();

    w -= 10;
    h -= 10;

    if(w < 10) w = 10;
    if(h < 10) h = 10;

    m_lblImage->resize(w, h);
    m_lblImage->setPixmap(m_img.scaled(w, h));
}

