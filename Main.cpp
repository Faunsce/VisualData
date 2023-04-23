// STD Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Personal Includes
#include "ConsoleLocaleFix.hpp"

namespace anna {
	void displayData(std::vector<int> data);
}


int main()
{
	consoleFix::init_locale();
	// Create a data set, be able to sort it, and display its elements visually
	std::vector<int> numberArray;
	const int dataSetSize = 20;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	for (int i = 0; i < dataSetSize; i++) {
		numberArray.push_back(i);
	}

	anna::displayData(numberArray);

	std::shuffle(numberArray.begin(), numberArray.end(), std::default_random_engine(seed));

	anna::displayData(numberArray);

	std::sort(numberArray.begin(), numberArray.end());
	
	anna::displayData(numberArray);

	std::cin.ignore(5); https://i.imgur.com/p9tIxnO.png

	return 0;

}


namespace anna {
	void displayData(std::vector<int> data) {
		
		std::wstring topLine(L"╔");
		std::wstring midLine(L"║");
		std::wstring botLine(L"╚");

		std::wstring stringData; 
		for (auto&& slot : data) {
			stringData += std::to_wstring(slot);
		}

		for (auto&& value : stringData) {
			topLine += L"═";
			midLine += value;
			botLine += L"═";
			
		}

		topLine = topLine + L"╗";
		midLine = midLine + L"║";
		botLine = botLine + L"╝";

		std::wcout
			<< topLine << "\n"
			<< midLine << "\n"
			<< botLine << "\n";

	}
}