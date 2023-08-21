#include <iostream>

bool calculateSum(const double* arr, int arrSize, double& sum)
{
	if (arrSize <= 0)
	{
		return false;
	}

	sum = 0.0;
	for (int i = 0; i < arrSize; ++i)
	{
		sum += arr[i];
	}
	return true;
}

int main()
{
	const int size = 5;
	double myArray[size] = { 1.5, 2.3, 3.7, 4.1, 5.2 };
	double result = 0.0;

	if (calculateSum(myArray, size, result))
	{
		std::cout << "Sum of elements: " << result << std::endl;
	}
	else
	{
		std::cout << "Array is empty." << std::endl;
	}
}