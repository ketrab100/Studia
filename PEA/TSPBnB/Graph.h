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
	int Iterations;
	int ShortestPath;
	int* BestPath;
	virtual ~Graph();
	void ShowAdjacencyMatrix();
	void ShowBestPath();

	void TSP();
	void copyToFinal(vector<int> curr_path, vector<int> final_path);
	int firstMin(int i);
	int secondMin(int i);
	void TSPRec(int curr_bound, int curr_weight, int level, vector<int> curr_path, vector<bool> visited, vector<int>final_path, int& final_res);

};