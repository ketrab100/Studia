#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <string>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <random>
#include "FileReader.h"

class Graph
{
private:
	int** AdjacencyMatrix;
public:
	vector<int> localBest;
	int VertexNumber;
	Graph(FileReader* fileReader);
	int ShortestPath;
	int* BestPath;

	virtual ~Graph();
	void ShowAdjacencyMatrix();
	void ShowBestPath();
	void SimulatedAnnealing();
	int CalcCost(vector<int> path);
	double ChangeTemperature(double a, int era);
};