#include <iostream>
#include <iomanip>

int main() {
    double number = 2453.53528;


    std::cout << "2 characters after dot: " << std::fixed << std::setprecision(2) << number << std::endl;
    std::cout << "5 characters after dot: " << std::fixed << std::setprecision(5) << number << std::endl;
    std::cout << "10 characters after dot: " << std::fixed << std::setprecision(10) << number << std::endl;

    std::cout << "Normal: " << std::defaultfloat << number << std::endl;
    std::cout << "E-type: " << std::scientific << number << std::endl;

    
}
