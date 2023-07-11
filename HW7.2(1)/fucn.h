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