#include <iostream>
#include <cctype>

int main() 
{
	char symbol;
	int digitSum = 0;

	while (true)
	{
		std::cout << "Enter your element (To exit, push '.'): ";
		std::cin >> symbol;

		if (symbol == '.')
		{
			std::cout << "Program end." << std::endl;
			break;
		}
		else if (islower(symbol)) 
		{
			char upperCaseSymbol = toupper(symbol);
			std::cout << "From lowercase symbol to uppercase: " << upperCaseSymbol << std::endl;
		}
		else if (isdigit(symbol)) 
		{
			int digit = symbol - '0';
			digitSum += digit;
			std::cout << "Sum of current numbers: " << digitSum << std::endl;
		}
		else if (isupper(symbol))
		{
			std::cout << "This symbol is upper case and unavailable in this programm!" << std::endl;
		}
		else
		{
			std::cout << "This symbol doesn't work in this program!" << std::endl;
		}
	}

	return 0;
}
