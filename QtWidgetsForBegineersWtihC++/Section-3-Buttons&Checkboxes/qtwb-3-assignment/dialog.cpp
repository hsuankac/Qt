#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->btnOne, &QPushButton::clicked, this, &Dialog::buttonClicked);
    connect(ui->btnTwo, &QPushButton::clicked, this, &Dialog::buttonClicked);
    connect(ui->btnThree, &QPushButton::clicked, this, &Dialog::buttonClicked);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    accept();
}

void Dialog::buttonClicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if(!btn) return;
    ui->lblButton->setText(btn->text());
}

