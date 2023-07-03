#include <iostream>

int main() {
    int month;

    std::cout << "Enter number of month: ";
    std::cin >> month;

    std::string season;

    switch (month) {
    case 1:
    case 2:
    case 12:
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
    default:
        season = "Unknown number of month";
        break;
    }

    std::cout << season << std::endl;

    return 0;
}
