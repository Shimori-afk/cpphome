#include "func.h"

int main()
{
	int count;
	std::cout << "Enter a number: ";
	std::cin >> count;

	int factorialR = factorialRecursive(count);
	std::cout << count << "! = " << factorialR << std::endl;

	int factorialL = factorialLoop(count);
	std::cout << count << "! = " << factorialL << std::endl;
}