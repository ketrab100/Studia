#include "Graph.h"
using namespace std;

Graph::Graph(FileReader *fileReader)
{
	this->vertexNumber = fileReader->vertexNumber;
	this->AdjacencyMatrix = fileReader->AdjacencyMatrix;
}

Graph::~Graph()
{
	for (int i = 0; i < vertexNumber; i++)
	{
		delete[] AdjacencyMatrix[i];
	}
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
	vector<int> path;
	iterations = 0;
	/// generating permutations and tracking the minimum cost
	do
	{
		iterations++;
		int path_weight = 0;
		//path.clear();
		int j = source;
		//path.push_back(j);
		for (int i = 0; i < n; i++)
		{
			path_weight += AdjacencyMatrix[j][nodes[i]];
			j = nodes[i];
			//path.push_back(j);
		}
		path_weight += AdjacencyMatrix[j][source];
		//path.push_back(source);
		/*
		if (shortest_path>path_weight)
		{
			bestPath = path;
		}
		*/
		shortest_path = min(shortest_path, path_weight);
	}
	while (next_permutation(nodes.begin(), nodes.end()));
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
	for(int i = 0 ;i<bestPath.size()-1;i++)
	{
		cout << bestPath[i] << "-";
	}
	cout << bestPath[bestPath.size()-1];
}