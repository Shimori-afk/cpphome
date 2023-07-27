#include <iostream>
#include <cctype>

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) {
    vowelsCount = 0;
    consonantsCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);

        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelsCount++;
            }
            else {
                consonantsCount++;
            }
        }
    }
}

int main() {
    const char str[] = "Hello, World!";
    int vowelsCount = 0;
    int consonantsCount = 0;

    parseStringLetters(str, vowelsCount, consonantsCount);

    std::cout << "Vowels count: " << vowelsCount << std::endl;
    std::cout << "Consonants count: " << consonantsCount << std::endl;

    return 0;
}
