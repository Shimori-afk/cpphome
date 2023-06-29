#include <iostream>

int main()
{
	float a, b, c;
	bool compare1_2, compare2_3;

	std::cout << "Enter your numbers:";
	std::cin >> a >> b >> c;

	compare1_2 = a == b;
	compare2_3 = b == c;

	std::cout << "Sum of numbers: " << a + b + c << std::endl;

	std::cout << "Sum of numbers: " << a * b * c << std::endl;

	std::cout << "Avg: " << (a + b + c) / 3.0 << std::endl;

	std::cout << "Compare1_2: " << std::boolalpha << compare1_2 << std::endl;
	std::cout << "Compare2_3: " << std::boolalpha << compare2_3 << std::endl;

}