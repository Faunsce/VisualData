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


inline constexpr std::wstring_view clearScreen = L"\x1b[2J\x1b[H";

const int printWidth = 60;
const int printHeight = 40;
const int headerHeight = 2;
const int freeHeight = 3;
const int bodyHeight = 35;

/*
╔═╗
║ ║
╚═╝
*/

void print(std::wstring header, std::wstring body)
{
	std::vector<std::wstring> page;

	// Create Header and center it
	int headerSpaces = printWidth - header.length();
	header = std::wstring(headerSpaces / 2, L' ') + header + std::wstring(headerSpaces - (headerSpaces / 2), L' ');
	

	// Create Body and center it
	std::vector<std::wstring> bodyArray{std::wstring()};
	for (const auto& letter : body)
	{
		if (bodyArray[bodyArray.size() - 1].length() >= printWidth)
		{
			bodyArray.push_back(std::wstring());
		}
		bodyArray[bodyArray.size() - 1] += letter;
	}
	if (bodyArray[bodyArray.size() - 1].length() < printWidth)
	{
		bodyArray[bodyArray.size() - 1] += std::wstring(printWidth - bodyArray[bodyArray.size() - 1].length(), L' ');
	}

	for (int i = 0; i < bodyHeight - bodyArray.size(); i++)
	{
		bodyArray.emplace_back(std::wstring(printWidth, L' '));
	}


	// Put Together page
	page.emplace_back(std::wstring(printWidth, L'═'));
	page.emplace_back(std::wstring(printWidth, L' '));
	page.emplace_back(header);
	for (int i = 0; i < 3; i++)
	{
		page.emplace_back(std::wstring(printWidth, L' '));
	}
	page.insert(page.end(), bodyArray.begin(), bodyArray.end());
	page.emplace_back(std::wstring(printWidth, L' '));
	page.emplace_back(std::wstring(printWidth, L'═'));


	// Add Side Borders
	page[0] = L"╔" + page[0] + L"╗";
	for (int i = 1; i < page.size() - 1; i++)
	{
		page[i] = L"║" + page[i] + L"║";
	}
	page[page.size() - 1] = L"╚" + page[page.size() - 1] + L"╝";

	std::wcout << clearScreen;
	for (const auto& line : page)
	{
		std::wcout << line << L"\n";
	} 
}

/*template<typename T>
requires std::integral<T> || std::floating_point<T>
void print(std::vector<T> dataArray)
{
	int arrayItemMaxSize = 1;
	for (const auto& arrayItem : dataArray)
	{
		int itemLength = std::string(arrayItem).length();
		if (itemLength > arrayItemMaxSize)
		{
			arrayItemMaxSize = std::string(arrayItem).length();
		}
	}

	int containerSize = arrayItemMaxSize + 2;
	int itemsPerLine = printWidth / containerSize;


	print(L"Sorting array of X using the Y method", L"Your Data");
}
*/

int main()
{
	consoleFix::init_locale();
	std::random_device randomSeed{}; 
	std::mt19937 randomEngine{ randomSeed() };

	print(L"Welcome to my little program!",
		L"In this program you will be able to set a data array to a fixed length, shuffle it, then re - organize it using an algorithm of your choice!");
	std::this_thread::sleep_for(std::chrono::seconds(5));
	
	std::wstring userInput;
	bool clean;
	do {
		clean = true;
		print(L"Please enter the size of your data set!",
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
		if (clean && std::stoi(userInput) > 20)
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

