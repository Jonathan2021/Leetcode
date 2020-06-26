/*
 * =====================================================================================
 *
 *       Filename:  RomanToInteger.cpp
 *
 *    Description: https://leetcode.com/problems/roman-to-integer/ 
 *
 *        Version:  1.0
 *        Created:  06/26/20 12:03:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@epita.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

int RomanToInt(std::string s)
{
    int slices[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string roman_slices[] ={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int res = 0;
    size_t i = 0;;
    for (size_t j = 0; j < s.size(); ++i)
    {
        while (s.find(roman_slices[i], j) == j)
        {
            j += roman_slices[i].size();
            res += slices[i];
        }
    }
    return res;
}

int main(void)
{
    std::cout << RomanToInt("III") << std::endl;
    std::cout << RomanToInt("IV") << std::endl;
    std::cout << RomanToInt("IX") << std::endl;
    std::cout << RomanToInt("LVIII") << std::endl;
    std::cout << RomanToInt("MCMXCIV") << std::endl;
    return 0;
}
