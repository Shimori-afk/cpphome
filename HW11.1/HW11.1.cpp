#include <iostream>

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{

		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}

	}
}

int main()
{
	int arr[] = { 5, 3, 7, 21, 87, 34, 65, 10, 45, 782,98 };
	int size = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, size);

	for (int i = 0; i < size; ++i)
	{
		std::cout << " " << arr[i];
	}

}