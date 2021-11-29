#include "Graph.h"
using namespace std;

Graph::Graph(FileReader* fileReader)
{
	this->ShortestPath = INT32_MAX;
	this->VertexNumber = fileReader->VertexNumber;
	this->AdjacencyMatrix = fileReader->AdjacencyMatrix;
	BestPath = new int[VertexNumber + 1];
}

Graph::~Graph()
{
	for (int i = 0; i < VertexNumber; i++)
	{
		delete[] AdjacencyMatrix[i];
	}
	delete[] BestPath;
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
	for (int i = 0; i < VertexNumber - 1; i++)
	{
		cout << BestPath[i] << "-";
	}
	cout << BestPath[VertexNumber - 1] << endl;
}

//rozwi¹zanie prblemu komiwojazera metoda przegladu zupelnego
void Graph::BruteForce()
{
	//wiezcholek startowy/koncowy
	int source = 0;
	//lista wierzcholkow
	vector<int> nodes;

	//dodanie wszystkich wierzcholkow do listy poza wierzcholkiem startowym
	for (int i = 0; i < VertexNumber; i++)
	{
		if (i != source)
		{
			nodes.push_back(i);
		}
	}

	int n = nodes.size();
	int shortest_path = INT_MAX;
	//tablica zaswierajaca optymalna sciezke
	int* path = new int[VertexNumber + 1];
	//generowanie kolnejnych permutacji
	do
	{
		int path_weight = 0;
		int j = source;
		path[0] = j;
		//obliczenie sumy wag krawedzi nowej sciezki
		for (int i = 0; i < n; i++)
		{
			path_weight += AdjacencyMatrix[j][nodes[i]];
			j = nodes[i];
			path[i + 1] = j;
		}
		path_weight += AdjacencyMatrix[j][source];
		path[VertexNumber] = source;
		//jezeli suma wag krawedzi nowej sciezki jest mniejsza niz najlepsza znaleziona do tej pory 
		if (shortest_path > path_weight)
		{
			//najlepsza sciezka = sciezka znaleziona w aktualnej permutacji
			for (int i = 0; i <= VertexNumber; i++)
			{
				BestPath[i] = path[i];
			}
		}

		shortest_path = min(shortest_path, path_weight);
	}
	//dopoki istnieja niespardzone permutacje geneeruje koilejna z nich 
	while (next_permutation(nodes.begin(), nodes.end()));
	delete[] path;
	this->ShortestPath = shortest_path;
}

void Graph::SimulatedAnnealing()
{
	//lista wierzcholkow
	vector<int> nodes;
	//dodanie wszystkich wierzcholkow do listy
	for (int i = 0; i < VertexNumber; i++)
	{
		nodes.push_back(i);
	}
	vector<int> bestPermutation;
	bestPermutation = nodes;

	//next_permutation(nodes.begin(), nodes.end());
	//cout << "nowa = " << CalcCost(nodes) << endl;
	//cout << "stara = " << CalcCost(bestPermutation) << endl;

	int n = 0;
	int l = 20;
	float t0 = 999999999;
	int k = 0;
	float t = t0;
	do 
	{
		bool c = false;
		k++;
		for (int i = 0; i < l; i++)
		{
			next_permutation(nodes.begin(), nodes.end());
			int delta = CalcCost(nodes) - CalcCost(bestPermutation);
			if (delta < 0) {
				bestPermutation = nodes;
				c = true;
			}
			else
			{
				float s = float(rand() % 101) / 100;
				if (s < exp(-delta / t))
				{
					c = true;
					bestPermutation = nodes;
				}
			}
		}
		if (c == true)
		{
			n = 0;
		}
		else
		{
			n++;
		}
		t = ChangeTemperature(t, k);
	} while (n < 2);
	for (int i = 0; i < VertexNumber - 1; i++)
	{
		BestPath[i] = bestPermutation[i];
	}
	BestPath[VertexNumber] = nodes[0];
	ShortestPath = CalcCost(bestPermutation);
}

int Graph::CalcCost(vector<int> path)
{
	int cost = 0;
	for (int i = 0; i < path.size()-1; i++)
	{
		cost += AdjacencyMatrix[path[i]][path[i + 1]];
	}
	cost += AdjacencyMatrix[path[path.size()-1]][path[0]];
	return cost;
}

float Graph::ChangeTemperature(float t, int k)
{
	return pow(0.99999999999, k) * t;
}