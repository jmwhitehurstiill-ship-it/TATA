#include <iostream>

int factorial(int x) {
	// Base Case: This is the stopping condition for the recursion.
	// If the number is 1, the "sum" is just 1
	if (x <= 1) {
		return 1;
	}
	// Recursive Step: The function calls itself with a smaller number.
	// It adds the current number (x) to the sum of all the numbers below it.
	// Example: factorial(5) returns 5 * factorial(4) i.e  5! = 5 * 4 * 3 * 2 * 1
	else {
		return x * factorial(x - 1);
	}
}

// This function correctly calculates the sum of all integers from 1 up to k.
int summation(int k) {
	// Recursive Step: If k is greater than 0, add k to the sum of all numbers below it.
	// Example: summation(10) returns 10 + summation(9). i.e 10 + 9 + 8 + ... + 1 = 55. ...
	if (k > 0) {
		return k + summation(k - 1);
	}
	// Base Case: The essential stopping point. When k reaches 0, the recursion stops
	// and the function returns 0, ending the chain of additions.
	else {
		return 0;
	}
}

void countDown(int n) {
	if (n > 0) {
		std::cout << n << std::endl;
		countDown(n - 1);
	}
}

int main() {
	std::cout << "\n====== count down recursion =====" << std::endl;
	countDown(5);
	int number = 5;
	int result = factorial(5);
	int resultSum = summation(10);
	std::cout << "\n====== other (factorial and summation) recursion =====" << std::endl;
	std::cout << "Factorial of 5:   " << result << std::endl;
	std::cout << "Summation of 10:  " << resultSum << std::endl;
	return 0;
}