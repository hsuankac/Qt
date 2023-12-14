#ifndef EQUATION_H
#define EQUATION_H

#include <QObject>
#include <QDebug>

class Equation : public QObject
{
    Q_OBJECT
public:
    explicit Equation(QObject *parent = nullptr);

    enum Action{
        NONE,
        RESET,
        ADD,
        SUBSTRACT,
        MULTIPLY,
        DIVIDE
    };

    QString sum() const;
    void setSum(const QString &newSum);

    QString value1() const;
    void setValue1(const QString &newValue1);

    QString value2() const;
    void setValue2(const QString &newValue2);

    Equation::Action action() const;
    void setAction(Equation::Action newAction);

    void calculate();
    QString toString();

signals:

public slots:

private:
    QString m_sum;
    QString m_value1;
    QString m_value2;
    Equation::Action m_action;
    double getValue(QString data);
};

#endif // EQUATION_H
