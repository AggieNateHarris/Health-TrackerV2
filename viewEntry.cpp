#include "viewEntry.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void changeOf(std::vector<double> inputV, std::vector<std::string> dateV, std::string whatChange)
{
	if (inputV.size() > 9)
	{
		std::cout << whatChange << " change between last 7 entries.\n";
		std::cout << "7: " << inputV[inputV.size() - 8] - inputV[inputV.size() - 1] << '\n';
	}
	if (inputV.size() > 31)
	{
		std::cout << whatChange << " change between last 30 entries.\n";
		std::cout << "30: " << inputV[inputV.size() - 30] - inputV[inputV.size() - 1] << '\n';
	}
	for (int i = 0; i < inputV.size(); i++)
	{
		std::cout << inputV.size() - i << ". ";
		std::cout << dateV[i] << " --- " << inputV[i] << '\n';
	}
}

viewEntry::viewEntry()
{
	std::ifstream readFile;
	std::vector<double> weightV, bfV, muscleV, totalV, waterV, muscleMassV, wilksV, fatMassV;
	std::vector<std::string> dateV;

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

	readFile.open("bf.txt");
	if (!readFile.is_open())
		std::cout << "Error opening bf file.\n";
	else
	{
		while (!readFile.eof())
		{
			double bf;
			readFile >> bf;
			bfV.push_back(bf);
		}
		readFile.close();
	}

	readFile.open("muscle.txt");
	if (!readFile.is_open())
		std::cout << "Error opening muscle file.\n";
	else
	{
		while (!readFile.eof())
		{
			double holder;
			readFile >> holder;
			muscleV.push_back(holder);
		}
		readFile.close();
	}

	readFile.open("total.txt");
	if (!readFile.is_open())
		std::cout << "Error opening total file.\n";
	else
	{
		while (!readFile.eof())
		{
			double holder;
			readFile >> holder;
			totalV.push_back(holder);
		}
		readFile.close();
	}

	readFile.open("water.txt");
	if (!readFile.is_open())
		std::cout << "Error opening water file.\n";
	else
	{
		while (!readFile.eof())
		{
			double holder;
			readFile >> holder;
			waterV.push_back(holder);
		}
		readFile.close();
	}

	readFile.open("muscleMass.txt");
	if (!readFile.is_open())
		std::cout << "Error opening muscle mass file.\n";
	else
	{
		while (!readFile.eof())
		{
			double holder;
			readFile >> holder;
			muscleMassV.push_back(holder);
		}
		readFile.close();
	}

	readFile.open("wilks.txt");
	if (!readFile.is_open())
		std::cout << "Error opening wilks file.\n";
	else
	{
		while (!readFile.eof())
		{
			double holder;
			readFile >> holder;
			wilksV.push_back(holder);
		}
		readFile.close();
	}

	readFile.open("date.txt");
	if (!readFile.is_open())
		std::cout << "Error opening date file.\n";
	else
	{
		while (!readFile.eof())
		{
			std::string holder;
			readFile >> holder;
			dateV.push_back(holder);
		}
		readFile.close();
	}

	readFile.open("fatMass.txt");
	if (!readFile.is_open())
		std::cout << "Error opening fat mass file.\n";
	else
	{
		while (!readFile.eof())
		{
			double holder;
			readFile >> holder;
			fatMassV.push_back(holder);
		}
		readFile.close();
	}
	/* Just opened up all the files and loaded their contents into vectors to be used. */
	/* Just opened up all the files and loaded their contents into vectors to be used. */
	/* Just opened up all the files and loaded their contents into vectors to be used. */
	/* Just opened up all the files and loaded their contents into vectors to be used. */
	/* Just opened up all the files and loaded their contents into vectors to be used. */

	int viewChoice = 1;

	while (viewChoice > 0)
	{
		for (int i = 0; i < weightV.size(); i++)
		{
			std::cout << dateV[i] << " / " << weightV[i] << " / " << bfV[i] << " / " << muscleV[i] << " / " << totalV[i] << " / " << waterV[i] << " / " << muscleMassV[i] << " / "
				<< wilksV[i] << " / " << '\n';
		}

		std::cout << "Options [0] Exit, [1] Weight, [2] Bf%, [3] Muscle%, [4] Total, [5] Water%, [6] Muscle Mass, [7] Wilks, [8] Fat Mass\n";
		std::cin >> viewChoice;

		if (viewChoice == 1)
		{
			if (weightV.size() > 9)
			{
				std::cout << "Weight change between last 7 entries.\n";
				std::cout << "7: " << weightV[weightV.size() - 8] - weightV[weightV.size() - 1] << '\n';
				std::cout << "Calorie differential: " << (weightV[weightV.size() - 8] - weightV[weightV.size() - 1]) * 3500 << '\n';
			}
			if (weightV.size() > 31)
			{
				std::cout << "Weight change between last 30 entries.\n";
				std::cout << "30: " << weightV[weightV.size() - 30] - weightV[weightV.size() - 1] << '\n';
				std::cout << "Calorie differential: " << (weightV[weightV.size() - 30] - weightV[weightV.size() - 1]) * 3500 << '\n';
			}
			for (int i = 0; i < weightV.size(); i++)
			{
				std::cout << weightV.size() - i << ". ";
				std::cout << dateV[i] << " --- " << weightV[i] << '\n';
			}
		}

		else if (viewChoice == 2)
		{
			changeOf(bfV, dateV, "Bf%");
		}

		else if (viewChoice == 3)
		{
			changeOf(muscleV, dateV, "Muscle%");
		}

		else if (viewChoice == 4)
		{
			changeOf(totalV, dateV, "Total");
		}

		else if (viewChoice == 5)
		{
			changeOf(waterV, dateV, "Water%");
		}

		else if (viewChoice == 6)
		{
			changeOf(muscleMassV, dateV, "Muscle mass");
		}

		else if (viewChoice == 7)
		{
			changeOf(wilksV, dateV, "wilks");
		}

		else if (viewChoice == 8)
		{
			changeOf(fatMassV, dateV, "Fat mass");
		}
	}
}