#ifndef RANDGENERATOR_H
#define RANDGENERATOR_H

#include <iostream>
#include <ctime>

class Randgenerator
{
public:
    Randgenerator(long long initialSeed = 0);

    long long getParkMiller();
    long long getLEcuyer();
    unsigned int getLinearCongruential();
    long long getBlumBlumShub();
private:
    long long seedParkMiller;
    long long seedLEcuyer1;
    long long seedLEcuyer2;
    unsigned int seedLinearCongruential;
    long long seedBlumBShub;
    long long m_BlumBShub;
};

#endif // RANDGENERATOR_H
