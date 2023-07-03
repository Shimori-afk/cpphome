#include <iostream>

int main()
{
	int num1, num2;
	int min;
	std::cout << "Enter your numbers: ";
	std::cin >> num1 >> num2;
	min = num1 < num2 ? num1 : num2;

	std::cout << "Minimal number: " << min;
}

