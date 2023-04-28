#include "Anna.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

namespace anna
{
	template<typename T>
	void displayData(std::vector<T> data)
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
			<< L"\x1b[2J\x1b[H"
			<< topLine << L"\n"
			<< midLine << L"\n"
			<< botLine << L"\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 4));

	}

	template<typename T>
	std::vector<T> bubbleSort(std::vector<T> dataArray) 
	{
		for (int arrayEnd = dataArray.size() - 1; arrayEnd > 0; arrayEnd--)
		{
			static int swaps = 0;
			static int checks = 0;
			bool sorted = true;
			for (int arrayScan = 0; arrayScan < dataArray.size() - 1; arrayScan++)
			{
				checks++;
				if (dataArray[arrayScan] > dataArray[arrayScan + 1])
				{
					swaps++;
					sorted = false;
					std::swap(dataArray[arrayScan], dataArray[arrayScan + 1]);
					anna::displayData(dataArray);
				}
			}
			//std::wcout << L"Checks :" << std::to_wstring(checks) << L"  Swaps :" << std::to_wstring(swaps) << L"\n";
			if (sorted) break;
		}
		return dataArray;
	}

	void linkFixFunction()
	{
		displayData(std::vector<int>{});
		std::vector<int> test = bubbleSort(std::vector<int>{});
	}
}
