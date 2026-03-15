#ifndef TEST_H
#define TEST_H

#include <QVector>
#include <QDebug>
#include "randgenerator.h"

class Test
{
public:
    Test();
    ~Test();

    void allTest(int totalNumbers = 1000000, int intervalsCount = 6);

private:
    void testUniformity(const QString& generatorName, int generatorType, int TotalNumbers, int intervalsCount);

    Randgenerator* m_generator;
};

#endif // TEST_H
