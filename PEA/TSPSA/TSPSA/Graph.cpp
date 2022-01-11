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

void Graph::SimulatedAnnealing()
{
    double temperature = VertexNumber*170;
    srand(time(NULL));
    int era = 1;

    vector<int> globalShortestPath;
    for (int q = 0; q < VertexNumber; q++)
    {
        if (q != 0)
        {
            globalShortestPath.push_back(q);
        }
    }

    int n = globalShortestPath.size();
    random_shuffle(globalShortestPath.begin(), globalShortestPath.end());

    int globalShortestPathCost = 0;
    globalShortestPathCost = CalcCost(globalShortestPath);

    while (temperature > 0.00000000001) {
        int localShortestPathCost = INT_MAX;
        vector<int> localShortestPath;

        for (int i = 0; i < 10; i++) {
            int currentPathCost = 0;
            int swap_node_1 = rand() % (VertexNumber - 1);
            int swap_node_2 = rand() % (VertexNumber - 1);
            while (swap_node_1 == swap_node_2) 
            {
                swap_node_2 = rand() % (VertexNumber - 1);
            }
            vector<int> currentPath = globalShortestPath;
            swap(currentPath[swap_node_1], currentPath[swap_node_2]);
            currentPathCost = CalcCost(currentPath);
            if (currentPathCost < localShortestPathCost)
            {
                localShortestPathCost = currentPathCost;
                localShortestPath = currentPath;
            }
        }
        if (localShortestPathCost < globalShortestPathCost || (((double)rand() / (RAND_MAX)) <= exp(-abs(localShortestPathCost - globalShortestPathCost) / temperature))) 
        { 
            globalShortestPathCost = localShortestPathCost;
            globalShortestPath = localShortestPath;
            era++; 
        }
        else 
        { 
            era++; 
        }
        temperature = ChangeTemperature(temperature, era);
    }

    ShortestPath = CalcCost(globalShortestPath);
}

int Graph::CalcCost(vector<int> path)
{
	int cost = AdjacencyMatrix[0][path[0]];
	for (int i = 0; i < path.size() - 1; i++)
	{
		cost += AdjacencyMatrix[path[i]][path[i + 1]];
	}
	cost += AdjacencyMatrix[path[path.size() - 1]][0];
	return cost;
}

double Graph::ChangeTemperature(double temperature, int era)
{
    double alpha = 0.9999999999;
	return pow(alpha, era)*temperature;
}