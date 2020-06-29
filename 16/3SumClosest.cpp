/*
 * =====================================================================================
 *
 *       Filename:  3SumClosest.cpp
 *
 *    Description: https://leetcode.com/problems/3sum-closest/ 
 *
 *        Version:  1.0
 *        Created:  06/29/20 20:21:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), misterjonathansands@gmail.com
 *        Company:  none
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int abs(int a)
{
    return (a < 0) ? a * -1 : a;
}

int threeSumClosest(std::vector<int>& nums, int target)
{
    std::stable_sort(nums.begin(), nums.end());
    int closest = std::numeric_limits<int>::max(); 
    int gap = std::numeric_limits<int>::max();
    for (size_t i = 0; i < nums.size() - 2; ++i)
    {
        if (i == 0 || nums[i - 1] != nums[i])
        {
            for (size_t j = i + 1, k = nums.size() - 1; j < k;)
            {
                if (j - 1 > i && nums[j-1] == nums[j])
                    ++j;
                else if (k + 1 < nums.size() && nums[k] == nums[k + 1])
                    k--;
                else
                {
                    int total = nums[i] + nums[j] + nums[k];
                    int cur_gap = total - target;
                    if (!cur_gap)
                        return total;
                    cur_gap = abs(cur_gap);
                    if (cur_gap < gap)
                    {
                        closest = total;
                        gap = cur_gap;
                    }
                    if (total > target)
                    {
                        int peek = nums[i] + nums[j] + nums[j + 1] - target;
                        if (j + 1 < k && peek > 0 && peek > gap)
                        {
                            break;
                        }
                        k--;
                    }
                    else
                    {
                        int peek = nums[i] + nums[k] + nums[k - 1] - target;
                        if (k - 1 > j && peek < 0 && -peek > gap)
                        {
                            break;
                        }
                        j++;
                    }
                }
            }
        }
    }
    return closest;
}

int main(void)
{
    std::vector<int> nums({-4,-1,1,2});
    std::cout << threeSumClosest(nums, 1) << std::endl;
    return 0;
}
