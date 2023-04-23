// STD Includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>


// Stolen code cause microsoft is dumb
#ifndef MS_STDLIB_BUGS
#  if ( _MSC_VER || __MINGW32__ || __MSVCRT__ )
#    define MS_STDLIB_BUGS 1
#  else
#    define MS_STDLIB_BUGS 0
#  endif
#endif

#if MS_STDLIB_BUGS
#  include <io.h>
#  include <fcntl.h>
#endif

void init_locale(void)
{
#if MS_STDLIB_BUGS
	constexpr char cp_utf16le[] = ".1200";
	setlocale(LC_ALL, cp_utf16le);
	_setmode(_fileno(stdout), _O_WTEXT);
#else
	// The correct locale name may vary by OS, e.g., "en_US.utf8".
	constexpr char locale_name[] = "";
	setlocale(LC_ALL, locale_name);
	std::locale::global(std::locale(locale_name));
	std::wcin.imbue(std::locale())
		std::wcout.imbue(std::locale());
#endif
}

namespace anna {
	void displayData(std::vector<int> data);
}


int main()
{
	init_locale();
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

		for (auto&& value : data) {
			topLine = topLine + L"═";
			midLine = midLine + std::to_wstring(value);
			botLine = botLine + L"═";
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