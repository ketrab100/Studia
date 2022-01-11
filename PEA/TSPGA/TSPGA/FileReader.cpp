#include "FileReader.h"


void FileReader::Read(string fileName)
{
	VertexNumber = 0;
	ifstream ifs;
	fileName = fileName;
	ifs.open(fileName);
	if (ifs.is_open())
	{
		ifs >> this->VertexNumber;
		this->AdjacencyMatrix = new int* [VertexNumber];
		for (int i = 0; i < this->VertexNumber; i++)
		{
			AdjacencyMatrix[i] = new int[VertexNumber];
			for (int j = 0; j < this->VertexNumber; j++)
			{
				ifs >> AdjacencyMatrix[i][j];
			}
		}
	}
	ifs.close();
}