/*
 * =====================================================================================
 *
 *       Filename:  ValidParentheses.cpp
 *
 *    Description: https://leetcode.com/problems/valid-parentheses/ 
 *
 *        Version:  1.0
 *        Created:  14/07/2020 14:53:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <set>
#include <map>
#include <stack>
#include <iostream>

bool isValid(std::string s)
{
    std::map<char, char> brackets;
    brackets['('] = ')';
    brackets['['] = ']';
    brackets['{'] = '}';
    std::stack<char> expected;
    

    for (char& c: s)
    {
        if (brackets.find(c) != brackets.end())
            expected.push(brackets[c]);
        else if (expected.empty() || expected.top() != c)
            return false;
        else
            expected.pop();
    }
    return expected.empty();
}

int main(void)
{
    std::cout << isValid("()") << std::endl;
    std::cout << isValid("()[]{}") << std::endl;
    std::cout << isValid("(]") << std::endl;
    std::cout << isValid("([)]") << std::endl;
    std::cout << isValid("{[]}") << std::endl;
    return 0;
}
