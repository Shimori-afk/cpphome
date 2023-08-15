#include <iostream>
#include <array>

void ColsSearch(int array[][4], int rows, int cols)
{
    for (int j = cols - 1; j >= 0; --j)
    {
        for (int i = 0; i < rows; ++i)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void RowsSearch(int array[][4], int rows, int cols)
{
    for (int i = rows - 1; i >= 0; --i)
    {
        for (int j = cols - 1; j >= 0; --j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int rows = 3;
    const int cols = 4;
    int array2d[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::cout << "ColsSearch:" << std::endl;
    ColsSearch(array2d, rows, cols);

    std::cout << std::endl;

    std::cout << "RowsSearch (Bottom to Top):" << std::endl;
    RowsSearch(array2d, rows, cols);

    return 0;
}
