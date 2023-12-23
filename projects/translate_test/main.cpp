#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    // const QStringList uiLanguages = QLocale::system().uiLanguages();
    // for (const QString &locale : uiLanguages) {
    //     const QString baseName = "translate_test_" + QLocale(locale).name();
    //     qDebug() << baseName;
    if (translator.load(":/i18n/translate_test_zh_TW.qm")) {
        a.installTranslator(&translator);
        // break;
    }
    // }
    MainWindow w;
    w.show();
    return a.exec();
}
