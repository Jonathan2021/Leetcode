/*
 * =====================================================================================
 *
 *       Filename:  LongestCommonPrefix.cpp
 *
 *    Description: https://leetcode.com/problems/longest-common-prefix/ 
 *
 *        Version:  1.0
 *        Created:  06/27/20 20:03:03
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
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    if (!strs.size())
        return "";
    std::string prefix = "";
    std::string next_prefix = "";
    for (size_t i = 0; i < strs[0].size(); ++i)
    {
        next_prefix += strs[0][i];
        if (std::all_of(strs.begin(), strs.end(), [&, next_prefix](std::string& str) -> bool {return (!str.find(next_prefix));}))
            prefix = next_prefix;
        else
            break;
    }
    return prefix;
}


int main(void)
{
    std::vector <std::string> words({"flower","flow","flight"});
    std::cout << longestCommonPrefix(words) << std::endl;
    words = {"dog", "racecar", "car"};
    std::cout << longestCommonPrefix(words) << std::endl;
    return 0;
}
