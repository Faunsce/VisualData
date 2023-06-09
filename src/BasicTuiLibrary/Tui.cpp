﻿#include "Tui.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace tuilib
{
	Tui::Tui()
	{
		this->printWidth = 60;
		this->printHeight = 40;
		this->headerHeight = 2;
		this->freeHeight = 3;
		this->bodyHeight = 35;
	}

	Tui::~Tui()
	{

	}

	void Tui::print(std::wstring header, std::wstring body)
	{
		std::vector<std::wstring> page;

		// Create Header and center it
		int headerSpaces = printWidth - header.length();
		header = std::wstring(headerSpaces / 2, L' ') + header + std::wstring(headerSpaces - (headerSpaces / 2), L' ');


		// Create Body and center it
		std::vector<std::wstring> bodyArray{ std::wstring() };
		for (const auto& letter : body)
		{
			if (bodyArray[bodyArray.size() - 1].length() >= printWidth)
			{
				bodyArray.push_back(std::wstring());
			}
			bodyArray[bodyArray.size() - 1] += letter;
		}
		if (bodyArray[bodyArray.size() - 1].length() < printWidth) // make sure final line of text has proper spacing.
		{
			bodyArray[bodyArray.size() - 1] += std::wstring(printWidth - bodyArray[bodyArray.size() - 1].length(), L' ');
		}
		for (int i = 0; i < bodyHeight - bodyArray.size(); i++) // make sure body has proper height
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
}