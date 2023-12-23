#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listItemsButton_clicked()
{
    // qDebug() << "count is: " << ui->listWidget->count();
    for(size_t i{}; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem* item_ptr = ui->listWidget->item(i);
        // item_ptr->setToolTip("Tooltop" + QString::number(i));
        QVariant data = item_ptr->data(Qt::DisplayRole);
        qDebug() << data.toString();
    }
}


void Widget::on_AddItemButton_clicked()
{
    ui->listWidget->addItem("Hello World");
}
