#include <iostream>
#include <string>
#include <stack>
#include <map>

bool isValid(std::string s)
{
    std::map<char, char> bracketPairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    std::stack<char> stack;

    for (char ch : s) {
        if (bracketPairs.find(ch) != bracketPairs.end()) {
            if (stack.empty() || stack.top() != bracketPairs[ch]) {
                return false;
            }
            stack.pop();
        } else {
            stack.push(ch);
        }
    }

    return stack.empty();
}

int main()
{
    std::string s;
    getline(std::cin, s);
    if (isValid(s))
        std::cout << "String is valid" << std::endl;
    else
        std::cout << "String is invalid" << std::endl;
}