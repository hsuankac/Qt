#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Editor)
{
    ui->setupUi(this);

    ui->txtPassword->setEchoMode(QLineEdit::EchoMode::Password);
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_buttonBox_accepted()
{
    m_username = ui->txtUsername->text();
    m_password = ui->txtPassword->text();
    accept();
}


void Editor::on_buttonBox_rejected()
{
    reject();
}

QString Editor::password() const
{
    return m_password;
}

QString Editor::username() const
{
    return m_username;
}

