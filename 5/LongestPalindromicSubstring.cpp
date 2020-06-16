/*
 * =====================================================================================
 *
 *       Filename:  LongestPalindromicSubstring.cpp
 *
 *    Description: https://leetcode.com/problems/longest-palindromic-substring/ 
 *
 *        Version:  1.0
 *        Created:  16/06/2020 12:18:32
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

std::string longestPalindrome(std::string s)
{
    long unsigned int start = 0;
    long unsigned int  end = 1;
    for (long unsigned i = 0; s.size() - i > end - start; ++i)
    {
        for (long unsigned j = s.size() - 1; j - i >= end - start ; --j)
        {
            bool test = true;
            for (long unsigned k = 0; k < j-i && (test = (s[i + k] == s[j - k])); ++k);
            if (test)
            {
                start = i;
                end = j + 1;
                break;
            }
        }
    }
    return s.substr(start, end - start);
}

int main(void)
{
    std::cout << longestPalindrome("babad") << std::endl;
    std::cout << longestPalindrome("cbbd") << std::endl;
    std::cout << longestPalindrome("babad") << std::endl;
    return 0;
}
