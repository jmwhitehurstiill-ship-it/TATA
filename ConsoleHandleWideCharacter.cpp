#include <iostream>
#include <string>
#include <Windows.h>  // For SetConsoleOutputCP, WriteConsoleW, SetConsoleTitle
#include <locale.h>   // For setlocale

int main() {
	SetConsoleTitle(L"Wide Character");
	SetConsoleOutputCP(65001);   // Enable UTF-8
	setlocale(LC_ALL, "en-us");  // Enable locale

	wchar_t name = L'★';
	const wchar_t* Sname = L"🐍🐍🐍🐍🐍";
	// modern alternative to const wchar_t* in c++
	std::wstring Stname = L"こんにちは🐍🐍🐍🐍🐍🐍🐍🐍🐍🐍🐍🐍🐍🐍🐍";

	// Get the console Handle
	HANDLE stdConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (stdConsole == INVALID_HANDLE_VALUE) {
		std::cerr << "Failed to get console handle. Error: " << GetLastError() << std::endl;
		return 1;
	}
	//star is a single wchar_t (wide character), its "size" is inherently 1
	WriteConsoleW(stdConsole, &name, 1, nullptr, nullptr);
	std::wcout << L"\n";
	// String size is 1 byte (strlen) and Wide String size is 2 byte (wcslen)
	WriteConsoleW(stdConsole, Sname, wcslen(Sname), nullptr, nullptr);
	std::wcout << L"\n";
	// The c_str() : in C++ is used to convert a std::string object to a C-style string
	WriteConsoleW(stdConsole, Stname.c_str(), Stname.size(), nullptr, nullptr);
	std::wcout << L"\n";

	// Checks
	std::cout << "\nSize of char: " << sizeof(char) << " bytes\n";
	std::cout << "Size of wchar_t: " << sizeof(wchar_t) << " bytes\n";
	std::cout << "Size of int: " << sizeof(int) << " bytes\n";
	std::cout << "Size of bool: " << sizeof(bool) << " bytes\n";

	std::cin.get();
	return 0;
}

