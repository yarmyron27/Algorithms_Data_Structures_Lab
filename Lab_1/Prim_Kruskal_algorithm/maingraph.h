#ifndef MAINGRAPH_H
#define MAINGRAPH_H

#include <QVector>
#include <algorithm>
#include <iostream>

struct Edge {
    int startPoint;
    int endPoint;
    int weight;
};

class MainGraph
{
public:
    MainGraph(int vertex);

    void addEdge(int startPoint, int endPoint, int weight);

    QVector<Edge> findMinSpanningTree(int& totalWeight);
private:
    int countVertex;
    QVector<Edge> allEdges;
};

#endif // MAINGRAPH_H
