#pragma once
#include <iostream>

void printNaturalNumbers(int count)
{
	if (count == 0)
	{
		return;
	}
	else
		std::cout << count << " " << std::endl;
	printNaturalNumbers(count - 1);

}