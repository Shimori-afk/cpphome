#include <iostream>
#include <cctype>
int main() {
    char symbol;
    int digitSum = 0;

    while (true) {
        std::cout << "Enter your element (To exit push'.'): ";
        std::cin >> symbol;

        if (symbol == '.') {
            std::cout << "Programm end." << std::endl;
            break;
        }
        else if (islower(symbol)) {
            char upperCaseSymbol = toupper(symbol);
            std::cout << "From lowercase symbol to Uppercase: " << upperCaseSymbol << std::endl;
        }
        else if (isdigit(symbol)) {
            int digit = symbol - '0';
            digitSum += digit;
            std::cout << "Sum of current numbers: " << digitSum << std::endl;
        }
        else {
            std::cout << "This symbol don't work in this programm!" << std::endl;
        }
    }

    return 0;
}
