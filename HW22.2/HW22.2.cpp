#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

std::string mostOccuredWord(const std::string& line) {
    std::unordered_map<std::string, int> wordCount;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {

        wordCount[word]++;
    }

    std::string mostFrequentWord;
    int maxCount = 0;

    for (const auto& pair : wordCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    return mostFrequentWord;
}

int main() {
    std::string input = "This is a test. This is only a test. Test!";
    std::string result = mostOccuredWord(input);
    std::cout << "Most frequent word: " << result << std::endl;
    return 0;
}
