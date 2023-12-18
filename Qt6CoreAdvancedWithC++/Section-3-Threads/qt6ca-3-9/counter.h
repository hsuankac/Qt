#ifndef COUNTER_H
#define COUNTER_H

#include <QDebug>
#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QRandomGenerator>

class Counter : public QRunnable
{
public:
    Counter();

    // QRunnable interface
public:
    void run() override;
};

#endif // COUNTER_H
