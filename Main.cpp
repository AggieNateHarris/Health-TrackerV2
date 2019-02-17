#include <iostream>
#include "newEntry.h"
#include "viewEntry.h"

int main()
{
	int openingChoice = 1;
	while (openingChoice > 0)
	{
		std::cout << "Welcome to Health Tracker!" << '\n';
		std::cout << "Please choose [0] Exit, [1] New Entry, [2] View current info.\n";
		std::cin >> openingChoice;
		if (openingChoice == 1)
			newEntry();
		else if (openingChoice == 2)
			viewEntry();

	}

	return 0;
}