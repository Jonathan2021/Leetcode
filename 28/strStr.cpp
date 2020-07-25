/*
 * =====================================================================================
 *
 *       Filename:  strStr.cpp
 *
 *    Description: https://leetcode.com/problems/implement-strstr/ 
 *
 *        Version:  1.0
 *        Created:  07/25/20 12:04:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), misterjonathansands@gmail.com
 *        Company:  none
 *
 * =====================================================================================
 */
#include <string>
#include <iostream>

int strStr(std::string haystack, std::string needle)
{
     if (!needle.size())
            return 0;
     if (needle.size() > haystack.size())
         return -1;
    for (size_t i = 0; i < haystack.size() - needle.size() + 1; ++i)
    {
        size_t j = 0;
        for (; j < needle.size() && haystack[i + j] == needle[j]; ++j);
        if (j == needle.size())
            return i;
    }
    return -1;        
}

// better solution : http://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm

int main(void)
{
    std::cout << strStr("hello", "ll") << std::endl;
    std::cout << strStr("aaaaaa", "bba") << std::endl;
    std::cout << strStr("att", "tt") << std::endl;
    std::cout << strStr("a", "a") << std::endl;
    return 0;
}
