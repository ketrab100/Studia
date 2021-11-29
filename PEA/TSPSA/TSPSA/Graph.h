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
public:
	int VertexNumber;
	Graph(FileReader* fileReader);
	int ShortestPath;
	int* BestPath;
	virtual ~Graph();
	void ShowAdjacencyMatrix();
	void ShowBestPath();
	void BruteForce();
	void SimulatedAnnealing();
	int CalcCost(vector<int> path);
	float ChangeTemperature(float t, int k);
};