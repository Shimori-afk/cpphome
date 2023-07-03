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

    std::cout << "Enter the month number: ";
    std::cin >> monthNumber;

    Month month;

    switch (monthNumber) {
    case 1:
        month = Month::January;
        break;
    case 2:
        month = Month::February;
        break;
    case 3:
        month = Month::March;
        break;
    case 4:
        month = Month::April;
        break;
    case 5:
        month = Month::May;
        break;
    case 6:
        month = Month::June;
        break;
    case 7:
        month = Month::July;
        break;
    case 8:
        month = Month::August;
        break;
    case 9:
        month = Month::September;
        break;
    case 10:
        month = Month::October;
        break;
    case 11:
        month = Month::November;
        break;
    case 12:
        month = Month::December;
        break;
    default:
        std::cout << "Invalid month number!" << std::endl;
        return 0;
    }

    switch (month) {
    case Month::January:
        std::cout << "January" << std::endl;
        break;
    case Month::February:
        std::cout << "February" << std::endl;
        break;
    case Month::March:
        std::cout << "March" << std::endl;
        break;
    case Month::April:
        std::cout << "April" << std::endl;
        break;
    case Month::May:
        std::cout << "May" << std::endl;
        break;
    case Month::June:
        std::cout << "June" << std::endl;
        break;
    case Month::July:
        std::cout << "July" << std::endl;
        break;
    case Month::August:
        std::cout << "August" << std::endl;
        break;
    case Month::September:
        std::cout << "September" << std::endl;
        break;
    case Month::October:
        std::cout << "October" << std::endl;
        break;
    case Month::November:
        std::cout << "November" << std::endl;
        break;
    case Month::December:
        std::cout << "December" << std::endl;
        break;
    }

    return 0;
}
