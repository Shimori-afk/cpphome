#pragma once
#include <iostream>

void printNaturalNumbers(int count)
{
	for (int i = 0; i <= count; ++i)
	{
		std::cout << i << " " << std::endl;
	}
	std::cout << std::endl;
}