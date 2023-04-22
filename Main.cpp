// STD Includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>


// Personal Includes


int main()
{
	// Create a data set, be able to sort it, and display its elements visually
	std::vector<int> numberArray;
	const int dataSetSize = 20;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	for (int i = 0; i < dataSetSize; i++) {
		numberArray.push_back(i);
	}

	std::shuffle(numberArray.begin(), numberArray.end(), std::default_random_engine(seed));
	for (auto&& number : numberArray) {
		std::cout << "[" << number << "]";
	}
	std::cout << std::endl;

	std::sort(numberArray.begin(), numberArray.end());
	for (auto&& number : numberArray) {
		std::cout << "[" << number << "]";
	}
	std::cout << std::endl;
}
