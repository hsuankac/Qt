#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnLogin_clicked()
{
    Editor* editor = new Editor(this);
    editor->exec();

    if(editor->username() == "user" && editor->password() == "password")
    {
        ui->label->setText("Welcome: " + editor->username());
    }
    else
    {
        ui->label->setText("Not logged in");
        QMessageBox::critical(this, "Invalid Login", "Wrong username and password");
    }

    editor->deleteLater();
}

