#include "maingraph.h"

MainGraph::MainGraph(int vertex) {
    countVertex = vertex;
}

void MainGraph::addEdge(int startPoint, int endPoint,  int weight) {
    allEdges.append({startPoint, endPoint, weight});
}

QString MainGraph::findShortPathDijkstra(int startPoint, int endPoint, int &totalWeight) {
    QVector<int> distances(countVertex + 1, 999999);
    QVector<bool> visited(countVertex + 1, false);
    QVector<int> previous(countVertex + 1, 0);

    distances[startPoint] = 0;

    for (int count = 0; count < countVertex; ++count) {

        int minDistance = 999999;
        int mainPoint = -1;

        for (int iterator = 1; iterator <= countVertex; ++iterator) {
            if (!visited[iterator] && distances[iterator] < minDistance) {
                minDistance = distances[iterator];
                mainPoint = iterator;
            }
        }

        if (mainPoint == -1 || distances[mainPoint] == 999999) break;

        visited[mainPoint] = true;

        foreach (const Edge &edge, allEdges) {
            int visit = -1;
            int weight = edge.weight;

            if (edge.startPoint == mainPoint) {
                visit = edge.endPoint;
            } else if (edge.endPoint == mainPoint) {
                visit = edge.startPoint;
            }

            if (visit != -1 && !visited[visit]) {
                if (distances[mainPoint] + weight < distances[visit]) {
                    distances[visit] = distances[mainPoint] + weight;
                    previous[visit] = mainPoint;
                }
            }
        }
    }

    totalWeight = distances[endPoint];

    if (totalWeight == 999999) {
        return "Path not found";
    }

    QString path = "";
    int current = endPoint;
    while (current != 0) {
        path = QString::number(current) + (path.isEmpty() ? "" : " -> ") + path;
        current = previous[current];
    }

    return path;

}
