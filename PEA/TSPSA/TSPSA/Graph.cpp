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
	srand(time(NULL));
	//lista wierzcholkow
	vector<int> nodes;
	int startVertex = 0;
	//dodanie wszystkich wierzcholkow do listy
	for (int i = 0; i < VertexNumber; i++)
	{
		if (i != startVertex)
		{
			nodes.push_back(i);
		}
	}

	//cout << CalcCost(nodes, startVertex) << endl;

	random_shuffle(nodes.begin(), nodes.end(), [](int n) { return rand() % n; });

	vector<int> bestPermutation;
	bestPermutation = nodes;
	int n = 0;
	int l = 5;
	float t0 =  1000;
	int k = 0;
	float t = t0;
	while (n < 2)
	{
		k++;
		vector<int> bestInEra = nodes;
		vector<int> current = nodes;

		for (int i = 0; i < l; i++)
		{
			int r1 = 0;
			int r2 = 0;
			while (r1 == r2)
			{
				r1 = rand() % (VertexNumber - 1);
				r2 = rand() % (VertexNumber - 1);
			}
			swap(current[r1], current[r2]);
			int delta = CalcCost(current, startVertex) - CalcCost(bestInEra, startVertex);
			if (delta < 0)
			{
				bestInEra = current;
			}
		}

		int delta = CalcCost(bestInEra, startVertex) - CalcCost(bestPermutation, startVertex);
		float s = float(rand() % 101) / 100;
		if (delta<0 || exp(-(delta) / t)>s)
		{
			bestPermutation = bestInEra;
			//nodes = bestPermutation;
			n = 0;
		}
		else
		{
			n++;
		}
		t = ChangeTemperature(t, k);
	}

	for (int i = 0; i < VertexNumber - 1; i++)
	{
		BestPath[i] = bestPermutation[i];
	}
	BestPath[VertexNumber] = startVertex;
	ShortestPath = CalcCost(bestPermutation, startVertex);
}

int Graph::CalcCost(vector<int> path, int startVertex)
{
	int cost = AdjacencyMatrix[startVertex][path[0]];
	for (int i = 0; i < path.size()-1; i++)
	{
		cost += AdjacencyMatrix[path[i]][path[i + 1]];
	}
	cost += AdjacencyMatrix[path[path.size()-1]][startVertex];
	return cost;
}

float Graph::ChangeTemperature(float t, int k)
{
	return pow(0.99999999999, k) * t;
}