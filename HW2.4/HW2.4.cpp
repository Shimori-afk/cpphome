#include <iostream>

enum class Mounth
{
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thursday = 4,
	Friday = 5,
	Saturday = 6,
	Sunday = 7,

};

int main()
{
	Mounth Mon = Mounth::Monday;
	std::cout << int(Mon) << std::endl;

	Mounth Tues = Mounth::Tuesday;
	std::cout << int(Tues) << std::endl;

	Mounth Wed = Mounth::Wednesday;
	std::cout << int(Wed) << std::endl;

	Mounth Thur = Mounth::Thursday;
	std::cout << int(Thur) << std::endl;

	Mounth Fri = Mounth::Friday;
	std::cout << int(Fri) << std::endl;

	Mounth Satu = Mounth::Saturday;
	std::cout << int(Satu) << std::endl;

	Mounth Sun = Mounth::Sunday;
	std::cout << int(Sun) << std::endl;


}