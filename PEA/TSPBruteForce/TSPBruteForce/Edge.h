#pragma once
class Edge
{
public:
    int vertex1;
    int vertex2;
    int weight;
    Edge();
    Edge(int vertex1, int vertex2, int weight);
    bool operator<(Edge &edge)
    {
        return (weight < edge.weight);
    }
};

class Compare
{
public:
    bool operator()(Edge edge1,Edge edge2)
    {
        return (edge1.weight>edge2.weight);
    }
};