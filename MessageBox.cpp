#include <iostream>
#include <Windows.h>

// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox
int main() {
	// MB_ABORTRETRYIGNORE = IDABORT, IDRETRY, IDIGNORE
	// MB_YESNO            = IDYES, IDNO
	int msgBox = MessageBox(
		NULL, 
		L"Resource not available\nDo you want to try again?", 
		L"Account Details", 
		MB_YESNO
	);

	switch (msgBox) {
		case IDYES:
			std::cout << "Yes buton is clicked!" << std::endl;
			break;
		case IDNO:
			std::cout << "No buton is clicked!" << std::endl;
			break;
		case IDABORT:
			std::cout << "Abort buton is clicked!" << std::endl;
			break;
		case IDRETRY:
			std::cout << "Retry buton is clicked!" << std::endl;
			break;
		case IDIGNORE:
			std::cout << "Ignore buton is clicked" << std::endl;
			break;

	}

	SECURITY_ATTRIBUTES att = { sizeof(SECURITY_ATTRIBUTES) };

	return 0;
}