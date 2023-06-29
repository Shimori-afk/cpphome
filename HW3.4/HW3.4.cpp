#include <iostream>

int main()
{
	int width, height, P, S;

	std::cout << "Enter width: ";
	std::cin >> width;

	std::cout << "Enter height: ";
	std::cin >> height;


	S = width * height;
	std::cout << "Area: S = " << S << std::endl;

	P = 2 * (width + height);
	std::cout << "Perimetr: P = " << P << std::endl;
}

