#include <fstream>
#include <iostream>
#include <vector>
#pragma once
using namespace std;
class FileReader
{
public:
	FileReader();
	void read(string fileName);
	int vertexNumber;
	int** AdjacencyMatrix;
};