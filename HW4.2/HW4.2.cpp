#include <iostream>

int main()
{
	int num1, num2;
	std::cout << "Enter your numbers: ";
	std::cin >> num1 >> num2;

	const int min = num1 < num2 ? num1 : num2;
	std::cout << "Minimal number: " << min;
}

