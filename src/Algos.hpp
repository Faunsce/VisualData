namespace algos
{
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
}