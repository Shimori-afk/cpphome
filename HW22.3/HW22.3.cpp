#include <iostream>
#include <stack>
#include <string>

bool areBracketsBalanced(const std::string& str)
{
    std::stack<char> bracketsStack;

    for (char ch : str) 
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            bracketsStack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') 
        {
            if (bracketsStack.empty()) 
            {
                return false;
            }

            char openBracket = bracketsStack.top();
            bracketsStack.pop();

            if ((ch == ')' && openBracket != '(') ||
                (ch == ']' && openBracket != '[') ||
                (ch == '}' && openBracket != '{')) 
            {
                return false;
            }
        }
    }

    return bracketsStack.empty();
}

int main() 
{
    std::string input1 = "{ [()][ ] }()";
    std::string input2 = "[{]}";

    if (areBracketsBalanced(input1))
    {
        std::cout << "Input 1 is balanced." << std::endl;
    }
    else 
    {
        std::cout << "Input 1 is not balanced." << std::endl;
    }

    if (areBracketsBalanced(input2)) 
    {
        std::cout << "Input 2 is balanced." << std::endl;
    }
    else
    {
        std::cout << "Input 2 is not balanced." << std::endl;
    }

    return 0;
}
