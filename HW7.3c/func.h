#pragma once
#include <iostream>

void printNaturalNumbers(int count)
{
	if (count == 0) {
		return;
	}
	else
	{
		std::cout << count << " ";
		printNaturalNumbers(count - 1);
	}
}

void printNaturalNumbers1(int count)
{
	if (count == 0)
	{
		return;
	}
	else
	{
		printNaturalNumbers1(count - 1);
		std::cout << count << " ";
	}
}
