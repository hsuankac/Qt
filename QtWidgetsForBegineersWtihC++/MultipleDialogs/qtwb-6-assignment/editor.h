#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include <QString>

namespace Ui {
class Editor;
}

class Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    ~Editor();

    QString username() const;

    QString password() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Editor *ui;
    QString m_username;
    QString m_password;
};

#endif // EDITOR_H
