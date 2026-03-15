#include "itembasedrec.h"

Itembasedrec::Itembasedrec(const Moviedata& database)
    : m_data(database)
{

}

double Itembasedrec::calculateSimilari(int movieId1, int movieId2) {

    const auto& users1 = m_data.movieRatings.at(movieId1);
    const auto& users2 = m_data.movieRatings.at(movieId2);

    double dotProduct = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;

    for (const auto& pair1 : users1) {
        int userId = pair1.first;
        double rating1 = pair1.second;

        norm1 += rating1 * rating1;

        auto count2 = users2.find(userId); // цей користувач дивися і другий фільм
        if (count2 != users2.end()) {
            double rating2 = count2->second;
            dotProduct += rating1 * rating2;
        }
    }

    for (const auto& pair2 : users2) {
        norm2 += pair2.second * pair2.second;
    }

    if (norm1 == 0 || norm2 == 0) return 0.0;

    return dotProduct / (sqrt(norm1) * sqrt(norm2));
}

vector<int> Itembasedrec::getTop5RecItem(int userId) {
    cout << "\n User " << userId << "...\n";

    if (m_data.userRatings.find(userId) == m_data.userRatings.end()) {
        cout << "User not found\n";
        return {};
    }

    const auto& myRatedMovies = m_data.userRatings.at(userId);

    vector<pair<double, int>> predictions;

    for (const auto& moviePair : m_data.movieRatings) {
        int candidateMovieId = moviePair.first;

        if (myRatedMovies.find(candidateMovieId) != myRatedMovies.end()) {
            continue;
        }

        double numerator = 0.0;
        double denominator = 0.0;

        for (const auto& ratedPair : myRatedMovies) {
            int ratedMovieId = ratedPair.first;
            double myRating = ratedPair.second;

            double similarity = calculateSimilari(candidateMovieId, ratedMovieId);

            if (similarity > 0.1) {
                numerator += similarity * myRating;
                denominator += similarity;
            }
        }

        if (denominator > 0) {
            double predictedRating = numerator / denominator;
            predictions.push_back({predictedRating, candidateMovieId});
        }
    }

    sort(predictions.rbegin(), predictions.rend());

    vector<int> top5;
    for (size_t count = 0; count < min<size_t>(5, predictions.size()); ++count) {
        top5.push_back(predictions[count].second);
    }

    return top5;
}
