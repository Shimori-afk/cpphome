#include "DynamicIntArray.h"
using namespace std;
DynamicIntArray::DynamicIntArray() : array(nullptr), arraySize(0), capacity(0) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : array(new int[size]), arraySize(size), capacity(size) {}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : array(new int[other.arraySize]), arraySize(other.arraySize), capacity(other.arraySize)
{
    for (std::size_t i = 0; i < arraySize; ++i) {
        array[i] = other.array[i];
    }
}

DynamicIntArray::~DynamicIntArray()
{
    delete[] array;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
    if (this != &other) {
        delete[] array;
        arraySize = other.arraySize;
        capacity = other.arraySize;
        array = new int[arraySize];
        for (std::size_t i = 0; i < arraySize; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

int& DynamicIntArray::operator[](std::size_t index)
{
    if (index > arraySize) {
       throw out_of_range("Index out of range");
    }
    return array[index];
}

void DynamicIntArray::setSize(std::size_t newSize)
{
    if (newSize > capacity) {
        resize(newSize);
    }
    arraySize = newSize;
}

std::size_t DynamicIntArray::getSize() const
{
    return arraySize;
}

void DynamicIntArray::clear()
{
    delete[] array;
    array = nullptr;
    arraySize = 0;
    capacity = 0;
}

void DynamicIntArray::push_back(int element)
{
    if (arraySize >= capacity) {
        resize(capacity * 2);
    }
    array[arraySize++] = element;
}

void DynamicIntArray::resize(std::size_t newCapacity)
{
    int* newArray = new int[newCapacity];
    for (std::size_t i = 0; i < arraySize; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}
