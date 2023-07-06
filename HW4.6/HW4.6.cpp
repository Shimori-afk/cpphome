#include <iostream>

enum class Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main() {
	int monthNumber;

	std::cout << "Enter number of month: ";
	std::cin >> monthNumber;

	Month month = static_cast<Month>(monthNumber);

	std::string season;

	switch (month) {
	case Month::December:
	case Month::January:
	case Month::February:
		season = "Winter";
		break;

	case Month::March:
	case Month::April:
	case Month::May:
		season = "Spring";
		break;

	case Month::June:
	case Month::July:
	case Month::August:
		season = "Summer";
		break;

	case Month::September:
	case Month::October:
	case Month::November:
		season = "Autumn";
		break;

	default:
		season = "Unknown number of month";
		break;
	}

	std::cout << season << std::endl;

	return 0;
}
