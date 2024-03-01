#pragma once
#include <iostream>
#include <cmath>

class Vector2d
{
private:
    float x;
    float y;

public:

    Vector2d(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    Vector2d(float x0, float y0, float x1, float y1) : x(x1 - x0), y(y1 - y0) {}

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

    float dotProduct(const Vector2d& other) const
    {
        return x * other.x + y * other.y;
    }

    Vector2d crossProduct(const Vector2d& other) const
    {
        return Vector2d(0.0f, 0.0f, x * other.y, y * other.x);
    }

    Vector2d negate() const
    {
        return Vector2d(-x, -y);
    }

    void scale(float factorX, float factorY)
    {
        x *= factorX;
        y *= factorY;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);
    friend std::istream& operator>>(std::istream& is, Vector2d& vec);
};
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