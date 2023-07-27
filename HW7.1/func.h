#pragma once
#include <iostream>

int count_Numbers(int count)
{
	int c_positive = 0;
	int c_zero = 0;
	int c_negative = 0;
	int temp;



	for (int i = 0; i < count; ++i)
	{
		std::cout << "Elements is: ";
		std::cin >> temp;

		if (temp > 0)
		{
			++c_positive;
		}
		else if (temp == 0)
		{
			++c_zero;
		}
		else
		{
			++c_negative;
		}
	}
	std::cout << "Resutl: " << std::endl;
	std::cout << "Count of positive numbers: " << c_positive << std::endl;
	std::cout << "Count of numbers equal zero: " << c_zero << std::endl;
	std::cout << "Count of negative numbers: " << c_negative << std::endl;

	return 1;
}