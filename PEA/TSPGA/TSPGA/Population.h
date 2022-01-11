#include "Graph.h"
#include "FileReader.h"

class Population
{
private:
	vector<Graph>population;
	int populationSize;
	int maxCost;
	float mutationRate;
	void CalcFitness();
public:
	Population(int popullatinSize, float mutationRate, string fileName);
	void Generation();
	Graph showBest();
	//virtual ~Population();
};