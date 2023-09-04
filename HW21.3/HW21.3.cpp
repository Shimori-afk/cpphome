#include <iostream>
#include <algorithm>
#include <vector>


unsigned int CountDivisibleBy(const std::vector<int>& vec, int number)
{

	return std::count_if(vec.begin(), vec.end(), [number](int value) {return  value % number == 0; });
	

}

int main()
{
	std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const int divisor = 3;

	unsigned int count = CountDivisibleBy(numbers, divisor);

	std::cout << "Number of elements divisible by " << divisor << ": " << count << std::endl;

}

