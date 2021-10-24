#include "Graph.h"
using namespace std;

//stworzegrafu z pliku 
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

//rozwi¹zanie prblemu komiwojazera metoda przegladu zupelnego
int Graph::TSP()
{
	//wiezcholek startowy/koncowy
	int source = 0;
	//lista wierzcholkow
	vector<int> nodes;

	//dodanie wszystkich wierzcholkow do listy poza wierzcholkiem startowym
	for (int i = 0; i < vertexNumber; i++)
	{
		if (i != source)
		{
			nodes.push_back(i);
		}
	}

	int n = nodes.size();
	int shortest_path = INT_MAX;
	//tablica zaswierajaca optymalna sciezke
	int* path = new int[vertexNumber+1];
	iterations = 0;
	//generowanie kolnejnych permutacji
	do
	{
		iterations++;
		int path_weight = 0;
		int j = source;
		path[0]=j;
		//obliczenie sumy wag krawedzi nowej sciezki
		for (int i = 0; i < n; i++)
		{
			path_weight += AdjacencyMatrix[j][nodes[i]];
			j = nodes[i];
			path[i+1] = j;
		}
		path_weight += AdjacencyMatrix[j][source];
		path[vertexNumber] = source;
		//jezeli suma wag krawedzi nowej sciezki jest mniejsza niz najlepsza znaleziona do tej pory 
		if (shortest_path>path_weight)
		{
			//najlepsza sciezka = sciezka znaleziona w aktualnej permutacji
			bestPath = path;
		}

		shortest_path = min(shortest_path, path_weight);
	}
	//dopoki istnieja niespardzone permutacje geneeruje koilejna z nich 
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
	cout << bestPath[vertexNumber];
}