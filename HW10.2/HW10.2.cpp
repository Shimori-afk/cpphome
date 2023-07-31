#include <iostream>

enum class SortingDirection
{
	ascending,
	descending
};

bool isSorted(const int* arr, int size, SortingDirection direction)
{
	if (size <= 1)
	{
		return true;
	}
	if (direction == SortingDirection::ascending)
	{
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
		}
	}
	else if (direction == SortingDirection::descending)
	{
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i] < arr[i + 1])
			{
				return false;
			}

		}
	}

	return true;
}

int main()
{
	const int size = 5;
	int arr_ascending[size] = { 1, 2, 3, 4, 5 };
	int arr_descending[size] = { 5, 4, 3, 2, 1 };

	if (isSorted(arr_ascending, size, SortingDirection::ascending))
	{
		std::cout << "Array is  sorted by ascending" << std::endl;
	}
	else
	{
		std::cout << "Array isn't sorted by ascending" << std::endl;
	}

	if (isSorted(arr_descending, size, SortingDirection::descending))
	{
		std::cout << "Array is sorted by descending " << std::endl;
	}
	else
	{
		std::cout << "Array isn't  sorted by descending" << std::endl;
	}
}
