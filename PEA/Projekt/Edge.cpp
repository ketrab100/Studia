#include "Edge.h"
Edge::Edge(){}
Edge::Edge(int vertex1, int vertex2, int weight)
{
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
    this->weight = weight;
}