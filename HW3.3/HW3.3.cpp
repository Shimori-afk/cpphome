#include <iostream>

int main()
{
	int number1, number2;
	bool lessThen, equal, moreThen, lessOrEqual;

	std::cout << "Enter your numbers: ";
	std::cin >> number1 >> number2;

	lessThen = number1 < number2;
	equal = number1 == number2;
	moreThen = number1 > number2;
	lessOrEqual = number1 <= number2;

	std::cout << "lessThen: " << std::boolalpha << lessThen << std::endl;
	std::cout << "equal: " << std::boolalpha << equal << std::endl;
	std::cout << "moreThen: " << std::boolalpha << moreThen << std::endl;
	std::cout << "lessOrEqual: " << std::boolalpha << lessOrEqual << std::endl;

}