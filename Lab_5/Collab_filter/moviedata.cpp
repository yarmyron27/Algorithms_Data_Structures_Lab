#include "moviedata.h"

bool Moviedata::loadFromFile(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "error file not found" << filename << "\n";
        return false;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream strString(line);
        string token;

        try {
            getline(strString, token, ',');
            int userId = stoi(token);

            getline(strString, token, ',');
            int movieId = stoi(token);

            getline(strString, token, ',');
            double rating = stod(token);

            userRatings[userId][movieId] = rating;
            movieRatings[movieId][userId] = rating;
        }
        catch (...) {
            continue;
        }
    }

    file.close();

    return true;
}

bool Moviedata::loadTitles(const string &filename) {
    ifstream file(filename.c_str());

    if (!file.is_open()) {
        cerr << "error file not found " << filename << "\n";
        return false;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream strString(line);
        string token;

        try {
            getline(strString, token, ',');
            int movieId = stoi(token);

            string titleInfo;
            getline(strString, titleInfo);

            movieTitles[movieId] = titleInfo;
        }
        catch (...) {
            continue;
        }
    }

    file.close();
    return true;
}
