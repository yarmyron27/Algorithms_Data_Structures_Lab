#ifndef USERBASEDREC_H
#define USERBASEDREC_H

#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "moviedata.h"

using namespace std;

class Userbasedrec
{
public:
    Userbasedrec(const Moviedata& database);

    vector<int> getTop5RecUser(int userId);

private:
    const Moviedata& m_data;

    double calculateSimilari(int user1, int user2);
    double getUserAverage(int userId);
};

#endif // USERBASEDREC_H
