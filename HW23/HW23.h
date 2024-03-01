#pragma once
#include <iostream>
#include <cstdlib>

template <typename T, std::size_t MaxSize>
class InplaceArray
{
public:
    InplaceArray() : size(0) {}

    std::size_t getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == MaxSize;
    }

    void push_back(const T& element)
    {
        if (isFull())
        {
            throw std::overflow_error("Array is full");
        }
        data[size++] = element;
    }

    void pop_back()
    {
        if (!isEmpty())
        {
            --size;
        }
    }

    T& operator[](std::size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void reserve(std::size_t reservedSpace)
    {
        if (reservedSpace > MaxSize)
        {
            throw std::overflow_error("Requested capacity exceeds the maximum size");
        }
        capacity = reservedSpace;
    }

    std::size_t getCapacity() const
    {
        return capacity;
    }

    void shrinkToFit()
    {
        if (size < capacity)
        {
            capacity = size;
        }
    }

    void clear()
    {
        size = 0;
    }

private:
    T data[MaxSize];
    std::size_t size;
    std::size_t capacity;
};


