#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <string>
#include "FileReader.h"

class Graph
{
private:
	int** AdjacencyMatrix;
	int vertexNumber;
public:
	Graph(FileReader* fileReader);
	int iterations;
	vector<int> bestPath;
	virtual ~Graph();
	void showAdjacencyMatrix();
    int TSP();
	void showBestPath();
};