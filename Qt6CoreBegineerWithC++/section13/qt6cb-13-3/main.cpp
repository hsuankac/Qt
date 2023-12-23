#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

bool doDiv(int max)
{
    //Throw
    try
    {
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if(value == 0) throw QString("Can not divide by zero");
        if(value > 5) throw 99;
        if(value == 1) throw std::runtime_error("Should be greater than 1");

        int result = max / value;
        qInfo() << "Result = " << result;
    }
    catch (std::exception const& e)
    {
        qWarning() << "We caught a std : " << e.what();
        return false;
    }
    catch (QString e)
    {
        qWarning() << "We caught a QString" << e;
        return false;
    }
    catch (int e)
    {
        qWarning() << "We caught a QString" << e;
        return false;
    }
    catch (...)
    {
        // catch all is bad
        qWarning() << "We know something is wrong, but we dont know why";
        return false;
    }
    // Finally - here
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int max = 44;
    do
    {
        //Our loop
    }while(doDiv(max));

    return a.exec();
}
