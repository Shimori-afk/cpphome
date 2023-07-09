#include <iostream>

int main()
{
	char a = '*';
	int n;
	int loop;
	std::cout << "Enter n number: ";
	std::cin >> n;
	std::cout << "Enter num of case[1, 2, 3, 4]: ";
	std::cin >> loop;

	switch (loop)
	{
	case 1:
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i > j || i == j)
				{
					std::cout << a;
				}
			}
			std::cout << std::endl;
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i < j || i == j)
				{
					std::cout << a;
				}
			}
			std::cout << std::endl;
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << a;
			}
			std::cout << std::endl;
		}
		break;
	}
	case 4:
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				std::cout << ((i + j) % 2);
			}
			std::cout << std::endl;
		}
		break;
	}
	default:
		std::cout << "Invalid variable!" << std::endl;
	}
}