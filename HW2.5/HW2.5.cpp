#include <iostream>
#include <iomanip>

int main()
{

    int number;

    std::cout << "Enter your number: ";
    std::cin >> number;

    bool boolValue = bool(number);

    std::cout << std::boolalpha << "Value bool: " << boolValue << std::endl;

}
