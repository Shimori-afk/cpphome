#include <iostream>


void toUppercase(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
		}
		++i;
	}
}

int main()
{
	const int sizeMax = 100;
	char str[sizeMax];

	std::cout << "Enter some text: ";
	std::cin.getline(str, sizeMax);

	toUppercase(str);

	std::cout << "New string: " << str << std::endl;


}