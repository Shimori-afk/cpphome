#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

unsigned int countDivisibleBy(const std::vector<int>& vec, int number)
{
    return 0; //#TODO: Implement and test
}

//#TODO: Find out what's wrong
std::function<std::string()> makeLambda()
{
    const std::string val = "string";
    return [/*&*/val] {return val; };
}

int main()
{
    auto bad = makeLambda();
    std::cout << bad();
}
