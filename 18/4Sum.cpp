/*
 * =====================================================================================
 *
 *       Filename:  4Sum.cpp
 *
 *    Description: https://leetcode.com/problems/4sum/ 
 *
 *        Version:  1.0
 *        Created:  12/07/2020 16:45:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), jonathan.sands@edu.devinci.fr
 *        Company:  none
 *
 * =====================================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (i != 0 && nums[i] == nums[i-1])
            continue;
        for (size_t j = nums.size() - 1; j > i; --j)
        {
            if (j < nums.size() - 1 && nums[j] == nums[j + 1])
                continue;
            for (size_t k = i+1 , l = j - 1; k < l;)
            {
                if (k > i + 1 && nums[k - 1] == nums[k])
                {
                    k++;
                    continue;
                }
                if (l < j - 1 && nums[l] == nums[l + 1])
                {
                    l--;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum > target)
                    l--;
                else if (sum < target)
                    k++;
                else
                {
                    res.push_back({nums[i], nums[k++], nums[l--], nums[j]});
                }
            }
        }
    }
    return res;
}

int main(void)
{
    std::vector<int> nums = {1,0,-1,0,-2,2};
    for (auto& combo : fourSum(nums, 0))
    {
        std::cout << "[";
        for (auto number: combo)
        {
            std::cout << number << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
