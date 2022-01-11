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
public:
	int** AdjacencyMatrix;
	int VertexNumber;
	Graph(string fileName);
	Graph();
	Graph(int vertexNumber);
	vector<int> Path;
	int Cost;

	virtual ~Graph();
	void FromFile(string fileName);
	void ShowAdjacencyMatrix();
	void ShowBestPath();
	void CalcCost();
	void Randomize();
	void Mutate(float mutationRate);
	static Graph CrossOver(Graph parent1, Graph parent2);
};