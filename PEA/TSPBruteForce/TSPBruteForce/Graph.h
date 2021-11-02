#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <string>
#include <bitset>
#include "FileReader.h"

class Graph
{
private:
	int** AdjacencyMatrix;
	int MinCost(int startVertex, vector<int> vertexes);
public:
	int VertexNumber;
	Graph(FileReader* fileReader);
	int Iterations;
	int ShortestPath;
	int* BestPath;
	virtual ~Graph();
	void ShowAdjacencyMatrix();
	void ShowBestPath();
    void BruteForce();
	void HeldKarp();

};