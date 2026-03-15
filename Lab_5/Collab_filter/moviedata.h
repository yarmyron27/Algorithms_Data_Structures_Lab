#ifndef MOVIEDATA_H
#define MOVIEDATA_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Moviedata
{
public:
    map<int, map<int, double>> userRatings;
    map<int, map<int, double>> movieRatings;
    map<int, string> movieTitles;

    bool loadFromFile(const string& filename);
    bool loadTitles(const string& filename);
};

#endif // MOVIEDATA_H
