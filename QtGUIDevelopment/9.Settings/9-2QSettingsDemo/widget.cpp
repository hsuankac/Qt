#include "widget.h"
#include "./ui_widget.h"
#include <QSettings>
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(int i = 0; i < 9; i++)
    {
        m_color_list.append(Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button1_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[0], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[0] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button1->setStyleSheet(css);
    }
}


void Widget::on_button2_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[1], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[1] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button2->setStyleSheet(css);
    }
}


void Widget::on_button3_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[2], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[2] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button3->setStyleSheet(css);
    }
}


void Widget::on_button4_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[3], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[3] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button4->setStyleSheet(css);
    }
}


void Widget::on_button5_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[4], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[4] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button5->setStyleSheet(css);
    }
}


void Widget::on_button6_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[5], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[5] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button6->setStyleSheet(css);
    }
}


void Widget::on_button7_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[6], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[6] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button7->setStyleSheet(css);
    }
}


void Widget::on_button8_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[7], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[7] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button8->setStyleSheet(css);
    }
}


void Widget::on_button9_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[8], this, "Choose Background Color");
    if(color.isValid()){
        // Save the color in the list
        m_color_list[9] = color;
        QString css = QString("background-color : %1").arg(color.name());
        ui->button9->setStyleSheet(css);
    }
}


void Widget::on_saveSettingsButton_clicked()
{
    saveColor("button1", m_color_list[0]);
    saveColor("button2", m_color_list[1]);
    saveColor("button3", m_color_list[2]);
    saveColor("button4", m_color_list[3]);
    saveColor("button5", m_color_list[4]);
    saveColor("button6", m_color_list[5]);
    saveColor("button7", m_color_list[6]);
    saveColor("button8", m_color_list[7]);
    saveColor("button9", m_color_list[8]);
}


void Widget::on_loadSettingsButton_clicked()
{
    setLoadedColor("button1", 0, ui->button1);
    setLoadedColor("button2", 1, ui->button2);
    setLoadedColor("button3", 2, ui->button3);
    setLoadedColor("button4", 3, ui->button4);
    setLoadedColor("button5", 4, ui->button5);
    setLoadedColor("button6", 5, ui->button6);
    setLoadedColor("button7", 6, ui->button7);
    setLoadedColor("button8", 7, ui->button8);
    setLoadedColor("button9", 8, ui->button9);
}

void Widget::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("Blikoon", "SettingsDemo");

    settings.beginGroup("ButtonColor");
    settings.setValue(key + "r", red);
    settings.setValue(key + "g", green);
    settings.setValue(key + "b", blue);
    settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("Blikoon", "SettingsDemo");

    settings.beginGroup("ButtonColor");

    red = settings.value(key + "r", QVariant(0)).toInt();
    green = settings.value(key + "g", QVariant(0)).toInt();
    blue = settings.value(key + "b", QVariant(0)).toInt();
    settings.endGroup();

    return QColor(red, green, blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color = loadColor(key);
    m_color_list[index] = color;
    QString css = QString("background-color : %1").arg(color.name());
    button->setStyleSheet(css);
}








