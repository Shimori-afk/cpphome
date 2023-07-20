#include<iostream>

bool find(const int* arr, int size, int elem)
{
	const int* end = arr + size;
	while (arr < end)
	{
		if (*arr == elem)
		{
			return true;
		}
		++arr;
	}
	return false;
}

int main()
{
	const int size = 5;
	int myArray[size] = { 1, 3, 5, 7, 9 };
	int searchElement = 5;

	if (find(myArray, size, searchElement)) 
	{
		std::cout << "Element " << searchElement << " is found in the array." << std::endl;
	}
	else
	{
		std::cout << "Element " << searchElement << " is not found in the array." << std::endl;
	}
}