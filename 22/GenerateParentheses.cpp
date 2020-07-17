/*
 * =====================================================================================
 *
 *       Filename:  GenerateParentheses.cpp
 *
 *    Description: https://leetcode.com/problems/generate-parentheses/ 
 *
 *        Version:  1.0
 *        Created:  07/17/20 11:32:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), misterjonathansands@gmail.com
 *        Company:  none
 *
 * =====================================================================================
 */
#include <vector>
#include <string>
#include <iostream>

void generateParenthesis_rec(std::vector<std::string>& res, std::string current, int left_to_open, int unclosed)
{
    if (!left_to_open)
    {
        current += std::string(unclosed, ')');
        res.push_back(current);
    }
    else
    {
        if (unclosed)
        {
            generateParenthesis_rec(res, current + ')', left_to_open, unclosed - 1);
        }
        generateParenthesis_rec(res, current + '(', left_to_open - 1, unclosed + 1);
    }
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> res;
    generateParenthesis_rec(res, "", n, 0);
    return res;
}

int main(void)
{
    for (auto& comb : generateParenthesis(3))
        std::cout << comb << std::endl;
    return 0;
}
