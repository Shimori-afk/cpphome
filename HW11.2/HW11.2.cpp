#include <iostream>

enum class SortingDirection 
{ 
	ByRows,
	ByColumn 
};

const int COLUMN = 5; 

void quickSort(int arr[], int low, int high)
 {
    if (low < high)
     {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) 
        {
            if (arr[j] < pivot)
             {
                i++;
               std::swap(arr[i], arr[j]);
             }
        }
       std::swap(arr[i + 1], arr[high]);

        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void sort2D(int arr[][COLUMN], int rows, SortingDirection direction)
{
    if (direction == SortingDirection::ByRows)
	{
        for (int i = 0; i < rows; i++)
		{
            quickSort(arr[i], 0, COLUMN - 1);
        }
    } else if (direction == SortingDirection::ByColumn)
		{
        for (int j = 0; j < COLUMN; j++) 
		{
            int column[COLUMN];
            for (int i = 0; i < rows; i++) 
			{
                column[i] = arr[i][j];
            }

            quickSort(column, 0, rows - 1);

            for (int i = 0; i < rows; i++) 
			{
                arr[i][j] = column[i];
            }
        }
    }
}

void printArray(int arr[][COLUMN], int rows)
{
    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < COLUMN; j++)
		{
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int ROWS = 4;
    int arr[ROWS][COLUMN] = {
        {5, 2, 9, 3, 1},
        {8, 4, 7, 6, 0},
        {3, 1, 2, 9, 5},
        {6, 7, 2, 4, 8}
    };

    std::cout << "Original Array:" << std::endl;
    printArray(arr, ROWS);

    sort2D(arr, ROWS, SortingDirection::ByRows);

    std::cout << "\nArray sorted by rows (in ascending order):" << std::endl;
    printArray(arr, ROWS);

    sort2D(arr, ROWS, SortingDirection::ByColumn);

    std::cout << "\nArray sorted by columns (in ascending order):" << std::endl;
    printArray(arr, ROWS);

    return 0;
}
