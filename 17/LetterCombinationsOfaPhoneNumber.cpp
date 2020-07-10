/*
 * =====================================================================================
 *
 *       Filename:  LetterCombinationsOfaPhoneNumber.cpp
 *
 *    Description: https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 
 *
 *        Version:  1.0
 *        Created:  10/07/2020 22:06:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> letterCombinations(std::string digits)
{
    if (!digits.size())
        return {};
    std::vector<std::vector<char>> letters = {{'a', 'b', 'c'}, {'d','e','f'}, {'g', 'h', 'i'},
        {'j', 'k', 'l'}, {'m', 'n', 'o'},  {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    std::vector<std::string> output = {""};
    for (auto& c : digits)
    {
        size_t cur_size = output.size();
        for (size_t i = 0; i < cur_size; ++i)
        {
            std::string cur_str = output[0];
            output.erase(output.begin());
            for (auto& possibility : letters[c - '2'])
            {
                output.push_back(cur_str + possibility);
            }
        }
    }
    return output;
}

int main(void)
{
    for (auto& str : letterCombinations("23"))
    {
        std::cout << str << " ";
    }
    letterCombinations("");
    return 0;
}
