#include "viewEntry.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


viewEntry::viewEntry()
{
	std::ifstream readFile;
	std::vector<double> weightV, bfV, muscle, total, water, muscleMass, wilks;
	readFile.open("weight.txt");
	if (!readFile.is_open())
		std::cout << "Error opening weight file.\n";
	else
	{
		while (!readFile.eof())
		{
			double weight;
			readFile >> weight;
			weightV.push_back(weight);
		}
		readFile.close();
	}
}
