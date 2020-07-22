/*
 * =====================================================================================
 *
 *       Filename:  RemoveDuplicatesFromSortedArray.cpp
 *
 *    Description: https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 
 *
 *        Version:  1.0
 *        Created:  07/22/20 16:29:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonathan Sands (js), misterjonathansands@gmail.com
 *        Company:  none
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>
#include <algorithm>

int removeDuplicates(std::vector<int>& nums)
{
    nums.erase(std::unique(nums.begin(),nums.end()), nums.end());
    return nums.size();
}

void printVector(std::vector<int>& vec)
{
    for (auto el : vec)
        std::cout << el << ", ";
}

int main(void)
{
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    std::cout << "New size : " << removeDuplicates(nums) << std::endl;
    printVector(nums);
    return 0;
}
