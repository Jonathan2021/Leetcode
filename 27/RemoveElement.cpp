/*
 * =====================================================================================
 *
 *       Filename:  RemoveElement.cpp
 *
 *    Description: https://leetcode.com/problems/remove-element/ 
 *
 *        Version:  1.0
 *        Created:  07/23/20 11:30:04
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

int removeElement(std::vector<int>& nums, int val)
{
    int count = 0;
    for (auto it = nums.begin(); it != nums.end() - count;)
    {
        if (*it == val)
        {
            *it = *(nums.end() - ++count);
        }
        else
            ++it;
    }
    return nums.size() - count;
}

void printVector(std::vector<int>& vec)
{
    for (auto el : vec)
        std::cout << el << ", ";
}

int main(void)
{
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    std::cout << "New size : " << removeElement(nums, 2) << std::endl;
    printVector(nums);
    return 0;
}

