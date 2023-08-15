#include <iostream>

void translateArray(int numbers[], int size)
{	
	for (int i = 0; i < 10; ++i)
	{

		if (numbers[i] > 0)
		{
			numbers[i] *= 2;
		}
		else
			numbers[i] = 0;
	}

}

int main()
{
	const int size = 10;
	int numbers[size] = {};

	std::cout << "Enter an array elements: ";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> numbers[i];
	}

	translateArray(numbers, size);

	std::cout << "New array: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}