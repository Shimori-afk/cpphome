#include <iostream>
#include <set>
#include <sstream>
#include <string>

unsigned int uniqueWordsCount(const std::string& line)
{
    std::set<std::string> uniqueWords;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word)
    {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}
    
int main()
{
    std::string line = "Hello Hey Hello Bye Hey";
    unsigned int count = uniqueWordsCount(line);
    std::cout << "Number of unique words: " << count << std::endl;
}