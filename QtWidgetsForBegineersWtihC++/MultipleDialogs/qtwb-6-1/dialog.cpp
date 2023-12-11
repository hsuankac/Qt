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

void Dialog::on_pushButton_clicked()
{
    // with parent, remember to use pointer, otherwise the dialog will close when we exit the function
    Dialog2* dialog = new Dialog2(this);
    dialog->show();
}


void Dialog::on_pushButton_2_clicked()
{
    // without parent
    Dialog2* dialog = new Dialog2(nullptr);
    dialog->show();
}

