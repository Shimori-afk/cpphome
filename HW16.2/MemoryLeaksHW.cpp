#include <iostream>
#include <cstring>

class StringCustom {
public:
    StringCustom();
    StringCustom(const char* c_str);
    StringCustom& operator=(const char* c_str);
    void assign(const char* c_str);

    ~StringCustom() { delete[] m_str; }

    std::size_t getLen() const { return strlen(m_str); }
    std::size_t getSize() const { return getLen() + 1; }
private:
    char* m_str;

};

StringCustom::StringCustom()
{
    m_str = new char[1];
    m_str[0] = '\0';
}

StringCustom::StringCustom(const char* c_str)
{
    if (c_str == nullptr)
    {
        m_str = new char[1];
        m_str[0] = '\0';
    }
    else
    {
        const std::size_t size = strlen(c_str);
        m_str = new char[size];
        
        for (int i = 0; i <= size; i++)
        {
            m_str[i] = c_str[i];
        }
    }
}

StringCustom& StringCustom::operator=(const char* c_str)
{
    if (c_str == nullptr)
    {
        delete[] m_str;
        m_str = new char[1];
        m_str[0] = '\0';
    }
    else
    {
        const std::size_t size = strlen(c_str);
        delete[] m_str;
        m_str = new char[size + 1];  
        
        for (int i = 0; i <= size; i++)
        {
            m_str[i] = c_str[i];
        }
    }

    return *this;
}

void StringCustom::assign(const char* c_str)
{
    delete[] m_str;
    m_str = new char[strlen(c_str) + 1];
    strcpy(m_str, c_str);
}

int* allocateArray(int size)
{
    int* arrayInt = new int[size];
    return arrayInt;
}

void clearArray(int* numbers)
{
    delete[] numbers;
}

int** allocateArrayOfArrays(int rows, int columns)
{
    int** arrayPtr = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        arrayPtr[i] = new int[columns];
    }

    return arrayPtr;
}

void clearArrayOfArrays(int** arrayPtr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arrayPtr[i];
    }
    delete[] arrayPtr;
}

int main()
{
    StringCustom a;
    a = "Hello";
    a = "There";

    StringCustom b;
    b.assign("Hello Here");
    b.assign("Simple hello");

    int ArraySize = 10;
    int* arrayInt = allocateArray(ArraySize);
    clearArray(arrayInt);

    int rows = 10;
    int columns = 20;
    int** array = allocateArrayOfArrays(rows, columns);
    clearArrayOfArrays(array, rows);

    return 0;
}
