#include <iostream>
#include <cctype>
#include <cstring>

bool isPalindrome(const char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        while (start < end && !isalnum(str[start])) 
        {
            break;
        }
        while (start < end && !isalnum(str[end])) 
        {
           break;
        }

        char char1 = tolower(str[start]);
        char char2 = tolower(str[end]);

        if (char1 != char2)
        {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int main()
{
    const char str1[] = "aba";
    const char str2[] = "--tenet";
    const char str3[] = "abba";
    const char str4[] = "teneT";
    const char str5[] = "abcd";
    const char str6[] = "abca";
    const char str7[] = "--aba";
    const char str8[] = "----";

    bool result1 = isPalindrome(str1);
    bool result2 = isPalindrome(str2);
    bool result3 = isPalindrome(str3);
    bool result4 = isPalindrome(str4);
    bool result5 = isPalindrome(str5);
    bool result6 = isPalindrome(str6);
    bool result7 = isPalindrome(str7);
    bool result8 = isPalindrome(str8);

    std::cout << "Input: " << str1 << " Output: " << (result1 ? "true" : "false") << std::endl;
    std::cout << "Input: " << str2 << " Output: " << (result2 ? "true" : "false") << std::endl;
    std::cout << "Input: " << str3 << " Output: " << (result3 ? "true" : "false") << std::endl;
    std::cout << "Input: " << str4 << " Output: " << (result4 ? "true" : "false") << std::endl;
    std::cout << "Input: " << str5 << " Output: " << (result5 ? "true" : "false") << std::endl;
    std::cout << "Input: " << str6 << " Output: " << (result6 ? "true" : "false") << std::endl;
    std::cout << "Input: " << str7 << " Output: " << (result7 ? "true" : "false") << std::endl;
    std::cout << "Input: " << str8 << " Output: " << (result8 ? "true" : "false") << std::endl;

    return 0;
}
