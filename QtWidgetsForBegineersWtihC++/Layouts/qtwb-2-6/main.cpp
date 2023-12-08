#include "dialog.h"

#include <QApplication>

/*
 * Multiple layouts, Nested layouts and spacers
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
