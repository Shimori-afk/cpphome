#include <iostream>
#include <string>

int main() {
    int monthNumber;

    std::cout << "Enter the month number (1-12): ";
    std::cin >> monthNumber;

    if (monthNumber >= 1 && monthNumber <= 12) {
        std::string season;

        switch (monthNumber) {
        case 12:
        case 1:
        case 2:
            season = "Winter";
            break;
        case 3:
        case 4:
        case 5:
            season = "Spring";
            break;
        case 6:
        case 7:
        case 8:
            season = "Summer";
            break;
        case 9:
        case 10:
        case 11:
            season = "Autumn";
            break;
        }

        std::cout << "The corresponding season is: " << season << std::endl;
    }
    else {
        std::cout << "Invalid month number!" << std::endl;
    }

    return 0;
}
