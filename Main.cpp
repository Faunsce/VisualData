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

	std::random_device rd{};
	std::mt19937 engine{ rd() };

	std::vector<int> numberArray;
	const int dataSetSize = 20;
	for (int i = 1; i <= dataSetSize; i++)
	{
		numberArray.push_back(i);
	}
	anna::displayData(numberArray);

	std::shuffle(numberArray.begin(), numberArray.end(), engine);
	anna::displayData(numberArray);

	anna::bubbleSort(numberArray);
	anna::displayData(numberArray);

	std::cin.ignore(5);

	return 0;

}
