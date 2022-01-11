#include <fstream>
#include <iostream>
#include <vector>
#pragma once
using namespace std;
class FileReader
{
public:
	void Read(string fileName);
	int VertexNumber;
	int** AdjacencyMatrix;
};