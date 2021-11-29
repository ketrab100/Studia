#include <iostream>
#include "Graph.h"
#include "FileReader.h"

int main()
{
    FileReader* fileReader = new FileReader();
    fileReader->Read("tsp17.txt");
    Graph* graph = new Graph(fileReader);
    graph->SimulatedAnnealing();
    cout << graph->ShortestPath;
}
