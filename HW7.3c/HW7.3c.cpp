#include "func.h"

int main()
{
	int count;
	std::cout << "Enter the count of natural numbers: ";
	std::cin >> count;

	printNaturalNumbers(count);
	std::cout << std::endl;

	printNaturalNumbers1(count);
	std::cout << std::endl;

	return 0;
}
