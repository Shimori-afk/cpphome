#include <iostream>

int main()
{
	int number;

	std::cout << "Enter your number: ";
	std::cin >> number;

	if (number % 5 == 0 && number % 11 == 0)
	{
		std::cout << "is divide";
	}
	else
		std::cout << "not divide";


}