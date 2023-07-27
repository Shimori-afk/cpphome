#include <iostream>
<<<<<<< HEAD

bool isEqual(const char str1[], const char str2[])
{
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; ++i)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
=======
#include <string>

bool isEqual(const char str1[], const char str2[])
{
	if (strlen(str1) != strlen(str2))
	{
		return false;
	}
	return true;
>>>>>>> 5d8393bfb83edc69d93fe8bb98694a93090a2d1f
}

int main()
{
<<<<<<< HEAD
    const char str1[] = "abc";
    const char str2[] = "abcde";
    const char str3[] = "abc";

    bool result1 = isEqual(str1, str2);
    bool result2 = isEqual(str1, str3);

    std::cout << "Result 1: " << (result1 ? "Equal" : "Not equal") << std::endl;
    std::cout << "Result 2: " << (result2 ? "Equal" : "Not equal") << std::endl;

    return 0;
}

=======
	const char str1[] = "abc";
	const char str2[] = "abcde";
	const char str3[] = "abc";

	bool result1 = isEqual(str1, str2);
	bool result2 = isEqual(str1, str3);

	std::cout << "Result 1: " << (result1 ? "Equal" : "Not equal") << std::endl;
	std::cout << "Result 2: " << (result2 ? "Equal" : "Not equal") << std::endl;

	return  0;
}
>>>>>>> 5d8393bfb83edc69d93fe8bb98694a93090a2d1f
