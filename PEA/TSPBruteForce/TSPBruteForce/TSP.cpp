#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "ini.h"
#include "FileReader.h"
#include "Graph.h"

using namespace std;
long long int read_QPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return ((long long int)count.QuadPart);
}
int main()
{
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	ofstream csvFile("wyniki.csv");
	mINI::INIFile file("plik.ini");
	mINI::INIStructure ini;
	file.read(ini);

	for (int i = 1; i <= 11; i++)
	{
		string name = to_string(i);
		string fileName = ini[name]["fileName"];
		string solutions = ini[name]["solution"];
		int solution = stoi(solutions);

		FileReader* graphFile;
		graphFile = new FileReader();
		graphFile->read(fileName);

		Graph* graph;
		graph = new Graph(graphFile);
		start = read_QPC();

		

		graph->HeldKarp();

		elapsed = read_QPC() - start;

		cout << "Nazwa pliku: " << fileName << endl;
		cout << "Kosz przejscia optymalna sciezka: ";
		cout << graph->ShortestPath << endl;
		
		cout << endl << "Czas znalezienia sciezki  [ms] = " << setprecision(3) << (1000.0 * elapsed) / frequency << endl << endl;

		csvFile << "Nazwa pliku;Koszt przejscia" << endl;
		csvFile << fileName << ";" << graph->ShortestPath;
		csvFile << endl << "Time [us] = ;" << setprecision(3) << (1000000.0 * elapsed) / frequency << endl;
		csvFile << "Time [ms] = ;" << setprecision(3) << (1000.0 * elapsed) / frequency << endl ;
		csvFile << "Wielkosc instacji = ;" << graph->VertexNumber << endl << endl;

		delete graph;
	}

	system("PAUSE");
}