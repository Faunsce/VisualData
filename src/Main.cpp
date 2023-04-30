// STD Includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>

// Personal Includes
#include "ConsoleLocaleFix.hpp"
#include "Anna.hpp"
#include "Algos.hpp"


int main()
{
	consoleFix::init_locale();

	std::random_device randomSeed{}; 
	std::mt19937 randomEngine{ randomSeed() };

	std::wcout
		<< L"╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                              Welcome to my little program!                                       ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"║                                                                                                  ║\n"
		<< L"╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n"
		<< L"\x1b[2J\x1b[H";
	
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::vector<int> numberArray;
	const int dataSetSize = 20;
	for (int i = 1; i <= dataSetSize; i++)
	{
		numberArray.push_back(i);
	}

	std::shuffle(numberArray.begin(), numberArray.end(), randomEngine);
	anna::displayData(numberArray);

	algos::bubbleSort(numberArray);
	anna::displayData(numberArray);

	std::cin.ignore(5);

	return 0;

}
