#pragma once
#include <iostream>

int facotrialLoop(int count)
{
	int result = 1;

	for (int i = 1; i <= count; ++i)
	{
		result *= i;
	}

	return result;
}