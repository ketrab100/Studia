#include "FileReader.h"


FileReader::FileReader()
{
}

void FileReader::read(string fileName)
{
	vertexNumber = 0;
	ifstream ifs;
	fileName = fileName;
	ifs.open(fileName);
	if (ifs.is_open())
	{
		ifs >> this->vertexNumber;
		this->AdjacencyMatrix = new int*[vertexNumber];
		for (int i = 0; i < this->vertexNumber; i++)
		{
			AdjacencyMatrix[i] = new int[vertexNumber];
			for (int j=0;j<this->vertexNumber;j++)
			{
				ifs >> AdjacencyMatrix[i][j];
			}
		}
	}
	ifs.close();
}