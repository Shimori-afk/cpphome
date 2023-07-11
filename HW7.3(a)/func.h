#pragma once
#include <iostream>

void printNaturalNumbers(int count)
{
	for (int i = count; i >= 1; --i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
