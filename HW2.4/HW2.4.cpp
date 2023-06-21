#include <iostream>

enum class Week
{
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thursday = 4,
	Friday = 5,
	Saturday = 6,
	Sunday = 7

};

int main()
{
	Week Mon = Week::Monday;
	std::cout << int(Mon) << std::endl;

	Week Tues = Week::Tuesday;
	std::cout << int(Tues) << std::endl;

	Week Wed = Week::Wednesday;
	std::cout << int(Wed) << std::endl;

	Week Thur = Week::Thursday;
	std::cout << int(Thur) << std::endl;

	Week Fri = Week::Friday;
	std::cout << int(Fri) << std::endl;

	Week Satu = Week::Saturday;
	std::cout << int(Satu) << std::endl;

	Week Sun = Week::Sunday;
	std::cout << int(Sun) << std::endl;


}