#include "Population.h"

Population::Population(int populationSize, float mutaionRate, string fileName)
{
	maxCost = 0;
	this->populationSize = populationSize;
	this->mutationRate = mutationRate;
	
	for (int i = 0; i < populationSize; i++)
	{
		Graph g;
		g.FromFile(fileName);
		g.Randomize();
		g.CalcCost();
		g.ShowAdjacencyMatrix();
		g.ShowBestPath();
		cout << g.Cost << endl;
		if (maxCost < g.Cost)
		{
			maxCost = g.Cost;
		}
		population.push_back(g);
	}
}

void Population::CalcFitness()
{
	for (Graph g : population)
	{
		g.CalcCost();
	}
}

Graph Population::showBest()
{
	Graph* best = new Graph(population[0].VertexNumber);
	best->Cost = INT32_MAX;
	CalcFitness();
	for (Graph g : population)
	{
		if (best->Cost > g.Cost)
		{
			best = &g;
		}
	}
	best->ShowBestPath();
	cout << endl;
	cout << best->Cost;
	return *best;
}

void Population::Generation()
{
	CalcFitness();
	vector<Graph> matingPool;
	for (Graph g : population)
	{
		for (int j = 0; j < maxCost - g.Cost; j++)
		{
			matingPool.push_back(g);
		}
	}
	for (Graph g : population)
	{
		int random1 = rand() % matingPool.size();
		int random2 = rand() % matingPool.size();
		g = Graph::CrossOver(matingPool[random1], matingPool[random2]);
		g.Mutate(this->mutationRate);
	}
}