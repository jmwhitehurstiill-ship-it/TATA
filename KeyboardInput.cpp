 // this GetAsyncKeyState cannot be used with raylib for games because when you click off the window it will work even if the game window is not focused! i.e Try clicking off the window and pressing 'G' but raylib input only works for ther game window


#include <iostream>

// Include the correct header based on the OS
#ifdef _WIN32
	#include <Windows.h> // We still need this for GetAsyncKeyState, Sleep
#else
	#include <unistd.h>
#endif

int main()
{
	std::cout << "Monitoring for SPACEBAR and ESC key presses..." << std::endl;
	std::cout << "Press SPACE to shoot. Hold ESC to quit." << std::endl;

	// This is our simple "game loop". It runs forever until we exit.
	while (true) {
		// Check if the ESC is currently held down.
		// The 0x8000 check is to see the "most significant bit", which means the key is pressed right now
		if (GetAsyncKeyState(VK_ESCAPE) & 0X8000) {
			std::cout << "ESC pressed. Exiting." << std::endl;
			break;
		}

		// Check if the SPACE key is pressed.
		// VK_SPACE is a "virtual key code" for the spacebar.
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			std::cout << "PEW! Shot fired!" << std::endl;
		}
	}
	// This is use to clear the screen
	std::system("cls");

	std::cout << "Sleeping for 5000 milliseconds...\n";

	#ifdef _WIN32
		Sleep(5000); // Sleep for 5000 milliseconds (5 seconds)
	#else
		sleep(5000);
	#endif

	std::cout << "Awake now!\n";



	return 0;
}