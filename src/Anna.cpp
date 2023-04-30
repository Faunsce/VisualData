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

	void func()
	{
		displayData(std::vector<int> {});
	}
}
