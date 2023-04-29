// STD Includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Personal Includes
#include "ConsoleLocaleFix.hpp"
#include "Anna.hpp"
#include "Algos.hpp"


int main()
{
	consoleFix::init_locale();

	std::random_device randomSeed{}; 
	std::mt19937 randomEngine{ randomSeed() };

	std::vector<int> numberArray;
	const int dataSetSize = 20;
	for (int i = 1; i <= dataSetSize; i++)
	{
	}

	std::shuffle(numberArray.begin(), numberArray.end(), randomEngine);
	anna::displayData(numberArray);

	algos::bubbleSort(numberArray);
	anna::displayData(numberArray);

	std::cin.ignore(5);

	return 0;

}
