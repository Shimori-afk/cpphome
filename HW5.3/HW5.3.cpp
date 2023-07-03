#include <iostream>

int main()
{
	int n;
	int result = 1;

	std::cout << "Enter your number: ";
	std::cin >> n;

	for (int i = 1; i < n; ++i)
	{
		result = result * i;

	std::cout << "Factorial: " << result << std::endl;
	}


}