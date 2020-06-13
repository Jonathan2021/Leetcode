/*
 * =====================================================================================
 *
 *       Filename:  TwoSum.cpp
 *
 *    Description:  https://leetcode.com/problems/two-sum/
 *
 *        Version:  1.0
 *        Created:  13/06/2020 11:37:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
 *        Company:  none
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> res;
    for (long unsigned int i = 0; i < nums.size(); ++i)
    {
        for (long unsigned int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

void print(std::vector<int> const &input)
{
    for (auto const& i : input)
        std::cout << i << " "; 
}

int main(void)
{
    std::vector<int> nums = {2,7,11,15};
    std::vector<int> indices = twoSum(nums, 9);
    print(indices);
    return 0;
}
