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
#include "BasicTuiLibrary/Tui.hpp"

int main()
{
	consoleFix::init_locale();
	std::random_device randomSeed{}; 
	std::mt19937 randomEngine{ randomSeed() };
	tuilib::Tui window;

	window.print(L"Welcome to my little program!",
		L"In this program you will be able to set a data array to a fixed length, shuffle it, then re - organize it using an algorithm of your choice!");
	std::this_thread::sleep_for(std::chrono::seconds(5));
	
	std::wstring userInput;
	bool clean;
	do {
		clean = true;
		window.print(L"Please enter the size of your data set!",
			L"You may enter a value between 10 and 100 for the size of the array.");
		std::getline(std::wcin, userInput);
		for (const auto& value : userInput)
		{
			if (!std::isdigit(value))
			{
				clean = false;
				break;
			}
		}
		if (clean && std::stoi(userInput) > 100)
		{
			clean = false;
		}
	} while (!clean);

	std::vector<int> numberArray;
	int dataSetSize = std::stoi(userInput);
	for (int i = 1; i <= dataSetSize; i++)
	{
		numberArray.push_back(i);
	}

	std::shuffle(numberArray.begin(), numberArray.end(), randomEngine);
	anna::displayData(numberArray);

	auto dataHistory = algos::bubbleSort(numberArray);
	for (const auto& dataState : dataHistory)
	{
		anna::displayData(dataState);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	anna::displayData(numberArray);

	std::cin.ignore(5);

	return 0;

}

/* 
Possibly create class for box, with lineand column class.make your own box object, with methods to manipulat it, then just output THAT to the console.
columns and rows dont have to be classes. make them an array of char's, create functions for manipulating that. this may or may not be easier than an array of strings. there is essentially no difference.

Solve displaying in use data by storing a large array containing the state of the array. cycle through that list to display each state of the array.
*/

