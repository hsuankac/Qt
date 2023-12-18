#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{}

void Test::finished()
{
    //When Qt concurrent is done
    qInfo() << this << "Processing...";
}
