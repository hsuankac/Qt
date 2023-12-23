#include "pet.h"

int Pet::age() const
{
    return m_age;
}

void Pet::setAge(int newAge)
{
    m_age = newAge;
}

const QString &Pet::getName() const
{
    return name;
}

void Pet::setName(const QString &newName)
{
    name = newName;
}

Pet::Pet(QObject *parent) : QObject(parent)
{

}
