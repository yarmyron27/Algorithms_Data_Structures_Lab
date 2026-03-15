#include "userbasedrec.h"

Userbasedrec::Userbasedrec(const Moviedata& database)
    : m_data(database)
{

}

double Userbasedrec::getUserAverage(int userId) {
    const auto& myMovies = m_data.userRatings.at(userId);
    if (myMovies.empty()) return 0.0;

    double sum = 0.0;
    for (const auto& pair : myMovies) {
        sum += pair.second;
    }
    return sum / myMovies.size();
}

double Userbasedrec::calculateSimilari(int user1, int user2) {
    const auto& movies1 = m_data.userRatings.at(user1);
    const auto& movies2 = m_data.userRatings.at(user2);

    double dotProduct = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;

    for (const auto& pair1 : movies1) {
        int movieId = pair1.first;
        double rating1 = pair1.second;

        norm1 += rating1 * rating1;

        auto count2 = movies2.find(movieId);
        if (count2 != movies2.end()) {
            double rating2 = count2->second;
            dotProduct += rating1 * rating2;
        }
    }

    for (const auto& pair2 : movies2) {
        norm2 += pair2.second * pair2.second;
    }

    if (norm1 == 0 || norm2 == 0) return 0.0;
    return dotProduct / (sqrt(norm1) * sqrt(norm2));
}

vector<int> Userbasedrec::getTop5RecUser(int userId) {
    if (m_data.userRatings.find(userId) == m_data.userRatings.end()) {
        cout << "User not found\n";
        return {};
    }

    double targetAvg = getUserAverage(userId);
    const auto& myRatedMovies = m_data.userRatings.at(userId);

    map<int, double> numerator;
    map<int, double> denominator;

    for (const auto& userPair : m_data.userRatings) {
        int otherUserId = userPair.first;

        if (otherUserId == userId) continue;

        double similarity = calculateSimilari(userId, otherUserId);

        if (similarity > 0.1) {
            double otherAvg = getUserAverage(otherUserId);

            for (const auto& moviePair : m_data.userRatings.at(otherUserId)) {
                int movieId = moviePair.first;
                double rating = moviePair.second;

                if (myRatedMovies.find(movieId) == myRatedMovies.end()) {
                    numerator[movieId] += similarity * (rating - otherAvg);
                    denominator[movieId] += abs(similarity);
                }
            }
        }
    }

    vector<pair<double, int>> predictions;
    for (const auto& numPair : numerator) {
        int movieId = numPair.first;
        if (denominator[movieId] > 0) {
            double predictedRating = targetAvg + (numPair.second / denominator[movieId]);
            predictions.push_back({predictedRating, movieId});
        }
    }

    sort(predictions.rbegin(), predictions.rend());

    vector<int> top5;
    for (size_t i = 0; i < min<size_t>(5, predictions.size()); ++i) {
        top5.push_back(predictions[i].second);
    }

    return top5;
}
