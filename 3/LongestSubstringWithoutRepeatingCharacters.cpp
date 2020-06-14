/*
 * =====================================================================================
 *
 *       Filename:  LongestSubstringWithoutRepeatingCharacters.cpp
 *
 *    Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/ 
 *
 *        Version:  1.0
 *        Created:  14/06/2020 12:51:04
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
#include <string.h>

int lengthOfLongestSubstring(std::string s)
{
    int longest = 0;
    int current_length = 0;
    int characters[128] = {0};
    for (long unsigned int i = 0; i < s.size(); ++i)
    {
        if (characters[(int)s[i]])
        {
            longest = (current_length > longest) ? current_length : longest;
            i = characters[(int)s[i]] - 1;
            memset(characters, 0, sizeof(characters));
            current_length = 0;
        }
        else
        {
            characters[(int)s[i]] = i + 1;
            current_length += 1;
        }
    }
    return (longest > current_length) ? longest : current_length;
}

int main(void)
{
    std::cout << lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << lengthOfLongestSubstring("bbbbbb") << std::endl;
    std::cout << lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << lengthOfLongestSubstring("--") << std::endl;
    return 0;
}
