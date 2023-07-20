#pragma once
#include <iostream>

int factorialRecursive(int count)
{
	if (count == 0)
	{
		return 1;
	}
	else
		return count * factorialRecursive(count - 1);

}

int factorialLoop(int count)
{
	int result = 1;

	for (int i = 1; i <= count; ++i)
	{
		result *= i;
	}

	return result;
}