#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

const char* database[] = {"HOUSE", "RANGE", "WORLD"};
const int numWords = sizeof(database) / sizeof(database[0]);

std::string getRandomWord() {
    int randomIndex = rand() % numWords;
    return database[randomIndex];
}

bool isWordGuessed(const std::string& secretWord, const std::string& guessedWord) {
    if (secretWord.length() != guessedWord.length()) {
        return false;
    }

    for (size_t i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] != guessedWord[i]) {
            return false;
        }
    }

    return true;
}

std::string getDisplayWord(const std::string& secretWord, const std::string& guessedWord) {
    std::string displayWord;

    for (size_t i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guessedWord[i]) {
            displayWord += std::toupper(secretWord[i]);
        } else {
            displayWord += '*';
        }
    }

    return displayWord;
}

std::string readWordOfTheDayFromFile() {
    std::ifstream inputFile("word_of_the_day.txt");
    std::string word;
    if (inputFile.is_open()) {
        inputFile >> word;
        inputFile.close();
    }
    return word;
}

void writeWordOfTheDayToFile(const std::string& word) {
    std::ofstream outputFile("word_of_the_day.txt");
    if (outputFile.is_open()) {
        outputFile << word;
        outputFile.close();
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::string wordOfTheDay = readWordOfTheDayFromFile();
    if (wordOfTheDay.empty()) {
        wordOfTheDay = getRandomWord();
        writeWordOfTheDayToFile(wordOfTheDay);
    }

    int attempts = 0;
    std::string guessedWord;

    std::cout << "Welcome to the Word Guessing Game!" << std::endl;

    do {
        std::cout << "Enter a word with " << wordOfTheDay.length() << " letters: ";
        std::cin >> guessedWord;
        attempts++;

        if (isWordGuessed(wordOfTheDay, guessedWord)) {
            std::cout << "Congratulations! You guessed the word in " << attempts << " attempts." << std::endl;
            writeWordOfTheDayToFile(""); // Clear the word of the day for the next day
            wordOfTheDay = getRandomWord();
            writeWordOfTheDayToFile(wordOfTheDay); // Save a new word of the day for the next round
            attempts = 0; // Reset the attempt counter
        } else {
            std::string displayWord = getDisplayWord(wordOfTheDay, guessedWord);
            std::cout << "Incorrect! Keep trying. Here's your progress: " << displayWord << std::endl;
        }
    } while (true);

    return 0;
}
