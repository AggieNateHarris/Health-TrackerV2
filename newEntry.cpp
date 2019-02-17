#include "newEntry.h"
#include <iostream>
#include <fstream>
#include <string>



newEntry::newEntry()
{
	std::cout << "Enter, in order, weight, BF%, Muscle%, PL Total, Water%.\n";
	double weight, bf, muscle, total, water;
	std::cin >> weight >> bf >> muscle >> total >> water;
	std::ofstream appendFile;
	appendFile.open("weight.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening weight file.\n";
	else
		appendFile << weight << " ";
	appendFile.close();

	appendFile.open("bf.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening bf file.\n";
	else
		appendFile << bf << " ";
	appendFile.close();

	appendFile.open("muscle.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening muscle file.\n";
	else
		appendFile << muscle << " ";
	appendFile.close();

	appendFile.open("total.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening total file.\n";
	else
		appendFile << total << " ";
	appendFile.close();

	appendFile.open("water.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening water file.\n";
	else
		appendFile << water << " ";
	appendFile.close();

	appendFile.open("muscleMass.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening muscle mass file.\n";
	else
	{
		double muscleMass = muscle / 100;
		muscleMass = muscleMass * weight;
		appendFile << muscleMass << " ";
	}
	appendFile.close();

	appendFile.open("wilks.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening wilks file.\n";
	else
	{
		double wilks = total * 500;
		double denominator = (-216.0475144) + (16.2606339 * weight) + (-.002388645 * weight * weight) + (-.00113732 * weight * weight * weight) +
			((7.01863 / 1000000) * weight * weight * weight * weight) + ((-1.291 / 100000000) * weight * weight * weight * weight * weight);
		wilks /= denominator;
		appendFile << wilks << " ";
	}
	appendFile.close();
}
