#include <iostream>

int main()
{
	int num1, num2, num3;
	std::cout << "Enter your numbers: ";
	std::cin >> num1 >> num2 >> num3;
	int max = num1;
	
	if (num2 > max)
	{
		max = num2;
	}

	if (num3 > max)
	{
		max = num3;
	}

	std::cout << "Max number: " << max;
}

