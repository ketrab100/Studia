#include <iostream>
#include "INI.h"
#include "FileReader.h"
#include "Population.h"

using namespace std;

int main()
{
	mINI::INIFile file("plik.ini");
	mINI::INIStructure ini;
	file.read(ini);
	for (int i = 1; i <= 2; i++)
	{
		string name = to_string(i);
		string fileName = ini[name]["fileName"];
		string solutions = ini[name]["solution"];
		int solution = stoi(solutions);


		Population* population = new Population(50,0.01f,fileName);

		for (int i = 0; i < 100; i++)
		{
			population->Generation();
		}
		
		population->showBest();

	}

}
