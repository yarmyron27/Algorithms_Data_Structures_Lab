#include "maingraph.h"

MainGraph::MainGraph(int vertex) {
    countVertex = vertex;
}

void MainGraph::addEdge(int startPoint, int endPoint,  int weight) {
    allEdges.append({startPoint, endPoint, weight});
}

QVector<Edge> MainGraph::findMinSpanningTree(int& totalWeight) {
    QVector<Edge> resultTree;
    totalWeight = 0;

    //sort edges
    std::sort(allEdges.begin(), allEdges.end(), [](const Edge &first, const Edge &second) {
        return first.weight < second.weight;
    });

    //array color
    QVector<int> colors(countVertex + 1);
    for (int count = 0; count <= countVertex; ++count) {
        colors[count] = count;
    }

    //algoritm Kruskala
    foreach (const Edge &edge, allEdges) {
        if (colors[edge.startPoint] != colors[edge.endPoint]) {
            resultTree.append(edge);
            totalWeight += edge.weight;

            int firstColor = colors[edge.endPoint];
            int newColor = colors[edge.startPoint];
            for (int count = 1; count <= countVertex; ++count) {
                if (colors[count] == firstColor) {
                    colors[count] = newColor;
                }
            }
        }
    }

    return resultTree;
}
