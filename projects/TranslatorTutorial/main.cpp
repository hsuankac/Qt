#include "widget.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    QTranslator guiTranslator;
    QStringList languages;
    languages << "English" << "Chinese";

    QString lang = QInputDialog::getItem(NULL, "Select language", "Language", languages);

    if(lang == "Chinese")
    {
        t.load(":/files/chinese.qm");
        guiTranslator.load("C:/Qt/6.6.1/mingw_64/translations/qt_zh_CN.qm");
    }

    if(lang != "English")
    {
        a.installTranslator(&t);
        a.installTranslator(&guiTranslator);
    }

    Widget w;
    w.show();
    return a.exec();
}
