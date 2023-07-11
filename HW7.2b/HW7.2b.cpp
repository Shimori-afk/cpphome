#include "func.h"

int main()
{
	int count;

	std::cout << "Enter a number: ";
	std::cin >> count;

	int factorial = facotrialLoop(count);

	std::cout << count << "! = " << factorial << std::endl;
}