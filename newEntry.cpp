#include "newEntry.h"
#include <iostream>
#include <fstream>
#include <string>



newEntry::newEntry()
{
	std::cout << "Enter, in order, weight, BF%, Muscle%, PL Total, Water%, date.\n";
	double weight, bf, muscle, total, water, fatMass;
	std::string date;
	std::cin >> weight >> bf >> muscle >> total >> water >> date;
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
		double wilks = (total / 2.205) * 500;
		double kgWeight = weight / 2.205;
		double denominator = (-216.0475144) + (16.2606339 * kgWeight) + (-.002388645 * kgWeight * kgWeight) + (-.00113732 * kgWeight * kgWeight * kgWeight) +
			((7.01863 / 1000000) * kgWeight * kgWeight * kgWeight * kgWeight) + ((-1.291 / 100000000) * kgWeight * kgWeight * kgWeight * kgWeight * kgWeight);
		wilks /= denominator;
		appendFile << wilks << " ";
	}
	appendFile.close();

	appendFile.open("date.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening date file.\n";
	else
		appendFile << date << " ";
	appendFile.close();

	appendFile.open("fatMass.txt", std::ios_base::app);
	if (!appendFile.is_open())
		std::cout << "Error opening fatMass file.\n";
	else
		fatMass = weight * (bf / 100);
		appendFile << fatMass << " ";
	appendFile.close();
}
