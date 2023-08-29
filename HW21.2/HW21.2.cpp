#include <iostream>
#include <vector>
#include <algorithm>

//sortByFunc
bool compareByLength(std::string& str1, std::string str2)
{
	return str1.size() < str2.size();

}

//sortByFunctor
class LengthComparator
{
public:
	bool operator()(const std::string& str1, std::string& str2)
	{
		return str1.size() < str2.size();
	}
};

int main()
{

	std::vector<std::string> stringContainer
	{
			"Miracle",
			"Heckfy",
			"Yatoro",
			"Witchblvde",
			"Zitraks",
			"Shigetsu"
	};

	// sortByLambda;
	std::sort(stringContainer.begin(), stringContainer.end(),
		[](std::string& str1, std::string& str2)
		{
			return str1.size() < str2.size();
		});

	for (const std::string& str : stringContainer)
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;


	std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);

	for (const std::string& str : stringContainer)
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;


	std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());

	for (const std::string& str : stringContainer)
	{
		std::cout << str << " ";
	}

}

