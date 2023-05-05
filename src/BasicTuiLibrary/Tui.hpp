#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace tuilib
{
	constexpr std::wstring_view clearScreen = L"\x1b[2J\x1b[H";

	class Tui
	{
	private:
		int printWidth;
		int printHeight;
		int headerHeight;
		int freeHeight;
		int bodyHeight;
	public:
		Tui();
		~Tui();
		void print(std::wstring header, std::wstring body);
	};
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

/*
╔═╗
║ ║
╚═╝
*/
