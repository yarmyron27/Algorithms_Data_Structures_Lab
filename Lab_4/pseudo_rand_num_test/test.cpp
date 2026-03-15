#include "test.h"

Test::Test() {
    m_generator = new Randgenerator(0);
}

Test::~Test() {
    delete m_generator;
}

void Test::allTest(int totalNumbers, int intervalsCount) {
    qDebug() << "Start Testing";

    testUniformity("Park-Miller", 1, totalNumbers, intervalsCount);
    testUniformity("L'Ecuyer", 2, totalNumbers, intervalsCount);
    testUniformity("Linear Congruential", 3, totalNumbers, intervalsCount);
    testUniformity("Blum-Blum-Shub", 4, totalNumbers, intervalsCount);
}

void Test::testUniformity(const QString& generatorName, int generatorType, int totalNumbers, int intervalsCount) {
    QVector<int> buckets(intervalsCount, 0);

    for (int number = 0; number < totalNumbers; number++) {
        double randomValue = 0.0;

        switch (generatorType) {
        case 1: // for Park-Miller
            randomValue = static_cast<double>(m_generator->getParkMiller()) / 2147483647.0;
            break;
        case 2: // for L'Ecuyer
            randomValue = static_cast<double>(m_generator->getLEcuyer()) / 2147483563.0;
            break;
        case 3: // for Linear Congruential
            randomValue = static_cast<double>(m_generator->getLinearCongruential()) / 4294967296.0;
            break;
        case 4: // for Blum-Blum-Shub
            randomValue = static_cast<double>(m_generator->getBlumBlumShub()) / 65535.0;
            break;
        }

        int bucketIndex = static_cast<int>(randomValue * intervalsCount);

        if (bucketIndex >= intervalsCount) bucketIndex = intervalsCount - 1;
        if (bucketIndex < 0) bucketIndex = 0;

        buckets[bucketIndex]++;
    }

    double expected = static_cast<double>(totalNumbers) / intervalsCount;
    double chiSquareVal = 0.0;

    for (int count = 0; count < intervalsCount; ++count) {
        double difference = buckets[count] - expected;
        chiSquareVal += (difference * difference) / expected;
    }

    qDebug() << "generator:" << generatorName;
    qDebug() << "Хі * Xi:" << chiSquareVal;
    qDebug() << "V:" << intervalsCount - 1;
}

