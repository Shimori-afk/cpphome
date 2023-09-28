#include "Hw25.h"

int main()
{
    Vector2d testVec{ 1.2, 5.6 };

    std::cout << testVec << std::endl;

    Vector2d vec1{ 3.0, 4.0 };
    Vector2d vec2{ 1.0, 2.0 };

    Vector2d sum = vec1 + vec2;
    Vector2d diff = vec1 - vec2;

    Vector2d vec{ 2.0f, 3.0f };
    vec.scale(2.0f, 0.5f);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;

    std::cout << "Length of vec1: " << vec1() << std::endl;

    std::cout << "Vector components: " << vec1[0] << ", " << vec1[1] << std::endl;

    std::cout << "Scaled vector: " << vec << std::endl;
    std::cin >> testVec;
    std::cout << "You entered: " << testVec << std::endl;

    return 0;
}

