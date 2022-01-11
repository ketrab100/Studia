#include "Graph.h"

using namespace std;

Graph::Graph(string fileName)
{
	this->Cost = 0;
	ifstream ifs;
	fileName = fileName;
	ifs.open(fileName);
	if (ifs.is_open())
	{
		ifs >> this->VertexNumber;
		this->AdjacencyMatrix = new int* [VertexNumber];
		for (int i = 0; i < this->VertexNumber; i++)
		{
			AdjacencyMatrix[i] = new int[VertexNumber];
			for (int j = 0; j < this->VertexNumber; j++)
			{
				ifs >> AdjacencyMatrix[i][j];
			}
		}
	}
	ifs.close();
}
Graph::Graph()
{
}
Graph::Graph(int vertexNumber)
{
	this->VertexNumber = VertexNumber;
}

Graph::~Graph()
{
	//for (int i = 0; i < VertexNumber; i++)
	//{
	//	delete[] AdjacencyMatrix[i];
	//}
}

void Graph::FromFile(string fileName)
{
	this->Cost = 0;
	ifstream ifs;
	fileName = fileName;
	ifs.open(fileName);
	if (ifs.is_open())
	{
		ifs >> this->VertexNumber;
		this->AdjacencyMatrix = new int* [VertexNumber];
		for (int i = 0; i < this->VertexNumber; i++)
		{
			AdjacencyMatrix[i] = new int[VertexNumber];
			for (int j = 0; j < this->VertexNumber; j++)
			{
				ifs >> AdjacencyMatrix[i][j];
			}
		}
	}
	ifs.close();
}

void Graph::ShowAdjacencyMatrix()
{
	for (int i = 0; i < VertexNumber; i++)
	{
		for (int j = 0; j < VertexNumber; j++)
		{
			cout << setw(10) << AdjacencyMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::ShowBestPath()
{
	for (int i = 0; i < VertexNumber-1; i++)
	{
		cout << Path[i] << "-";
	}
	cout << Path[VertexNumber-1] << endl;
}

void Graph::Randomize()
{
	for (int i = 0; i < VertexNumber; i++)
	{
		Path.push_back(i);
	}
}

void Graph::CalcCost()
{
	int temp = 0;
	for (int i = 0; i < VertexNumber-2; i++)
	{
		temp += AdjacencyMatrix[Path[i]][Path[i + 1]];
	}
	temp += AdjacencyMatrix[Path[VertexNumber-1]][Path[0]];
	this->Cost = temp;
}

Graph Graph::CrossOver(Graph parent1, Graph parent2)
{
	int random = rand();
	Graph* g = new Graph(parent1.VertexNumber);
	g->AdjacencyMatrix = parent1.AdjacencyMatrix;
	for (int i = 0; i < random; i++)
	{
		g->Path[i] = parent1.Path[i];
	}
	for (int i = random; i < parent1.VertexNumber; i++)
	{
		g->Path[i] = parent2.Path[i];
	}
	return *g;
}

void Graph::Mutate(float mutationRate)
{
	float f = float((rand() % 101) / 100);
	if (f < mutationRate)
	{
		int random1 = rand()%VertexNumber;
		int random2 = rand() % VertexNumber;
		swap(Path[random1], Path[random2]);
	}
}
