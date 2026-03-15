#include "randgenerator.h"

Randgenerator::Randgenerator(long long initialSeed) {
    if (initialSeed == 0) {
        initialSeed = time(nullptr);
    }

    seedParkMiller = (initialSeed > 0) ? initialSeed : 1;
    seedLEcuyer1 = seedParkMiller;
    seedLEcuyer2 = seedParkMiller + 1;
    seedLinearCongruential = static_cast<unsigned int>(initialSeed);

    long long p = 30011;
    long long q = 30047;
    m_BlumBShub = p * q;
    seedBlumBShub = initialSeed % m_BlumBShub;
    if (seedBlumBShub == 0 || seedBlumBShub == 1) seedBlumBShub = 2;
}

long long Randgenerator::getParkMiller() {
    long long const_a = 16807;
    long long const_m = 2147483647;

    seedParkMiller = (seedParkMiller * const_a) % const_m;

    return seedParkMiller;
}

long long Randgenerator::getLEcuyer() {
    long long const_m1 = 2147483563, const_a1 = 40014, const_q1 = 53668, const_r1 = 12211;
    long long const_m2 = 2147483399, const_a2 = 40692, const_q2 = 52774, const_r2 = 3791;

    long long rand_1 = const_a1 * (seedLEcuyer1 % const_q1) - const_r1 * (seedLEcuyer1 / const_q1);
    if (rand_1 < 0) rand_1 += const_m1;
    seedLEcuyer1 = rand_1;

    long long rand_2 = const_a2 * (seedLEcuyer2 % const_q2) - const_r2 * (seedLEcuyer2 / const_q2);
    if (rand_2 < 0) rand_2 += const_m2;
    seedLEcuyer2 = rand_2;

    long long result_rand = seedLEcuyer1 - seedLEcuyer2;
    if (result_rand < 1) result_rand += const_m1 - 1;

    return result_rand;
}

unsigned int Randgenerator::getLinearCongruential() {
    unsigned int const_a = 1664525;
    unsigned int const_c = 1013904223;

    seedLinearCongruential = const_a * seedLinearCongruential + const_c;
    return seedLinearCongruential;
}

long long Randgenerator::getBlumBlumShub() {
    seedBlumBShub = (seedBlumBShub * seedBlumBShub) % m_BlumBShub;
    return seedBlumBShub;
}


