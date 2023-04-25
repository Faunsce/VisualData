// STD Includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Personal Includes
#include "ConsoleLocaleFix.hpp"
#include "Anna.hpp"


int main()
{
	consoleFix::init_locale();
	// Create a data set, be able to sort it, and display its elements visually
	std::vector<int> numberArray;
	const int dataSetSize = 20;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	for (int i = 0; i < dataSetSize; i++)
	{
		numberArray.push_back(i);
	}


	anna::displayData(numberArray);

	std::shuffle(numberArray.begin(), numberArray.end(), std::default_random_engine(seed));

	anna::displayData(numberArray);

	anna::bubbleSort(numberArray);

	anna::displayData(numberArray);

	std::cin.ignore(5);

	return 0;

}
