// STD Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>


namespace anna {
	void displayData(std::vector<int> data);
}


int main()
{
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

}


namespace anna {
	void displayData(std::vector<int> data) {
		std::string topLine("╔");
		std::string midLine("║");
		std::string botLine("╚");

		for (auto&& value : data) {
			topLine = topLine + "═";
			midLine = midLine + std::to_string(value);
			botLine = botLine + "═";
		}

		topLine = topLine + "╗";
		midLine = midLine + "║";
		botLine = botLine + "╝";

		std::cout
			<< topLine << "\n"
			<< midLine << "\n"
			<< botLine << "\n";

	}
}