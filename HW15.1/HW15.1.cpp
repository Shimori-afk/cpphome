#include <iostream>

class Rectangle
{
private:
    float length;
    float height;
    static int count;

public:
    Rectangle() : length(0.0), height(0.0)
    {
        count++;
    }

    Rectangle(float length, float height) : length(length), height(height)
    {
        count++;
    }

    float getArea() 
    {
        return height * length;
    }

    float getPerimeter() 
    {
        return 2 * (height + length);
    }

    void printArea()
    {
        std::cout << "Area = " << getArea() << std::endl;
    }

    void printPerimeter()
    {
        std::cout << "Perimeter = " << getPerimeter() << std::endl;
    }

    static int getCount()
    {
        return count;
    }
};

int Rectangle::count = 0;

int main()
{
    Rectangle rectangle;
    rectangle.printArea();
    rectangle.printPerimeter();

    Rectangle rectangle1(5.0, 10.0);
    rectangle1.printArea();
    rectangle1.printPerimeter();

    std::cout << "Total Rectangles created: " << Rectangle::getCount() << std::endl;

    return 0;
}