#include <iostream>

int main()
{
	double a1, d;
	int n;

	std::cout << "Enter first number: ";
	std::cin >> a1;

	std::cout << "Enter step: ";
	std::cin >> d;

	std::cout << "Enter number of the last element: ";
	std::cin >> n;

	if (n <= 0)
	{
		std::cout << "Number should be more than 0!" << std::endl;
	}
	std::cout << "Arithmetic progression: " << std::endl;
	
	for (int i = 0; i < n; ++i)
	{
		double element = a1 + i * d;
		std::cout << element << " " << std::endl;
	}
	std::cout << std::endl;
}