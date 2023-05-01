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

	std::wcout << L"\x1b[2J\x1b[H";
	std::wcout
		<< L"╔═════════════════════════════════════════════════════════════════╗\n"
		<< L"║                                                                 ║\n"
		<< L"║                Welcome to my little program!                    ║\n"
		<< L"║                                                                 ║\n"
		<< L"║                                                                 ║\n"
		<< L"║             In this program you will be able to                 ║\n"
		<< L"║             set a data array to a fixed length,                 ║\n"
		<< L"║             shuffle it, then re-organize it                     ║\n"
		<< L"║             using an algorithm of your choice!                  ║\n"
		<< L"║                                                                 ║\n"
		<< L"║                                                                 ║\n"
		<< L"║                                                                 ║\n"
		<< L"║                                                                 ║\n"
		<< L"║                                                                 ║\n"
		<< L"╚═════════════════════════════════════════════════════════════════╝\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	
	std::wstring userInput;
	bool clean;
	do {
		clean = true;
		std::wcout << L"\x1b[2J\x1b[H";
		std::wcout
			<< L"╔═════════════════════════════════════════════════════════════════╗\n"
			<< L"║                                                                 ║\n"
			<< L"║            Please enter set the size of your data!              ║\n"
			<< L"║                                                                 ║\n"
			<< L"║             You may enter a value between 10 and                ║\n"
			<< L"║             100 for the size of the array.                      ║\n"
			<< L"║                                                                 ║\n"
			<< L"║                                                                 ║\n"
			<< L"║                                                                 ║\n"
			<< L"║                                                                 ║\n"
			<< L"║                                                                 ║\n"
			<< L"║                                                                 ║\n"
			<< L"║                                                                 ║\n"
			<< L"║                                                                 ║\n"
			<< L"╚═════════════════════════════════════════════════════════════════╝\n"
			<< L"Size of array : ";
		std::getline(std::wcin, userInput);
		for (const auto& value : userInput)
		{
			if (!std::isdigit(value))
			{
				clean = false;
				break;
			}
		}
		if (std::stoi(userInput) > 20)
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

	algos::bubbleSort(numberArray);
	anna::displayData(numberArray);

	std::cin.ignore(5);

	return 0;

}
