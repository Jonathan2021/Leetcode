/*
 * =====================================================================================
 *
 *       Filename:  IntegerToRoman.cpp
 *
 *    Description: https://leetcode.com/problems/integer-to-roman/ 
 *
 *        Version:  1.0
 *        Created:  06/25/20 11:29:50
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

std::string intToRoman(int num)
{
    std::string roman("");
    int slices[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string roman_slices[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; num && i < 13; ++i)
    {
        int times = num / slices[i];
        while (times--)
        {
            roman += roman_slices[i];
            num -= slices[i];
        }
    }
    return roman;
}


int main(void)
{
    std::cout << intToRoman(1) << std::endl;
    std::cout << intToRoman(3) << std::endl;
    std::cout << intToRoman(4) << std::endl;
    std::cout << intToRoman(9) << std::endl;
    std::cout << intToRoman(58) << std::endl;
    std::cout << intToRoman(1994) << std::endl;
    return 0;
}
