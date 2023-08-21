#include <iostream>

class Rectangle
{
private:
    float lenght;
    float height;
    
public:
    Rectangle() : lenght(0.0), height(0.0){}

    Rectangle(float lenght, float height) : lenght(lenght), height(height){}

    const float getArea() 
    {
        return height * lenght;
      
    }

   const float getPerimeter() 
    {
        return 2 * (height + lenght);

    }
    void printArea()
    {
        std::cout << " Area = " << getArea() << std::endl;
    }
    void printPerimeter()
    {
        std::cout << " Perimetr = " << getPerimeter() << std::endl;
    }


};

int main()
{

    Rectangle rectangle;
    rectangle.printArea();
    rectangle.printPerimeter();

    Rectangle rectangle1(5.0, 10.0);
    rectangle1.printArea();
    rectangle1.printPerimeter();

    }