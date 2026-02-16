#include <QCoreApplication>
#include "maingraph.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //variant graph
    MainGraph graph(6);
    graph.addEdge(1, 4, 11);
    graph.addEdge(1, 6, 3);
    graph.addEdge(1, 3, 12);

    graph.addEdge(4, 5, 6);
    graph.addEdge(5, 2, 5);
    graph.addEdge(5, 3, 10);

    graph.addEdge(2, 6, 5);
    graph.addEdge(6, 3, 1);

    int totalWeight = 0;
    QVector<Edge> minSpanTree = graph.findMinSpanningTree(totalWeight);

    std::cout << "Minimal tree" << std::endl;
    std::cout << "Edges: " << std::endl;

    foreach (const Edge &edge, minSpanTree) {
        std::cout << "(" << edge.startPoint << " - " << edge.endPoint << ") : weight " << edge.weight << std::endl;
    }

    std::cout << "Total weight tree: " << totalWeight << std::endl;

    return 0;
}
