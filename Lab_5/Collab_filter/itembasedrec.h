#ifndef ITEMBASEDREC_H
#define ITEMBASEDREC_H

#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "moviedata.h"

using namespace std;

class Itembasedrec
{
public:
    Itembasedrec(const Moviedata& database);

    vector<int> getTop5RecItem(int userId);

private:
    double calculateSimilari(int movieId1, int movieId2);

    const Moviedata& m_data;
};

#endif // ITEMBASEDREC_H
