#include <iostream>

int main()
{
	int  a, b, c;

	std::cout << "Enter your angle: ";
	std::cin >> a >> b >> c;

	if (a + b + c == 180 && a > 0 && b > 0 && c > 0)
	{
		std::cout << "Good triangle" << std::endl;
	}
	else
		std::cout << "It is not triangle" << std::endl;
}