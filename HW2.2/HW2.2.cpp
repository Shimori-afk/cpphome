#include <iostream>
#include <iomanip>

int main() {
    double number = 3.14159;
    std::cout << "Value of double: " << number << std::endl;

    int intValue = int(number);
    std::cout << "Value of int: " << intValue << std::endl;

    std::cout << std::setw(20) << std::right << std::setfill('$') << std::fixed << std::setprecision(2) << number << std::endl;
}
