#pragma once
#include <iostream>

void printNaturalNumbers(int count)
{
	for (int i = count; i >= 0; --i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void printNaturalNumbers1(int count)
{
	for (int i = 0; i <= count; ++i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}