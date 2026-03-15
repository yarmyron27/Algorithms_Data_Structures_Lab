#include <QCoreApplication>
#include "moviedata.h"
#include "itembasedrec.h"
#include "userbasedrec.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Moviedata data;
    if (!data.loadFromFile("ratings.csv")) {
        return -1;
    }

    if (!data.loadTitles("movies.csv")) {
        return -1;
    }

    Itembasedrec itemAlgo(data);
    Userbasedrec userAlgo(data);

    cout << "Enter id user ";
    int userId = 0;
    cin >> userId;

    vector<int> itemRecs = itemAlgo.getTop5RecItem(userId);
    vector<int> userRecs = userAlgo.getTop5RecUser(userId);

    cout << "\n top-5 (film item metod) \n";
    for (int movieId : itemRecs) {
        cout << "film id: " << movieId << " - " << data.movieTitles[movieId] << "\n";
    }

    cout << "\n top-5 (users metod) \n";
    for (int movieId : userRecs) {
        cout << "film id: " << movieId << " - " << data.movieTitles[movieId] << "\n";
    }

    return a.exec();
}
