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

    int shortestDistance = 0;
    QString route = graph.findShortPathDijkstra(1, 6, shortestDistance);

    std::cout << "Short way: " << std::endl;
    std::cout << "route: " << route.toStdString() << std::endl;
    std::cout << "weight of the path: " << shortestDistance << std::endl;

    return 0;
}
