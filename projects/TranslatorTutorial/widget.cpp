#include "widget.h"
#include "ui_widget.h"
#include <QFontDialog>
#include <QMessageBox>

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

void Widget::on_pushButton_clicked()
{
    //Font button
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        // font is set to the font the user selected
    } else {
        // the user canceled the dialog; font is set to the default
        // application font, QApplication::font()
    }

}


void Widget::on_pushButton_2_clicked()
{
    //Submit button
    QMessageBox::information(NULL, tr("Message"), tr("User %1 submitted a message with the title %2. the message is %3")
                                                      .arg(ui->lineEdit->text())
                                                      .arg(ui->lineEdit_2->text())
                                                      .arg(ui->plainTextEdit->toPlainText()));
}

