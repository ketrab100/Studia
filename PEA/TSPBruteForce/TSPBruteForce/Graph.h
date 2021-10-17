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
public:
	int vertexNumber;
	Graph(FileReader* fileReader);
	int iterations;
	int* bestPath;
	virtual ~Graph();
	void showAdjacencyMatrix();
    int TSP();
	void showBestPath();
};