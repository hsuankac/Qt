#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>

class Test : public QThread
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

    // QThread interface
protected:
    void run() override;
private:
    void test();
    QTimer m_timer;
};

#endif // TEST_H
