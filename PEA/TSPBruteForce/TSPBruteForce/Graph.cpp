#include "Graph.h"
using namespace std;

Graph::Graph(FileReader *fileReader)
{
	this->vertexNumber = fileReader->vertexNumber;
	this->AdjacencyMatrix = fileReader->AdjacencyMatrix;
	bestPath = new int[vertexNumber+1];
}

Graph::~Graph()
{
	for (int i = 0; i < vertexNumber; i++)
	{
		delete[] AdjacencyMatrix[i];
	}
	delete[] bestPath;
}

int Graph::TSP()
{
	/// Picking a source city
	int source = 0;
	vector<int> nodes;

	/// pushing the rest num_nodes-1 cities into a bundle
	for (int i = 0; i < vertexNumber; i++)
	{
		if (i != source)
		{
			nodes.push_back(i);
		}
	}
	int n = nodes.size();
	int shortest_path = INT_MAX;
	int* path = new int[vertexNumber+1];
	iterations = 0;
	/// generating permutations and tracking the minimum cost
	do
	{
		iterations++;
		int path_weight = 0;
		int j = source;
		path[0]=j;
		for (int i = 0; i < n; i++)
		{
			path_weight += AdjacencyMatrix[j][nodes[i]];
			j = nodes[i];
			path[i+1] = j;
		}
		path_weight += AdjacencyMatrix[j][source];
		path[vertexNumber] = source;

		if (shortest_path>path_weight)
		{
			bestPath = path;
		}

		shortest_path = min(shortest_path, path_weight);
	}
	while (next_permutation(nodes.begin(), nodes.end()));
	delete[] path;
	iterations--;
	return shortest_path;
}

void Graph::showAdjacencyMatrix()
{
	for (int i = 0; i < vertexNumber; i++)
	{
		for (int j = 0; j < vertexNumber; j++)
		{
			cout << setw(10) << AdjacencyMatrix[i][j] << " ";
		}
		cout << endl;
	}
}
void Graph::showBestPath()
{
	for(int i = 0 ;i<vertexNumber;i++)
	{
		cout << bestPath[i] << "-";
	}
	cout << bestPath[vertexNumber+1];
}