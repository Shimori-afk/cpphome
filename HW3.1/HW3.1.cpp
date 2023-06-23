#include <iostream>

int main()
{
	int totalSeconds;

	std::cout << "Enter totalSeconds: ";
	std::cin >> totalSeconds;

	int hours = totalSeconds / 3600;
	int minutes = (totalSeconds % 3600) / 60;
	int seconds = totalSeconds % 60;

	std::cout << "Hours: " << hours << std::endl;
	std::cout << "Minutes: " << minutes << std::endl;
	std::cout << "Seconds: " << seconds << std::endl;

}