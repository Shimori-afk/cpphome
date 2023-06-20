#include <iostream>

int main()
{
	int a;
	int b;
	int temp;

	std::cout << "Enter first number: ";
	std::cin >> a;
	std::cout << "Enter first number: ";
	std::cin >> b;

	temp = a;
	a = b;
	b = temp;

	std::cout << "Enter first changed number: " << a << std::endl;
	std::cout << "Enter first changed number: " << b << std::endl;


}