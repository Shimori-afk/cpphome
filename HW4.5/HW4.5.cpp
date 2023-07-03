#include <iostream>

enum class Month
{
    January,
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

int main() 
{
    int monthNumber;

    std::cout << "Enter number of the month: ";
    std::cin >> monthNumber;

    if (monthNumber >= 1 && monthNumber <= 12)
    {
        Month month = static_cast<Month>(monthNumber - 1);

        switch (month)
        {
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
    }
    else 
    {
        std::cout << "Invalid number of month (correct 1 - 12)!!!" << std::endl;
    }

    return 0;
}
