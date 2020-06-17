/*
 * =====================================================================================
 *
 *       Filename:  ZigZagConversion.cpp
 *
 *    Description: https://leetcode.com/problems/zigzag-conversion/ 
 *
 *        Version:  1.0
 *        Created:  17/06/2020 13:15:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <string>
#include <iostream>

std::string convert(std::string s, int numRows)
{
    if (numRows < 1)
        return "";
    if (numRows == 1)
        return s;
    std::string res = "";
    long unsigned int bigstep = 2 * numRows - 2;
    long unsigned int additionalIndex = 0;
    for (long unsigned int i = 0; (int)i < numRows; ++i)
    {
        for (long unsigned int j = i; j < s.size(); j += bigstep)
        {
            res += s[j];
            if (j % (numRows - 1) && 
                    (additionalIndex = 
                     (j + 2 * ( (numRows - 1)  - j % (numRows - 1)))) < s.size())
                res += s[additionalIndex];
        }
    
    }
    return res;
}

int main(void)
{
    std::cout << convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << convert("PAYPALISHIRING", 4) << std::endl;
    return 0;
}
