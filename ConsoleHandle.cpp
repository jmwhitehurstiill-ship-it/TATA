/*
	- Reference: https://learn.microsoft.com/en-us/windows/console/console-functions
	- Console: is a grid in rows(vertical) and columns(horizontal) i.e so when you use newline it move the operation to a new row and it print the operation on the column of that row;
	- Checking total rows and column in console; type 'mode'
		PS C:\Users\Kenne> mode

		Status for device CON:
		----------------------
			Lines:          54   <-- This is the Height (Y total) rows    (0, 54)
			Columns:        209  <-- This is the Width  (X total) column  (0, 209)
			Keyboard rate:  31
			Keyboard delay: 1
			Code page:      437
*/

#include <windows.h>
#include <iostream>

const int COLOR_RESET = 15;   // White
const int COLOR_GREEN = 10;   // Green
const int COLOR_RED = 12;     // Red
const int COLOR_DEFAULT = 7;  // Default : Grey

int main(void)
{
	std::cout << "==== Console API Demo Started ====" << std::endl;
	// Get console handle for controlling output (e.g., colors, cursor position)
	// Usage: Gets a HANDLE to the console screen for other functions like setting colors
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (stdHandle == INVALID_HANDLE_VALUE) {
		std::cerr << "GetStdHandle failed: " << GetLastError() << std::endl;
		return 1;
	}
	// Enable UTF-8 to support unicode characters like emojis (UTF-8 mode)
	SetConsoleOutputCP(65001);
	// Set the console windoW title
	SetConsoleTitle(L"Console API Demo");
	// Set text printed to console color
	SetConsoleTextAttribute(stdHandle, COLOR_RED);
	std::cout << "This text will be colour RED\n\n" << std::endl;
	// Print and color emoji and unicode character to console : Snake emoji 😊
	// {1, 3} this means print the emoji at Console : column 1 at front and row 3 ( newline 3 )
	DWORD written;
	SetConsoleTextAttribute(stdHandle, COLOR_GREEN);
	WriteConsoleOutputCharacterW(stdHandle, L"\u263A", 1, { 0, 2 }, &written);
	// Move cursor to (0, 0) position to start printing text
	// Alternative = std::system("cls");
	SetConsoleCursorPosition(stdHandle, { 0, 4 });
	// The End
	SetConsoleTextAttribute(stdHandle, COLOR_RESET);
	std::cout << "==== Console API Demo Complete ====" << std::endl;
	Sleep(5000);
	return 0;
}