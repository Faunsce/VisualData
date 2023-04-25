// STD Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Personal Includes
#include "ConsoleLocaleFix.hpp"

namespace anna 
{
	void displayData(std::vector<int> data);
}


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
	/*
	start at beginning of array
	move towards reducing size end
	swap largest element, to front
	now sorted front can be ignored
	*/

	for (int arrayEnd = numberArray.size() - 1; arrayEnd > 0; arrayEnd--)
	{
		static int swaps = 0;
		static int checks = 0;
		bool sorted = true;
		for (int arrayScan = 0; arrayScan < numberArray.size() - 1; arrayScan++)
		{
			checks++;
			if (numberArray[arrayScan] > numberArray[arrayScan + 1])
			{
				swaps++;
				sorted = false;
				std::swap(numberArray[arrayScan], numberArray[arrayScan + 1]);
				anna::displayData(numberArray);
			}
		}
		//std::wcout << L"Checks :" << std::to_wstring(checks) << L"  Swaps :" << std::to_wstring(swaps) << L"\n";
		if (sorted) break;
	}

	anna::displayData(numberArray);

	std::cin.ignore(5);

	return 0;

}


namespace anna 
{
	void displayData(std::vector<int> data) 
	{
		
		std::wstring topLine(L"╔");
		std::wstring midLine(L"║");
		std::wstring botLine(L"╚");

		std::wstring stringData; 
		for (auto&& slot : data) 
		{
			stringData += (L" [" + std::to_wstring(slot) + L"] ");
		}

		for (auto&& value : stringData) 
		{
			topLine += L"═";
			midLine += value;
			botLine += L"═";
			
		}

		topLine = topLine + L"╗";
		midLine = midLine + L"║";
		botLine = botLine + L"╝";

		std::wcout
			<< topLine << L"\n"
			<< midLine << L"\n"
			<< botLine << L"\n";

	}
}