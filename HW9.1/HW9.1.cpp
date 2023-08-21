#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;


}
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 5, y = 10;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

	swap(x, y);

	std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;

	int x1 = 5, y1 = 10;
	std::cout << "Before swap: x1 = " << x1 << ", y1 = " << y1 << std::endl;

	Swap(&x1, &y1);

	std::cout << "After swap: x1 = " << x1 << ", y1 = " << y1 << std::endl;


}

