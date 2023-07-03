#include <iostream>
int main()
{
	int  a, b, c;

	std::cout << "Enter your angle: ";
	std::cin >> a >> b >> c;

	if (a + b + c == 180)
	{
		std::cout << "Good triangle" << std::endl;
	}
	else std::cout << "It is not triangle" << std::endl;
}