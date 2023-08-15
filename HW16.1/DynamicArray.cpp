#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicIntArray arr(5);
    
    for (std::size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = i * 10;
    }
    
    arr.push_back(50);
    
    for (std::size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << "\n";
    
    return 0;
}
