/*
 * =====================================================================================
 *
 *       Filename:  StringToInteger.cpp
 *
 *    Description: https://leetcode.com/problems/string-to-integer-atoi/ 
 *
 *        Version:  1.0
 *        Created:  06/22/20 11:21:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@epita.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <string>
#include <iostream>
#include <limits>

void remove_leading_spaces(std::string& str)
{
    size_t end = str.find_first_not_of(" ");
    end = (end > str.size()) ? str.size() : end;
    str.erase(str.begin(), str.begin() + end);
}

int myAtoi(std::string str)
{
    remove_leading_spaces(str);
    int sign = 1; 
    if (str.size() && (str[0] == '-' || str[0] == '+'))
    {
        sign *= (str[0] == '-') ? -1 : 1; 
        str.erase(str.begin());
    }
    int res = 0;
    for (long unsigned i = 0; i < str.size() && str[i] >= '0' && str[i] <= '9'; ++i)
    {
        if ((std::numeric_limits<int>::max() - (str[i] - '0')) / 10 < res)
            return (sign == -1) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
        res = res * 10 + (str[i] - '0');
    }
    return res * sign;
}

int main(void)
{
    std::cout << myAtoi("   zda") << std::endl;
    std::cout << myAtoi("    87e") << std::endl;
    std::cout << myAtoi("    -87e") << std::endl;
    std::cout << myAtoi("    -91283472332r") << std::endl;
    std::cout << myAtoi("") << std::endl;
    return 0;
}
