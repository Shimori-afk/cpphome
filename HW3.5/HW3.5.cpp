#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main()
{
	double S, C, r;

	std::cout << "Enter your radius: ";
	std::cin >> r;

	std::cout << std::endl;

	C = 2 * M_PI * r;
	std::cout << "C = " << C << std::endl;

	S = pow(r, 2) * M_PI;
	std::cout << "S = " << S << std::endl;

}