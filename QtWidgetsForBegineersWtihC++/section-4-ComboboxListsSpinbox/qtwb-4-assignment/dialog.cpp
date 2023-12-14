#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->txtDate->setDateTime(QDateTime::currentDateTime());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    QString msg;
    msg += "Employer: " + ui->txtName->text() + "\r\n";
    msg += "Title: " + ui->txtTitle->text() + "\r\n";
    msg += "Hire date: " + ui->txtDate->dateTime().toString(Qt::DateFormat::TextDate) + "\r\n";
    QMessageBox::information(this, "Info", msg);
    accept();
}

