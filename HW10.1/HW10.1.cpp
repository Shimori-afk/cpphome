#include <iostream>

bool linearSearch2D(const int arr[][3], int rows, int cols, int target)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (arr[i][j] == target)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	const int rows = 3;
	const int cols = 3;

	int array[rows][cols] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int searchElement = 9;

	if (linearSearch2D(array, rows, cols, searchElement))
	{
		std::cout << "Element " << searchElement << " is found in this 2D array." << std::endl;
	}
	else
	{
		std::cout << "Element " << searchElement << " is not found in this 2D array." << std::endl;
	}
}