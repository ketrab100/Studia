#include "Graph.h"
using namespace std;

Graph::Graph(FileReader* fileReader)
{
	this->VertexNumber = fileReader->vertexNumber;
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
	for (int i = 0; i < VertexNumber; i++)
	{
		cout << BestPath[i] << "-";
	}
	cout << BestPath[VertexNumber];
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
	Iterations = 0;
	//generowanie kolnejnych permutacji
	do
	{
		Iterations++;
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
	Iterations--;
	this->ShortestPath = shortest_path;
}

//rozwi¹zanie prblemu komiwojazera algorytmem Helda-Karpa

void Graph::HeldKarp()
{
	// initialize the DP table 
	// best[visited][last] = the cheapest way to reach the state where: 
	// - "visited" encodes the set of visited vertices other than N-1
	// - "last" is the number of the vertex visited last 

	vector< vector<int> > best(1 << (VertexNumber - 1), vector<int>(VertexNumber, INT_MAX));

	// use DP to solve all states 
	// note that whenever we solve a particular state,  
	// the smaller states we need have already been solved 

	for (int visited = 1; visited < (1 << (VertexNumber - 1)); ++visited) 
	{
		for (int last = 0; last < (VertexNumber - 1); ++last) 
		{

			// last visited vertex must be one of the visited vertices 
			if (!(visited & 1 << last))
			{
				continue;
			}

			// try all possibilities for the previous vertex, 
			// pick the best among them 
			if (visited == 1 << last) 
			{
				// previous vertex must have been N-1 
				best[visited][last] = AdjacencyMatrix[VertexNumber - 1][last];
			}
			else {
				// previous vertex was one of the other ones in "visited" 
				int prev_visited = visited ^ 1 << last;
				for (int prev = 0; prev < VertexNumber - 1; ++prev) {
					if (!(prev_visited & 1 << prev))
					{
						continue;
					}
					best[visited][last] = min(best[visited][last],AdjacencyMatrix[last][prev] + best[prev_visited][prev]);
				}
			}
		}
	}

	// use the precomputed path lengths to choose the cheapest cycle 
	int answer = INT_MAX;
	for (int last = 0; last < VertexNumber - 1; ++last)
	{
		answer = min(answer, AdjacencyMatrix[last][VertexNumber - 1] + best[(1 << (VertexNumber - 1)) - 1][last]);
	}

	ShortestPath = answer;
}
