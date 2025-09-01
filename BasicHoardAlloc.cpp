#include <iostream>     // For input and outpur i.e cin, cout, cerr;
#include <vector>       // For vector
#include <string>       // For string
#include <cstdlib>      // For rand()
#include <ctime>        // For time()

using namespace std;

#define EXIT_SUCCESS 0

// This function will add a character to a random block in main vector
void simulate_allocation(vector<vector<char>>& hoard)
{
	if (hoard.empty()) {
		cout << "[ALLOCATE] Hoard is empty, cannot allocate!" << endl;
		return;
	};
	size_t random_index = rand() % hoard.size();
	hoard[random_index].push_back('X');
	cout << "[ALLOCATE] 'X' in block " << random_index << ". Block size is now: " << hoard[random_index].size() << endl;
	
}

// This function will remove a character from a random block
void simulate_deallocation(vector<vector<char>>& hoard)
{
	if (hoard.empty())
	{
		cout << "[DEALLOCATE] Hoard is empty, cannot deallocate!" << endl;
		return;
	};
	size_t random_index = rand() % hoard.size();
	if (!hoard[random_index].empty()) {
		hoard[random_index].pop_back();
		cout << "[DEALLOCATE] 'X' in block " << random_index << ". Block size is now: " << hoard[random_index].size() << endl;
	} else {
		cout << "[DEALLOCATE] Hoard block " << random_index << " is already empty!" << endl;
	}
}


int main()
{
	// Seed the random generator: This ensure different random number everytime program runs
	srand(time(0));

	// Create the hoard with 3 empty blocks
	vector<vector<char>> v(3);
	cout << "==== The Hoard has been activated! ====" << endl;
	for (size_t i = 0; i <= 5; ++i)
	{
		if (rand() % 2 == 0)
		{
			simulate_allocation(v);
		} else {
			simulate_deallocation(v);
		}
	}
	cout << "==== The Hoard has been deactivated! ====" << endl;
	return EXIT_SUCCESS;
}
