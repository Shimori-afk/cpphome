#include <iostream>
#include <cmath>

class Vector2d 
{
private:
    float x;
    float y;

public:
    Vector2d(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2d& operator=(const Vector2d& other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Vector2d operator+(const Vector2d& secondVector) const
    {
        return Vector2d(x + secondVector.x, y + secondVector.y);
    }

    Vector2d operator-(const Vector2d& secondVector) const
    {
        return Vector2d(x - secondVector.x, y - secondVector.y);
    }

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);

    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

    float operator()() const
    {
        return std::sqrt(x * x + y * y);
    }

    float& operator[](int i)
    {
        if (i == 0) return x;
        if (i == 1) return y;
        throw std::out_of_range("Index out of range");
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);

    // Оператор вводу вектора з консолі
    friend std::istream& operator>>(std::istream& is, Vector2d& vec);
};

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vec)
{
    os << "{" << vec.x << "; " << vec.y << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2d& vec)
{
    is >> vec.x >> vec.y;
    return is;
}

int main()
{
    Vector2d testVec{1.2, 5.6};
    std::cout << testVec << std::endl;

    Vector2d vec1{3.0, 4.0};
    Vector2d vec2{1.0, 2.0};
    
    Vector2d sum = vec1 + vec2;
    Vector2d diff = vec1 - vec2;
    
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    
    std::cout << "Length of vec1: " << vec1() << std::endl;
    
    std::cout << "Vector components: " << vec1[0] << ", " << vec1[1] << std::endl;
    
    std::cin >> testVec;
    std::cout << "You entered: " << testVec << std::endl;

    return 0;
}
