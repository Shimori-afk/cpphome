#include "func.h"

int main()
{
	int count;
	std::cout << "Enter a number: ";
	std::cin >> count;

	int factorial = factorialRecursive(count);

	std::cout << count << "! = " << factorial << std::endl;
}