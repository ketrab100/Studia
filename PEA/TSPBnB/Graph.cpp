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

void Graph::copyToFinal(vector<int> curr_path, vector<int> final_path)
{
    for (int i = 0; i < VertexNumber; i++)
        final_path[i] = curr_path[i];
    final_path[VertexNumber] = curr_path[0];
}


int Graph::firstMin(int i)
{
    int min = INT_MAX;
    for (int k = 0; k < VertexNumber; k++)
        if (AdjacencyMatrix[i][k] < min && i != k)
            min = AdjacencyMatrix[i][k];
    return min;
}

int Graph::secondMin(int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < VertexNumber; j++)
    {
        if (i == j)
            continue;

        if (AdjacencyMatrix[i][j] <= first)
        {
            second = first;
            first = AdjacencyMatrix[i][j];
        }
        else if (AdjacencyMatrix[i][j] <= second &&
			AdjacencyMatrix[i][j] != first)
            second = AdjacencyMatrix[i][j];
    }
    return second;
}

void Graph::TSPRec(int curr_bound, int curr_weight,int level, vector<int> curr_path, vector<bool> visited, vector<int>final_path, int& final_res)
{
    if (level == VertexNumber)
    {
        if (AdjacencyMatrix[curr_path[level - 1]][curr_path[0]] != -1)
        {
            int curr_res = curr_weight +
				AdjacencyMatrix[curr_path[level - 1]][curr_path[0]];

            if (curr_res <= final_res)
            {
                copyToFinal(curr_path, final_path);
                final_res = curr_res;
            }
        }
        return;
    }

    // for any other level iterate for all vertices to
    // build the search space tree recursively
    for (int i = 0; i < VertexNumber; i++)
    {
        // Consider next vertex if it is not same (diagonal
        // entry in adjacency matrix and not visited
        // already)
        if (AdjacencyMatrix[curr_path[level - 1]][i] != -1 && visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += AdjacencyMatrix[curr_path[level - 1]][i];

            // different computation of curr_bound for
            // level 2 from the other levels
            if (level == 1)
                curr_bound -= ((firstMin(curr_path[level - 1]) +
                    firstMin(i)) / 2);
            else
                curr_bound -= ((secondMin(curr_path[level - 1]) +
                    firstMin(i)) / 2);

            // curr_bound + curr_weight is the actual lower bound
            // for the node that we have arrived on
            // If current lower bound < final_res, we need to explore
            // the node further
            if (curr_bound + curr_weight <= final_res)
            {
                curr_path[level] = i;
                visited[i] = true;

                // call TSPRec for the next level
                TSPRec(curr_bound, curr_weight, level + 1,
                    curr_path, visited, final_path, final_res);
            }

            // Else we have to prune the node by resetting
            // all changes to curr_weight and curr_bound
            curr_weight -= AdjacencyMatrix[curr_path[level - 1]][i];
            curr_bound = temp;

            // Also reset the visited array
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

// This function sets up final_path[] 
void Graph::TSP()
{
    vector<int> curr_path(VertexNumber + 1);
    vector<int> final_path(VertexNumber + 1);
    vector<bool> visited(VertexNumber);
    int final_res = INT_MAX;

    // Calculate initial lower bound for the root node
    // using the formula 1/2 * (sum of first min +
    // second min) for all edges.
    // Also initialize the curr_path and visited array
    int curr_bound = 0;
    fill(curr_path.begin(), curr_path.end(), -1);
    fill(visited.begin(), visited.end(), 0);

    // Compute initial bound
    for (int i = 0; i < VertexNumber; i++)
        curr_bound += (firstMin(i) +
            secondMin(i));

    // Rounding off the lower bound to an integer
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 :
        curr_bound / 2;

    // We start at vertex 1 so the first vertex
    // in curr_path[] is 0
    visited[0] = true;
    curr_path[0] = 0;

    // Call to TSPRec for curr_weight equal to
    // 0 and level 1
    TSPRec(curr_bound, 0, 1, curr_path, visited, final_path, final_res);

	ShortestPath = final_res;


}